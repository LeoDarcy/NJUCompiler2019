#include "assemblycode.h"
extern InterCodes* head;
void initReg()
{
	for(int i = 0; i < REG_SIZE; i++)
	{
		Regs[i].used = false;
		Regs[i].lastest_line_number = -1;
		Regs[i].varOperand = 0;
	}
	OperandInfor = createHashMap(60);
	regs_Current = 0;
	Line_Count = 0;
}
//fw传入的好处是可以当op第一次在汇编中出现时，需要补充lw来加载的一行才能使用，以及寄存器与栈交换的代码也需要在这里完成
char* get_reg(Operand op, FILE *fw)
{
	//只能使用t0-t9， s0-s8
    //TODO:实现找到对应的寄存器，在这里可以继续向文件中写入寄存器存取操作
	int key = (int)op;
	DataType result = getItemFromHashMap(OperandInfor, key);
	if(result.key == key)
	{
		//说明已经找到相关的
		switch (result.type)
		{
		case 0:{
			//没有保存的情况：理论上不存在
		};break;
		case 1:{//表示在寄存器中
			return CorresponseReg[result.reg_no];
		};break;
		case 2:{//只存在在offset中
			if(regs_Current >= REG_SIZE)//说明没有有空闲可用
			{

			}
			else
			{
				fprintf(fw,"lw %s, %d($sp)\n", CorresponseReg[regs_Current], result.offset);//加载到寄存器中
				//修正变量对应信息的值
				result.type = 3;
				result.reg_no = regs_Current;
				putHashMap(OperandInfor, result.key,result.offset, result.reg_no, result.type);
				//修正寄存器保存的值
				Regs[regs_Current].used = true;
				Regs[regs_Current].lastest_line_number = Line_Count;//记录行数
				Regs[regs_Current].varOperand = op;
				regs_Current++;
				return CorresponseReg[regs_Current-1];
			}
		}
		case 3:{
			return CorresponseReg[result.reg_no];
		}
		default:
			return "？？？Wrong in get_reg";
		}
	}
	else
	{
		if(regs_Current >= REG_SIZE)//说明没有有空闲可用
		{
			//TODO:实现内存切换
		}
		else
		{
			//加载到寄存器中
			//修正变量对应信息的值
			result.key = key;
			result.type = 1;
			result.reg_no = regs_Current;
			putHashMap(OperandInfor, result.key,result.offset, result.reg_no, result.type);
			//修正寄存器保存的值
			Regs[regs_Current].used = true;
			Regs[regs_Current].lastest_line_number = Line_Count;//记录行数
			Regs[regs_Current].varOperand = op;
			regs_Current++;
			return CorresponseReg[regs_Current-1];
		}
		
	}
	
    char* str = (char*)malloc(30);
	strcpy(str, "no init in get_reg");
    return str;
}
void printAssemblyCodes(FILE *fw)
{
	InterCodes* tmp = head;
	while(tmp != NULL)
	{
		//printf("\nline code\n");
		Line_Count++;
		InterCode code = tmp->code;
		switch (code.kind)
		{
		case DEC:{//DEC 变量 变量大小 //开辟空间在栈区
            //TODO:等待补全
			//Finish：什么也不做就行
            //fprintf(fw,"DEC %s %d\n", trans(code.u.dec.op), code.u.dec.size);
            };break;
		case CLABEL:{
            fprintf(fw,"%s:\n", trans(code.u.single.op));};break;
		case FUNCTION:{//Function function_name
            fprintf(fw,"%s:\n",trans(code.u.single.op));};break;
		case GOTO:{
            fprintf(fw,"j %s\n",trans(code.u.single.op));};break;
		case RETURN:{//return x
            //：将op的值放入$v0，然后jr $ra
            fprintf(fw,"move $v0,  %s\n",get_reg(code.u.single.op, fw));
            fprintf(fw,"jr $ra\n");};break;
		case ARG:{
			fprintf(fw,"ARG %s\n",trans(code.u.single.op));};break;
		case PARAM:{
			//直接跳过
			//fprintf(fw,"PARAM %s\n",trans(code.u.single.op));
			};break;
		case READ:{
			//这里只考虑了v0（本来存返回值的寄存器）未被使用
			fprintf(fw,"addi $sp, $sp, -4\n");
			fprintf(fw,"sw $ra, 0($sp)\n");
			fprintf(fw,"jal read\n");
			fprintf(fw,"lw $ra, 0($sp)\n");
			fprintf(fw,"addi $sp, $sp, 4\n");
			fprintf(fw,"move %s, $v0\n", get_reg(code.u.single.op, fw));//把v0更新到原来的寄存器中
			//fprintf(fw,"READ %s\n",trans(code.u.single.op));
			};break;
		case WRITE:{
			fprintf(fw,"move $a0, %s\n",get_reg(code.u.single.op, fw));//保存参数
			fprintf(fw,"addi $sp, $sp, -4\n");
			fprintf(fw,"sw $ra, 0($sp)\n");
			fprintf(fw,"jal write\n");
			fprintf(fw,"lw $ra, 0($sp)\n");
			fprintf(fw,"addi $sp, $sp, 4\n");
			
			//fprintf(fw,"WRITE %s\n",trans(code.u.single.op));
			};break;
		case ASSIGN:{
			
			fprintf(fw,"%s := %s\n",trans(code.u.assign.left), trans(code.u.assign.right));};break;
		case CALL:{
			//适用于没有参数的情况，有参数的情况交给arg那部分解决
			fprintf(fw,"addi $sp, $sp, -4\n");
			fprintf(fw,"sw $ra, 0($sp)\n");
			fprintf(fw,"jal %s\n", trans(code.u.assign.right));
			fprintf(fw,"lw $ra, 0($sp)\n");
			fprintf(fw,"addi $sp, $sp, 4\n");
			fprintf(fw,"move %s, $v0\n", get_reg(code.u.assign.left, fw));//把v0更新到原来的寄存器中
			};break;
		case ADD:{
			//分类考虑出现常数的情况，这时用addi
			if(code.u.assign.left->kind == CONST || code.u.assign.right->kind == CONST)
			{
				fprintf(fw,"addi %s, %s, %s\n", get_reg(code.u.binop.result,fw), get_reg(code.u.binop.op1,fw), get_reg(code.u.binop.op2, fw));
			}
			else
				fprintf(fw,"add %s, %s, %s\n", get_reg(code.u.binop.result,fw), get_reg(code.u.binop.op1,fw), get_reg(code.u.binop.op2, fw));
			//fprintf(fw,"%s := %s + %s\n",trans(code.u.binop.result),trans(code.u.binop.op1), trans(code.u.binop.op2));
			};break;
		case SUB:{
			fprintf(fw,"sub %s, %s, %s\n", get_reg(code.u.binop.result,fw), get_reg(code.u.binop.op1,fw), get_reg(code.u.binop.op2, fw));
			};break;
		case MUL:{
			fprintf(fw,"mul %s, %s, %s\n", get_reg(code.u.binop.result,fw), get_reg(code.u.binop.op1,fw), get_reg(code.u.binop.op2, fw));
			};break;
		case DIV:{
			fprintf(fw,"div %s, %s\n",get_reg(code.u.binop.op1,fw), get_reg(code.u.binop.op2, fw));
			fprintf(fw,"mflo %s\n", get_reg(code.u.binop.result,fw));
			};break;
		case IFGOTO:{fprintf(fw,"IF %s %s %s GOTO %s\n",trans(code.u.triop.op1),code.u.triop.relop,trans(code.u.triop.op2),trans(code.u.triop.label));};break;
		case getaddr:{fprintf(fw,"%s = &%s\n", trans(code.u.assign.left), trans(code.u.assign.right));};break;
		case getpointer:{fprintf(fw,"%s = *%s\n", trans(code.u.assign.left), trans(code.u.assign.right));};break;//16, 17,represent result=&op1, result=*op1
		case pointto:{fprintf(fw,"*%s = %s\n", trans(code.u.assign.left), trans(code.u.assign.right));};break;
		
		default:
			break;
		}
		tmp = tmp->next;
	}
}


#include "assemblycode.h"
extern InterCodes* head;
VarDescriptor* OperandInfor[tsize];
char* CorresponseReg(int reg_no)
{
	char*result = (char*)malloc(10);
	strcpy(result, "$t0");
	if(reg_no < 0)
	{
		strcpy(result, "???Wrong in reg_no");
	}
	else if(reg_no < 10)
	{
		result[2] = result[2] + reg_no;
	}
	else if(reg_no < 19)
	{
		result[1] = 's';
		result[2] = result[2] + (reg_no-10);
	}
	else if(reg_no < REG_SIZE)
	{
		result[1] = 'a';
		result[2] = result[2] + (reg_no-19);
	}
	else
	{
		strcpy(result, "???Wrong in reg_no>reg_size");
	}
	return result;
}
void initReg()
{
	for(int i = 0; i < REG_SIZE; i++)
	{
		Regs[i].used = false;
		Regs[i].lastest_line_number = -1;
		Regs[i].varOperand = 0;
	}
	for(int i=0; i<tsize; i++)
	{
		OperandInfor[i] = NULL;
	}
	regs_Current = 0;
	Line_Count = 0;
}

//加入或者更新,注意item里面的key必须是新建的（保证正确）
bool putVarDescriptor(VarDescriptor* item)
{
	if(item == NULL) return;
	unsigned int key = pjwhash(item->key);
	VarDescriptor* queue = OperandInfor[key];
	if(queue == NULL)
	{
		item->next = NULL;
	}
	else
	{
		//先找是不是已经存在在表里
		VarDescriptor* beginlook = queue;
		while(beginlook != NULL)
		{
			if(strcmp(beginlook->key,item->key) == 0)
			{
				//找到并更新
				beginlook->offset = item->offset;
				beginlook->reg_no = item->reg_no;
				beginlook->type = item->type;
				return true;
			}
			beginlook = beginlook->next;
		}
	}
	//加入到开头
	item->next = queue;
	OperandInfor[key] = item;
}
//返回找到的
VarDescriptor* getItemFromVarDescriptor(char* keychar)
{
	unsigned int key = pjwhash(keychar);
	VarDescriptor* queue = OperandInfor[key];
	if(queue == NULL)
	{
		return NULL;
	}
	else
	{
		//先找是不是已经存在在表里
		VarDescriptor* beginlook = queue;
		while(beginlook != NULL)
		{
			if(strcmp(beginlook->key,keychar) == 0)
			{
				//找到并返回
				return beginlook;
			}
			beginlook = beginlook->next;
		}
	}
	return NULL;
}


//fw传入的好处是可以当op第一次在汇编中出现时，需要补充lw来加载的一行才能使用，以及寄存器与栈交换的代码也需要在这里完成
char* get_reg(Operand op, FILE *fw)
{
	//只能使用t0-t9， s0-s8
    //TODO:实现找到对应的寄存器，在这里可以继续向文件中写入寄存器存取操作
	VarDescriptor* result = getItemFromVarDescriptor(trans(op));
	//printf("find %s\n", trans(op));
	if(result != NULL)
	{
		//printf("  inside and type :%d \n", result->type);
		//说明已经找到相关的
		switch (result->type)
		{
		case 0:{
			//没有保存的情况：理论上不存在
		};break;
		case 1:{//表示在寄存器中
			return CorresponseReg(result->reg_no);
		};break;
		case 2:{//只存在在offset中
			if(regs_Current >= REG_SIZE)//说明没有有空闲可用
			{

			}
			else
			{
				fprintf(fw,"lw %s, %d($sp)\n", CorresponseReg(regs_Current), result->offset);//加载到寄存器中
				//修正变量对应信息的值
				result->type = 3;
				result->reg_no = regs_Current;
				//理论上不需要put，因为指针直接修改了
				//putVarDescriptor(OperandInfor, result.key,result.offset, result.reg_no, result.type);
				//修正寄存器保存的值
				Regs[regs_Current].used = true;
				Regs[regs_Current].lastest_line_number = Line_Count;//记录行数
				Regs[regs_Current].varOperand = op;
				regs_Current++;
				return CorresponseReg(regs_Current-1);
			}
		}
		case 3:{
			return CorresponseReg(result->reg_no);
		}
		default:
			return "？？？Wrong in get_reg";
		}
	}
	else
	{
		//printf(" No in \n");
		if(regs_Current >= REG_SIZE)//说明没有有空闲可用
		{
			//TODO:实现内存切换
		}
		else
		{
			//加载到寄存器中
			//修正变量对应信息的值
			result = (VarDescriptor*)malloc(sizeof(VarDescriptor));
			result->key = trans(op);
			result->type = 1;
			result->reg_no = regs_Current;
			result->offset = 0;
			putVarDescriptor(result);
			//修正寄存器保存的值
			Regs[regs_Current].used = true;
			Regs[regs_Current].lastest_line_number = Line_Count;//记录行数
			Regs[regs_Current].varOperand = op;
			regs_Current++;
			return CorresponseReg(regs_Current-1);
		}
		
	}
	
    char* str = (char*)malloc(30);
	strcpy(str, "no init in get_reg");
    return str;
}
void printAssemblyCodes(FILE *fw)
{
	fprintf(fw, ".data\n");
	fprintf(fw, "_prompt: .asciiz \"Enter an integer:\"\n");
	fprintf(fw, "_ret: .asciiz \"\\n\" \n");
	fprintf(fw, ".globl main\n");
	fprintf(fw, ".text\n");
	fprintf(fw, "read:\n");
	fprintf(fw, "li $v0, 4\n");
	fprintf(fw, "la $a0, _prompt\n");
	fprintf(fw, "syscall \n li $v0, 5 \n syscall \n jr $ra \n");
	fprintf(fw,"write:\n li $v0, 1 \n syscall \n li $v0, 4 \n la $a0, _ret \n syscall \n move $v0, $0 \n jr $ra\n");
	InterCodes* tmp = head;
	while(tmp != NULL)
	{
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
			//fprintf(fw,"%s := %s\n",trans(code.u.assign.left), trans(code.u.assign.right));
			if(code.u.assign.right->kind == CONST)
			{
				fprintf(fw, "li %s, %s\n", get_reg(code.u.assign.left, fw), code.u.assign.right->u.val);
			}
			else if(code.u.assign.left->kind == VAR && code.u.assign.right->kind == VAR)
			{
				fprintf(fw, "move %s, %s\n", get_reg(code.u.assign.left, fw), get_reg(code.u.assign.right, fw));
			}
			else if(code.u.assign.left->kind == VAR && code.u.assign.right->kind == TEMPVAR)
			{
				fprintf(fw, "move %s, %s\n", get_reg(code.u.assign.left, fw), get_reg(code.u.assign.right, fw));
			}
			else if(code.u.assign.left->kind == TEMPVAR && code.u.assign.right->kind == VAR)
			{
				fprintf(fw, "move %s, %s\n", get_reg(code.u.assign.left, fw), get_reg(code.u.assign.right, fw));
			}
			else if(code.u.assign.left->kind == TEMPVAR && code.u.assign.right->kind == TEMPVAR)
			{
				fprintf(fw, "move %s, %s\n", get_reg(code.u.assign.left, fw), get_reg(code.u.assign.right, fw));
			}
			else
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


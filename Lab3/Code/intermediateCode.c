#include"symboltable.h"
#include "intermediateCode.h"

InterCodes *head=NULL, *tail=NULL;

void insertInterCode(InterCodes *code)
{
	if(code==NULL) return;
	if(tail==NULL)
	{
		head=tail=code;
	}
	else
	{
		tail->next=code;
		code->prev=tail;
		tail=code;
	}
}

void deleteInterCode(InterCodes *code)
{
	if(code==NULL || head==NULL) return;
	if(code==head && code==tail)
	{
		head=tail=NULL;
	}
	else if(code==head)
	{
		head=head->next;
		head->prev=NULL;
	}
	else
	{
		InterCodes *p = code->prev;
		p->next=code->next;
		if(code->next!=NULL)
			code->next->prev=p;
	}
	free(code);
}

void deleteInterCodes()
{
	while(head!=NULL)
	{
		InterCodes *p = head;
		head=head->next;
		free(p);
	}
}

Operand newLabel(int no)
{
	Operand label=(Operand)malloc(sizeof(struct Operand_));
	label->kind=LABEL;
	label->u.no=no;
	return label;
}

Operand newTemp(int no)
{
	Operand temp=(Operand)malloc(sizeof(struct Operand_));
	temp->kind=TEMPVAR;
	temp->u.no=no;
	return temp;
}

int computeSize(Type type)
{
	if(type->kind==BASIC) 
		return 4;
	else if(type->kind==ARRAY)
		return type->u.array.size * computeSize(type->u.array.elem);
	else if(type->kind==STRUCTURE)
	{
		int size=0;
		FieldList field=type->u.structure;
		while(field)
		{
			size+=computeSize(field->type);
			field=field->tail;
		}
		return size;
	}
	return 0;
}


void insertFuncName(char* funcName)
{
	Operand func = (Operand)malloc(sizeof(Operand_));
	func->kind = FUNC;
	func->u.val=funcName;
	InterCodes *Code = (InterCodes*)malloc(sizeof(InterCodes));
	Code->prev=Code->next=NULL;
	Code->code.kind=FUNCTION;
	Code->code.u.single.op=func;
	insertInterCode(Code);
}

void insertFuncParam(char* paramName)
{
	Operand param = (Operand)malloc(sizeof(Operand_));
	param->kind = VAR;
	param->u.val=paramName;
	InterCodes *Code = (InterCodes*)malloc(sizeof(InterCodes));
	Code->prev=Code->next=NULL;
	Code->code.kind=PARAM;
	Code->code.u.single.op=param;
	insertInterCode(Code);
}

void insertFields(char* name,int size)//for array and structure
{
	Operand op = (Operand)malloc(sizeof(Operand_));
	op->kind = VAR;
	op->u.val=name;
	InterCodes *Code = (InterCodes*)malloc(sizeof(InterCodes));
	Code->prev=Code->next=NULL;
	Code->code.kind=DEC;
	Code->code.u.dec.op=op;
	Code->code.u.dec.size=size;
	insertInterCode(Code);
}

void insertReturn(Operand op)
{
	InterCodes *Code = (InterCodes*)malloc(sizeof(InterCodes));
	Code->prev=Code->next=NULL;
	Code->code.kind=RETURN;
	Code->code.u.single.op=op;
	insertInterCode(Code);
}

void insertAssignLID(char *leftName, Operand right)
{
	Operand left = (Operand)malloc(sizeof(Operand_));
	left->kind=VAR;
	left->u.val=leftName;
	InterCodes *Code = (InterCodes*)malloc(sizeof(InterCodes));
	Code->prev=Code->next=NULL;
	Code->code.kind=ASSIGN;
	Code->code.u.assign.left=left;
	Code->code.u.assign.right=right;
	insertInterCode(Code);
}

void insertAssignLOP(Operand left, Operand right)
{
	InterCodes *Code = (InterCodes*)malloc(sizeof(InterCodes));
	Code->prev=Code->next=NULL;
	Code->code.kind=ASSIGN;
	Code->code.u.assign.left=left;
	Code->code.u.assign.right=right;
	insertInterCode(Code);
}

void insertGotoLabelTrue(Operand op1, Operand op2, Operand labelTrue, char relop[])
{
	InterCodes *Code = (InterCodes*)malloc(sizeof(InterCodes));
	Code->prev=Code->next=NULL;
	Code->code.kind=IFGOTO;
	Code->code.u.triop.op1=op1;
	Code->code.u.triop.op2=op2;
	Code->code.u.triop.label=labelTrue;
	strcpy(Code->code.u.triop.relop, relop);
	insertInterCode(Code);
}

void insertGotoLabel(Operand label)
{
	InterCodes *Code = (InterCodes*)malloc(sizeof(InterCodes));
	Code->prev=Code->next=NULL;
	Code->code.kind=GOTO;
	Code->code.u.single.op=label;
	insertInterCode(Code);
}

void insertLabel(Operand label)
{
	InterCodes *Code = (InterCodes*)malloc(sizeof(InterCodes));
	Code->prev=Code->next=NULL;
	Code->code.kind=CLABEL;
	Code->code.u.single.op=label;
	insertInterCode(Code);
}

void insertBinop(Operand result, Operand op1, Operand op2, int kind)
{
	InterCodes *Code = (InterCodes*)malloc(sizeof(InterCodes));
	Code->prev=Code->next=NULL;
	Code->code.kind=kind;//
	Code->code.u.binop.result=result;
	Code->code.u.binop.op1=op1;
	Code->code.u.binop.op2=op2;
	insertInterCode(Code);
}

void insertReadfunc(Operand place)
{
	InterCodes *Code = (InterCodes*)malloc(sizeof(InterCodes));
	Code->prev=Code->next=NULL;
	Code->code.kind=READ;//
	Code->code.u.single.op=place;
	if(place)
		insertInterCode(Code);
}

void insertCall(Operand place, char* funcName)
{
	Operand func = (Operand)malloc(sizeof(Operand_));
	func->kind = FUNC;
	func->u.val=funcName;
	InterCodes *Code = (InterCodes*)malloc(sizeof(InterCodes));
	Code->prev=Code->next=NULL;
	Code->code.kind=CALL;
	Code->code.u.assign.left=place;//NULL时输出需要额外处理
	Code->code.u.assign.right=func;
	insertInterCode(Code);
}

void insertWritefunc(Operand op)
{
	InterCodes *Code = (InterCodes*)malloc(sizeof(InterCodes));
	Code->prev=Code->next=NULL;
	Code->code.kind=WRITE;//
	Code->code.u.single.op=op;
	insertInterCode(Code);
}

void insertFuncArgs(Operand arg)
{
	InterCodes *Code = (InterCodes*)malloc(sizeof(InterCodes));
	Code->prev=Code->next=NULL;
	Code->code.kind=ARG;
	Code->code.u.single.op=arg;
	insertInterCode(Code);
}

void insertGetAddrOrPointer(Operand result, Operand op1, int kind)
{
	InterCodes *Code = (InterCodes*)malloc(sizeof(InterCodes));
	Code->prev=Code->next=NULL;
	Code->code.kind=kind;//
	Code->code.u.assign.left=result;
	Code->code.u.assign.right=op1;
	insertInterCode(Code);
}

char* trans(Operand op)
{
	switch (op->kind)
	{
		case 0:{return op->u.val;};break;
		case 1:{char* result=malloc(30);
				strcpy(result, "#");
				strcat(result, op->u.val);
				return result;};break;
		case 2:
		case 3:{char* result=malloc(30);
				strcpy(result, "myvar");
				char* buffer = malloc(sizeof(char) * 30);
				sprintf(buffer,"%d",op->u.no);
				strcat(result, buffer);
				return result;};break;
		case 4:{char* result=malloc(30);
				strcpy(result, "mylabel");
				char* buffer = malloc(sizeof(char) * 30);
				sprintf(buffer,"%d",op->u.no);
				strcat(result, buffer);
				//printf("\n\n%s\n\n\n", result);
				return result;};break;
		case 5:{return op->u.val;};break;
		case 6:{char* result=malloc(30);
				strcpy(result, "*myvar");
				char* buffer = malloc(sizeof(char) * 30);
				sprintf(buffer,"%d",op->u.no);
				strcat(result, buffer);
				return result;};break;//ADDR加上*
		case 7:{char* result=malloc(30);
				strcpy(result, "&");
				strcat(result, op->u.val);
				return result;};break;//加上&
		case 8:{return op->u.val;};break;
	default:
		break;
	}
}

void printInterCodes()
{
	InterCodes* tmp = head;
	while(tmp != NULL)
	{
		//printf("\nline code\n");
		InterCode code = tmp->code;
		switch (code.kind)
		{
		case DEC:{printf("DEC %s %d\n", trans(code.u.dec.op), code.u.dec.size);};break;
		case CLABEL:{printf("LABEL %s :\n", trans(code.u.single.op));};break;
		case FUNCTION:{printf("FUNCTION %s :\n",trans(code.u.single.op));};break;
		case GOTO:{printf("GOTO %s\n",trans(code.u.single.op));};break;
		case RETURN:{printf("RETURN %s\n",trans(code.u.single.op));};break;
		case ARG:{printf("ARG %s\n",trans(code.u.single.op));};break;
		case PARAM:{printf("PARAM %s\n",trans(code.u.single.op));};break;
		case READ:{printf("READ %s\n",trans(code.u.single.op));};break;
		case WRITE:{printf("WRITE %s\n",trans(code.u.single.op));};break;
		case ASSIGN:{if(code.u.assign.left == NULL || code.u.assign.right ==NULL)printf("now begin\n\n");
			//printf("kind=%d, kind=%d\n", code.u.assign.left->kind, code.u.assign.right->kind);
			printf("%s := %s\n",trans(code.u.assign.left), trans(code.u.assign.right));};break;
		case CALL:{printf("%s := CALL %s\n",trans(code.u.assign.left), trans(code.u.assign.right));};break;
		case ADD:{printf("%s := %s + %s\n",trans(code.u.binop.result),trans(code.u.binop.op1), trans(code.u.binop.op2));};break;
		case SUB:{printf("%s := %s - %s\n",trans(code.u.binop.result),trans(code.u.binop.op1), trans(code.u.binop.op2));};break;
		case MUL:{printf("%s := %s * %s\n",trans(code.u.binop.result),trans(code.u.binop.op1), trans(code.u.binop.op2));};break;
		case DIV:{printf("%s := %s / %s\n",trans(code.u.binop.result),trans(code.u.binop.op1), trans(code.u.binop.op2));};break;
		case IFGOTO:{printf("IF %s %s %s GOTO %s\n",trans(code.u.triop.op1),code.u.triop.relop,trans(code.u.triop.op2),trans(code.u.triop.label));};break;
		case getaddr:{printf("%s = &%s\n", trans(code.u.assign.left), trans(code.u.assign.right));};break;
		case getpointer:{printf("%s = *%s\n", trans(code.u.assign.left), trans(code.u.assign.right));};break;//16, 17,represent result=&op1, result=*op1
		case pointto:{printf("*%s = %s\n", trans(code.u.assign.left), trans(code.u.assign.right));};break;
		
		default:
			break;
		}
		tmp = tmp->next;
	}
}


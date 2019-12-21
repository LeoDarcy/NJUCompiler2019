#ifndef ASSEMBLYCODE_H
#define ASSEMBLYCODE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
//#include "hashmap.h"
#include"intermediateCode.h"
#include "const.h"
typedef struct VarDescriptor{
	char* key;  //变量名
	int offset;  //内存中的值
    int reg_no; //在reg中的编号
    int type; // type = 0 表示未使用，type = 1表示reg_no可以用， type = 2 表示offset和reg_no可以用
    struct VarDescriptor* next;
}VarDescriptor; 
extern VarDescriptor* OperandInfor[tsize];
//加入或者更新
bool putVarDescriptor(VarDescriptor* item);
//返回找到的
VarDescriptor* getItemFromVarDescriptor(char* keychar);

//HashMap* OperandInfor;
typedef struct RegDescriptor
{
    bool used;
    int lastest_line_number;
    Operand varOperand;
}RegDescriptor;

RegDescriptor Regs[REG_SIZE];
int regs_Current;//表示已经在使用的有多少个
int Line_Count;

void initReg();
void printAssemblyCodes(FILE *fw);
#endif
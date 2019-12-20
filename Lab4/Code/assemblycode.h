#ifndef ASSEMBLYCODE_H
#define ASSEMBLYCODE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include "hashmap.h"
#include"intermediateCode.h"
#include "const.h"
typedef struct RegDescriptor
{
    bool used;
    int lastest_line_number;
    Operand varOperand;
}RegDescriptor;

RegDescriptor Regs[REG_SIZE];
int regs_Current;//表示已经在使用的有多少个
int Line_Count;
HashMap* OperandInfor;
void initReg();
void printAssemblyCodes(FILE *fw);
#endif ASSEMBLYCODE_H
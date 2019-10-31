#ifndef SYMBOLTABLE_H
#define STMBOLTABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef struct Type_* Type;
typedef struct FieldList_* FieldList;

struct VarObject
{
	char* name;
	Type type;
}
struct FuncObject
{
	char* name;
	Type rtype;
	vector* args;
}
struct Type_
{
	enum { BASIC, ARRAY, STRUCTURE } kind;
	union
	{
		// BASIC
		int basic;	// 0-int, 1-float
		// ARRAY
		struct { Type elem; int size; } array;
		// STRUCTURE
		FieldList structure; 
	} u;
	/*union
	{
		int intvalue;
		int floatvalue;
		int* intarray;
		float* floatarray;
	}value;*/
};

struct FieldList_
{
	char *name;	// name of the field
	Type type;	// type of the field
	FieldList tail;	// next field
};

typedef struct ValHashTable
{
	int depth;
	char *name;	// char name[33];
	Type type;	// variable-type (pointer-level 1)
	// for linking
	struct ValHashTable *indexNext;	// same index after hashing
	struct ValHashTable *fieldNext;	// same field in the syntax tree
} ValHashTable;

typedef struct FuncHashTable
{
	char *name;	// char name[33];
	Type rtype;	// function-return type (pointer-level 1)
	// for parameter
	int num;	// number of function parameters
	Type *vtype;	// types of parameters (pointer-level 2); name doesn't matter
	// for linking
	struct FuncHashTable *indexNext;	// same index after hashing
} FuncHashTable;

#define tsize 16384

ValHashTable* vtable[tsize];
FuncHashTable* ftable[tsize];

void initHashTable();

void freeHashTable();

void AddToValHashTable(Val* item);

void AddToFuncHashTable(Func* item);

bool CheckInValHashTable(char* name);

bool CheckInFuncHashTable(char* name);

unsigned int pjwhash(char *name);
//namespace
typedef struct NameFieldStruct NameFieldStruct;
typedef struct NameFieldStruct 
{
	int deep;
	int size;
	ValHashTable*items;
	NameFieldStruct* nextField;
}namesfield;

//这里负责有关命名空间的处理。
//作用域
NameFieldStruct* NameSpace;
//初始化
void initNameSpace();
//展开新的作用域
void CreateNewSpace();
//和加入符号表结合使用
void AddToNameSpace(ValHashTable* item);
//将语句块中的变量名全部去掉
void FreeThisNameSpace();
#endif
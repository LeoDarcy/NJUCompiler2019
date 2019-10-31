#ifndef SYMBOLTABLE_H
#define STMBOLTABLE_H
#include "vectorList.h"
#include "mydebug.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Type_* Type;
typedef struct FieldList_* FieldList;
typedef struct VarObject VarObject;
typedef struct FuncObject FuncObject;
struct VarObject
{
	char* name;// char name[33];
	Type type;	// variable-type (pointer-level 1)
};
struct FuncObject
{
	char* name;
	Type rtype;
	vector* args;
};

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
	VarObject varobject;
	// for linking
	struct ValHashTable *indexNext;	// same index after hashing
	struct ValHashTable *fieldNext;	// same field in the syntax tree
} ValHashTable;

typedef struct FuncHashTable
{
	FuncObject funcobject;
	// for linking
	struct FuncHashTable *indexNext;	// same index after hashing
} FuncHashTable;

#define tsize 16384

ValHashTable* vtable[tsize];
FuncHashTable* ftable[tsize];

void initHashTable();

void freeHashTable();

void AddToValHashTable(VarObject* item);

void AddToFuncHashTable(FuncObject* item);

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
	NameFieldStruct* next;
}namesfield;

//这里负责有关命名空间的处理。
//作用域
NameFieldStruct* NameSpace;
unsigned int CurrentDept;
//初始化
void initNameSpace();
//展开新的作用域
void CreateNewSpace();
//和加入符号表结合使用
void AddToNameSpace(ValHashTable* item);
//将语句块中的变量名全部去掉
void FreeThisNameSpace();



//Tool工具，不重要可不看
void ToolDeleteValHashTable(ValHashTable* item);
void ToolFreeValHashTable(ValHashTable*item);
void ToolFreeType(Type type);
void ToolFreeFieldList(FieldList flist);
void ToolFreeVarObject(VarObject* item);
#endif
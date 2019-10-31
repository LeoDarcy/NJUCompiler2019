#include"symboltable.h"

void initSymbolTable()
{
	initHashTable();
	initNameSpace();
}

void initHashTable()
{
	for(int i=0; i<tsize; i++)
	{
		vtable[i] = NULL;
		ftable[i] = NULL;
	}
}

void freeHashTable()
{
	for(int i=0; i<tsize; i++)
	{
		while(vtable[i] != NULL)
		{
			ValHashTable* cur=vtable[i];
			vtable[i]=vtable[i]->indexNext;
			free(cur);
		}
		while(ftable[i] != NULL)
		{
			FuncHashTable* cur=ftable[i];
			ftable[i]=ftable[i]->indexNext;
			free(cur);
		}
	}
}

unsigned int pjwhash(char *name)
{
	unsigned int val=0, i;
	for(; *name; ++name)
	{
		val = (val<<2) + *name;
		if(i = val & ~0x3fff)
			val = (val ^ (i>>12)) & 0x3fff;
	}
	return val;
}

void initNameSpace()
{
	NameSpace = (NameFieldStruct*)malloc(sizeof(NameFieldStruct));
	NameSpace->deep = 0;
	NameSpace->size = 0;
	NameSpace->items = NULL;
	NameSpace->nextField = NULL;
}
void AddToNameSpace(ValHashTable* item)
{
	if(item == NULL) return;
	NameSpace->size++;
	NameSpace->items
}

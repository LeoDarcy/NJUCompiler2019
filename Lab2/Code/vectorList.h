#ifndef VECTORLIST_H
#define VECTORLIST_H
#include "symboltable.h"
#include <malloc.h>
typedef struct vector
{
    //int size;//表示记录的个数
    int index;
    Val* var;
    val* last;
    vector* next;
}vector;


//建议使用接口，不要自己访问里面的成员
vector* CreateVector();
void FreeVector(vector* vt);
void GetFirstItem(vector* vt){return vt->first;}
void GetLastItem(vector* vt){return vt->last;}

void AddItem(vector* vt, ValHashTable* item);

ValHashTable* GetItemByIndex(vector* vt, int index);

bool RemoveItemByIndex(vector* vt, int index);



#endif
#ifndef VECTORLIST_H
#define VECTORLIST_H
#include "symboltable.h"
#include <malloc.h>
typedef struct vector vector;
/*extern struct VarObject;
extern struct FuncObject;
extern struct Type_;
extern struct FieldList_;
extern struct ValHashTable;
*/

struct vector
{
    //int size;//表示记录的个数
    int index;
    VarObject* var;
    VarObject* last;
    struct vector * next;
};


//建议使用接口，不要自己访问里面的成员
vector* CreateVector();
void FreeVector(vector* vt);
void GetFirstItem(vector* vt){if(vt->index > 0) return vt->var;else return NULL;}
//void GetLastItem(vector* vt){return vt->last;}

void AddItem(vector* vt, VarObject* item);

VarObject* GetItemByIndex(vector* vt, int index);

bool RemoveItemByIndex(vector* vt, int index);



#endif
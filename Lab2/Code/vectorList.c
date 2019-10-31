#include "vectorList.h"
#include <malloc.h>

vector* CreateVector()
{
    vector* p = (vector*)malloc(sizeof(vector));
    p->first = NULL;
    p->last = NULL;
    p->size = 0;
    return p;
}

void FreeVector(vector* vt)
{
    ValHashTable* head = vt->first;
    vt->first = NULL;
    vt->last = NULL;
    while(head != NULL)
    {
        ValHashTable* tmp = head;
        head = head->indexNext;
        free(tmp);
    }
    free(vt);
}
void AddItem(vector* vt, ValHashTable* item)
{
    if(vt == NULL || item == NULL) return;
    if(vt->size == 0)
    {
        vt->first = item;
        vt->last = item;
    }
    else
    {
        vt->last->indexNext = item;
        item->indexNext = NULL;
        vt->last = item;
    }
    vt->size++;
}

ValHashTable* GetItemByIndex(vector* vt, int index)
{
    if(vt == NULL || index < 0 || index >= vt->size) return NULL;
    ValHashTable* p = vt->first;
    for(int i = 0; i < index; i++)
    {
        p = p->indexNext;
    }
    return p;
}

bool RemoveItemByIndex(vector* vt, int index)
{
    if(vt == NULL || index < 0 || index >= vt->size) return false;
    ValHashTable* p = vt->first;
    if(0 == index)
    {
        ValHashTable* p = vt->first;
        vt->first = p->indexNext;
        if(vt->size == 1)
            vt->last = NULL;
        free(p);
    }
    else
    {
        ValHashTable* before = vt->first;
        ValHashTable* current = before->indexNext;
        for(int i = 1; i < index; i++)
        {
            before = before->indexNext;
            current = current->indexNext;
        }
        before->indexNext = current->indexNext;
        if(vt->last == current)
        {
            vt->last = before;
        }
        free(p);
    }
    vt->size--;
    return true;
}
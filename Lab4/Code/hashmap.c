#include "hashmap.h"
int getIndexFromKey(int key, int size)
{
    return abs(key) % size;
}
HashMap* createHashMap(int size)
{
    //分配内存空间
	HashMap *hashmap = (HashMap*)malloc(sizeof(HashMap));
	hashmap->size = size;
	//hash表分配空间
	hashmap->table=(HashNode *)malloc(sizeof(HashNode)*hashmap->size*4);
	//初始化
	int j = 0;
	for(j = 0; j < hashmap->size; j++){
		hashmap->table[j].data.key=INT_MIN;
		hashmap->table[j].next=NULL;
	}
	//处理完成，返回HashMap
	return hashmap;

}
bool putHashMap(HashMap* hashmap, int key, int offset, int reg_no, int type)
{
    DataType insert;
    insert.key = key;
    insert.offset = offset;
    insert.reg_no = reg_no;
    insert.type = type;
    int index = getIndexFromKey(key, hashmap->size);
    HashNode* pointer = &(hashmap->table[index]);
    if(pointer->data.key == INT_MIN)
    {
        if(pointer->next == NULL)
        {
            pointer->data = insert;
            return true;
        }
        //说明存在一个点是key=INT——MIN
    }
    while(pointer->next != NULL)
    {
        if(pointer->data.key == key)
        {
            pointer->data = insert;
            return true;
        }
        pointer = pointer->next;
    }
    if(pointer->data.key == key)
    {
        pointer->data = insert;
        return true;
    }
    HashNode* insertNode = (HashNode*)malloc(sizeof(HashNode));
    insertNode->data = insert;
    insertNode->next = NULL;
    pointer->next = insertNode;
    return true;
    
}
DataType getItemFromHashMap(HashMap* hashmap, int key)
{
    DataType result;
    result.key = key + 1;
    result.offset = 0;
    result.reg_no = -1;
    result.type = -1;
    int index = getIndexFromKey(key, hashmap->size);
    HashNode* pointer = &(hashmap->table[index]);
    while(pointer != NULL)
    {
        if(pointer->data.key == key)
        {
            result.key = key;
            result.offset = pointer->data.offset;
            result.reg_no = pointer->data.reg_no;
            result = pointer->data;
            return pointer->data;
        }
        pointer = pointer->next;
    }
    return result;
}
bool destroyHashMap(HashMap* hashmap)
{
    int i=0;
    HashNode *hpointer;
    while(i < hashmap->size){
        hpointer=hashmap->table[i].next;
        while(hpointer!=NULL)
        {
            hashmap->table[i].next=hpointer->next;
            //逐个释放结点空间，防止内存溢出
            free(hpointer);
            hpointer=hashmap->table[i].next;
        }
        //换至下一个结点
        i++;
    }
    free(hashmap->table);
    free(hashmap);
    printf("Destory hashmap Success!");
}
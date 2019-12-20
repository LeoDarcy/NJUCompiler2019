#ifndef HASHMAP_H
#define HASHMAP_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#define HashSize 60
typedef struct DataType{
	int key;  //键(实际上是Operand地址)
	int offset;  //内存中的值
    int reg_no; //在reg中的编号
    int type; // type = 0 表示未使用，type = 1表示reg_no可以用， type = 2 表示offset和reg_no可以用
}DataType; //对基本数据类型进行封装，类似泛型
typedef struct HashNode{
	DataType data;
	struct HashNode *next;  //key冲突时，通过next指针进行连接
}HashNode;
typedef struct HashMap{
	int size;
	HashNode *table;
}HashMap;
//获得HashMap，size是hash桶的数量
HashMap* createHashMap(int size);
//支持更新其中的数据
bool putHashMap(HashMap* hashmap, int key, int offset, int reg_no, int type);
//返回的数据类型如果key不相等，说明没找到
DataType getItemFromHashMap(HashMap* hashmap, int key);

bool destroyHashMap(HashMap* hashmap);
#endif
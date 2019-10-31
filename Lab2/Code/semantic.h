#ifndef SEMANTIC_H
#define SEMANTIC_H
#include "vectorList.h"
#include "symboltable.h"

void Program(TreeNode* root);
void ExtDefList(TreeNode* p);
void ExtDef(TreeNode* p);


Type Specifier(TreeNode* p);
Type StructSpecifier(TreeNode* p);

ValHashTable Exp(TreeNode* p);
void Args(TreeNode* p, vector* args);
#endif



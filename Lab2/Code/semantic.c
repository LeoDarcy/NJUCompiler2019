#include "tree.h"
#include "semantic.h"
#include "vectorList.h"
#include <assert.h>


void semanticAnalyse(TreeNode* root)
{
	initHashTable();
	traverseTree(root);
}


void ErrorGenerator(char* str)
{
	printf("%s", str);
	assert(0);
}

/*(1) High-level Definitions*/
void Program(TreeNode* root)
{
	if(root==NULL)	return;
	ExtDefList(root->firstChild);
}

void ExtDefList(TreeNode* p)
{
	if(p == NULL)	return;
	ExtDef(p->firstChild);
	if(p->lastChild != NULL)
		ExtDefList(p->lastChild);
}

void ExtDef(TreeNode* p)
{
	if(p == NULL)	return;
	TreeNode* q = p->firstChild;
	if(!q || q->nodetype == TYPE_Specifier) return; //the first must be "Specifier"
	Type specifier_type= Specifier(q);
	
	if(q->next && q->next->nodetype == TYPE_ExtDecList)
		ExtDecList(q->next, specifier_type);
	else if(q->next && q->next->nodetype == TYPE_FuncDec)
	{
		//in FuncDec, add the Func into symbol table
		FunDec(q->next, specifier_type);
		if(!q->next->next || q->next->next->nodetype == TYPE_CompSt)	
		{
			ErrorGenerator("wrong in ExtDef -> Specifier FunDec ??wrong tye");
			return;
		}
		CompSt(q->next->next);
	}
	return;
}

void ExtDecList(TreeNode* p, Type specifier)
{
	if(p == NULL) return;
	TreeNode* child = p->firstChild;
	if(child == NULL)
	{
		ErrorGenerator("Find ExtDecList -> NULL");
	}
	if(child->nodetype == TYPE_VarDec)
	{
		//ExtDecList -> VarDec ExtDecList, and check VarDec all in symbol table
		VarDec(child, specifier, true);//true表示需要加入符号表中
	}
	//if ExtDecList-> VarDec COMMA ExtDecList
	if(p->lastChild != NULL && p->lastChild->nodetype == TYPE_VarList)
		ExtDecList(p->lastChild, specifier);
}

/*(2) Specifiers*/
Type Specifier(TreeNode* p)
{
	if(p == NULL) return NULL;
	TreeNode* q=p->firstChild;
	if(q && q->nodetype == TOKEN_TYPE)
	{
		Type type=(Type)malloc(sizeof(Type));
		type->kind=BASIC;
		if(strcmp(q->value,"int")==0)
			type->u.basic=0;
		else
			type->u.basic=1;
		return type;
	}
	else if(q && strcmp(q->name,"StructSpecifier")==0)
	{
		return StructSpecifier(q);	
	}
}

Type StructSpecifier(TreeNode* p)
{
	if(p==NULL) return NULL;
	TreeNode* q=p->firstChild;
	if(!q || strcmp(q->name,"STRUCT")!=0) return NULL;
	if(q->next && strcmp(q->next->name,"OptTag")==0) //definition, insert
	{
		Type type=(Type)malloc(sizeof(Type));
		type->kind=STRUCTURE;
		char name[33]="";
		if(q->next->firstChild!=NULL)//firstChild could be empty
			strcpy(name,q->next->firstChild->value);

		if(!q->next->next || strcmp(q->next->next->name,"LC")!=0)	return NULL;
		TreeNode* r=q->next->next->next;
		if(r && strcmp(r->name,"DefList")==0)
			//type = DefList(r, type);段大哥这一句参数和返回值不统一，你可以把我的参数改一改
			;
		//if(!r->next || strcmp(r->next->name,"RC")!=0)	return NULL;
		return type;
	}
	else if(q->next && strcmp(q->next->name,"Tag")==0) //define variables WITH the defined structure, find
	{
		char name[33];
		strcpy(name,q->next->firstChild->value);
		Type type= "find type with the name in the vtable";
		return type; 
	}
	
}


/*(3) Declarators*/

//TODO：传入变量类型，向符号表中加入该变量
//注意这里的VarDec有可能是需要加入，有可能是不用加入而是需要检测的
//总结来说这个实现的是关于VarDec的自动检测加入或自动报错
void VarDec(TreeNode* p, ValHashTable* item, bool needtoAdd)
{
	if(p == NULL) return NULL;
	TreeNode* q = p->firstChild;
	if(q == NULL) return NULL;
	if(q->nodetype == TOKEN_ID)
	{
		//TODO: check TOKEN_ID is in symbol table
		//Add or report error
		//如果是用于函数参数的话不用考虑重定义的问题，直接就可以了
		if(needtoAdd)
		{
			//check symbol table
		}
		else
		{
			item->name = q->name;
			return;
		}
		
	}
	else if(q->nodetype == TYPE_VarDec)
	{
		//VarDec(q);
		//类似于数组类型的处理，最后根据needtoADD判断是否要加入到符号表中，
		//这里可能出现错误10，非数组元素使用[]来访问
		if(needtoAdd)
		{
			//check
		}
		else
		{
			item->type->u.array.elem = item->type;//考虑变成数组
			item->type->u.array.size = atoi(q->next->value);//得到数组长度
			item->type->kind = STRUCTURE;//修改成数组类型
		}
		
	}
	else
	{
		ErrorGenerator("error VarDec-> ??\n");
	}
	
}
//功能：传参是函数返回类型和指针，将这个函数声明加入到符号表中。
void FunDec(TreeNode* p, Type Specifier)
{
	if(p == NULL) return;
	TreeNode* func_name = p->firstChild;
	if(func_name == NULL)
	{
		ErrorGenerator("Wrong in FunDec! No children!");
		return;
	}
	TreeNode* func_vars = func_name->next->next;
	if(func_vars->nodetype == TOKEN_RP)
	{
		//说明没有参数
		//TODO 知道了返回值和函数名，加入符号表中
		//TODO：判断是否出现错误类型4，函数重复定义

	}
	else
	{
		//说明出现多个参数，将加入符号表的功能要求在VarList中实现
		//在VarList中传入一个vector列表引用，每个元素是一个参数，包含了类型信息
		vector* vars = NULL;
		VarList(func_vars, vars);
		//TODO: 和上面if一样，加入符号表
	}
}

//实现功能：填充参数列表,这里的Varist表示的只是参数，所以不需要考虑名字
void VarList(TreeNode* p, vector* vars)
{
	if(p == NULL) return;
	if(p->firstChild == p->lastChild)
	{
		//说明是Varist->ParamDec
		ParamDec(p->firstChild, vars);
	}
	else
	{
		//说明是VarList->ParamDec COMMA VarList
		ParamDec(p->firstChild, vars);
		VarList(p->lastChild, vars);
	}
	
}

void ParamDec(TreeNode* p, vector* vars)
{
	if(p == NULL) return;
	//TODO:将参数填入vector中
	//主要保存参数的类型，可以不用调用VarDec
	Type specifier = Specifier(p->firstChild);
	ValHashTable* var = (ValHashTable*)malloc(sizeof(ValHashTable));
	var->type = specifier;
	VarDec(p->lastChild, var, false);//不用加入符号表，只是解析得到var
	//加入参数列表
	AddItem(vars, var);
}
/*(4) Statements*/
//TODO：在函数块中的{}包围部分，需要考虑作用域的问题
void CompSt(TreeNode* p)
{
	if(p == NULL) return;
	//初步想法：有记录作用域的栈，这个记录作用域的为全局变量，在{}中的作用域就push到最上面
	//这期间调用VarDec之类新加的局部变量都挂在这个作用域上，和书上的图一样
	TreeNode* def_list = p->firstChild->next;
	TreeNode* stmt_list = def_list->next;

	DefList(def_list);
	//这里的stmt_list可能为空
	if(stmt_list->nodetype == TYPE_StmtList)
	{
		//说明stmt_list不为空
		StmtList(stmt_list);
	}

	//TODO：在结束是释放局部变量，pop作用域栈
}

void StmtList(TreeNode* p)
{
	if(p == NULL) return;
	Stmt(p->firstChild);
	if(p->firstChild == p->lastChild)
	{
		;//说明Stmt:ist->Stmt
	}
	else
	{
		//说明Stmt:ist->Stmt StmtList
		StmtList(p->lastChild);
	}
	
}

void Stmt(TreeNode* p)
{
	if(p == NULL) return;
	TreeNode* child = p->firstChild;
	switch (child->nodetype)
	{
	case TYPE_Exp:
		/* code */
		break;
	case TYPE_CompSt:
		{CompSt(child);}
		break;
	case TOKEN_RETURN:{/*检查有关return返回值的问题？作用域栈也要保存返回值*/} 
		break;
	case TOKEN_IF:{/*检查有关if的问题？作用域栈也要保存返回值*/} 
		break;
	case TOKEN_WHILE:{/*检查有关while的问题？作用域栈也要保存返回值*/} 
		break;
	default:
		break;
	}
}

/*(5) Local Definitions*/
void DefList(TreeNode* p)
{
	if(p==NULL)	return;
	TreeNode* q=p->firstChild;
	if(q==NULL)	return;//说明DefList->null
	if(q->nodetype == TYPE_Def)
		Def(q);
	if(q->next && q->next->nodetype == TYPE_DefList)
		DefList(q->next);
	
}

void Def(TreeNode* p)
{
	if(p==NULL)	return;
	TreeNode* q=p->firstChild;
	Type specifier = NULL;
	if(q && q->nodetype == TYPE_Specifier)
		specifier = Specifier(q);
	else
	{
		ErrorGenerator("Wrong in Def-> not Speicifier");
		return;
	}
		
	if(q->next && q->next->nodetype == TYPE_DecList)
		DecList(q->next, specifier);
	//if(!q->next->next || strcmp(q->next->next->name,"SEMI")!=0)	return;
}
//传入类型参数，这里接下来都要用到这个类型
void DecList(TreeNode* p, Type specifier)
{
	if(p==NULL)	return;
	TreeNode* q=p->firstChild;
	if(q && q->nodetype == TYPE_Dec)
	{
		//Dec包含了名字
		Dec(q, specifier);
		if(!q->next || strcmp(q->next->name,"COMMA")!=0)	return;
		if(q->next->next && strcmp(q->next->next->name,"DecList")==0)
			DecList(q->next->next, specifier);
	}
	else
	{
		ErrorGenerator("Wrong in DecList-> Not Dec");
	}
	
}

void Dec(TreeNode* p, Type specifier)
{
	if(p==NULL)	return;
	TreeNode* q=p->firstChild;
	if(q && strcmp(q->name,"VarDec")==0)
	{
		
		if(q->next && strcmp(q->next->name,"ASSIGNOP")==0)
		{
			/* need to record both sides of the "=" */
			ValHashTable value = Exp(q->next->next);
			if(q->next->next && q->next->next->nodetype == TYPE_Exp)
				value = Exp(q->next->next);
			//这里还不需要考虑赋值问题，如果需要赋值的话就在这里进行修改
			VarDec(q, specifier, true);//true表示需要向符号表加入
		}
		else
		{
			VarDec(q, specifier, true);//true表示需要向符号表加入
		}
	}	
}


/*(6) Expressions*/
//返回一个临时的变量，可以用于以后实验中赋值的问题。
ValHashTable Exp(TreeNode* p)//!
{
	if(p==NULL)	return;
	TreeNode* q=p->firstChild;
	if(q==NULL)	return;
	if(q->nodetype == TYPE_Exp)
	{
		ValHashTable left = Exp(q);
		if(q->next==NULL)	return;
		TreeNode* r=q->next->next;
		switch(q->next->nodetype)//match or not important
		{
		case TOKEN_ASSIGNOP:{
						if(r==NULL)	return;
						ValHashTable right = Exp(r);
						//TODO:检查左右类型是否符合，然后赋值操作
			}break;
		case TOKEN_AND:		{
						if(r==NULL)	return;
						ValHashTable right = Exp(r);
						//TODO:检查左右类型是否符合，然后赋值操作		
			}break;
		case TOKEN_OR:		{
						if(r==NULL)	return;
						ValHashTable right = Exp(r);
						//TODO:检查左右类型是否符合，然后赋值操作
			}break;
		case TOKEN_RELOP:	{
						if(r==NULL)	return;
						ValHashTable right = Exp(r);
						//TODO:检查左右类型是否符合，然后赋值操作
			}break;
		case TOKEN_PLUS:	{
						if(r==NULL)	return;
						ValHashTable right = Exp(r);
						//TODO:检查左右类型是否符合，然后赋值操作
						//check left ? right				
			}break;
		case TOKEN_MINUS:	{
						if(r==NULL)	return;
						ValHashTable right = Exp(r);
						//TODO:检查左右类型是否符合，然后赋值操作
						//check left ? right	
			}break;
		case TOKEN_STAR:	{
						if(r==NULL)	return;
						ValHashTable right = Exp(r);
						//TODO:检查左右类型是否符合，然后赋值操作
						//check left ? right			
			}break;
		case TOKEN_DIV:		{
						if(r==NULL)	return;
						ValHashTable right = Exp(r);
						//TODO:检查左右类型是否符合，然后赋值操作
						//check left ? right					
			}break;
		case TOKEN_LB:		{
						if(r==NULL)	return;
						ValHashTable right = Exp(r->next);
						//TODO:检查左右类型是否符合，然后赋值操作
						//这里可能出现错误right的值不是int
						//这里表示的是exp[(int)exp]数组
						if(r->next==NULL)	return;	//RB
			}break;		
		case TOKEN_DOT:		{
						char name[33];
						if(strcmp(r->name,"ID"))
							strcpy(name,r->value);	
						//检测left是不是一个结构体，错误类型13，非结构体使用DOT
						//检测右侧name是否是结构体的成员
			}break;
		default:printf("error!\n");
		}			
	}
	else if(q->nodetype == TOKEN_LP)
	{
		//表示（exp）
		return Exp(q->next);
	}
	else if(q->nodetype == TOKEN_MINUS)
	{
		//表示exp-> -exp
		ValHashTable right = Exp(q->next);
		//转成负号返回即可
		//TODO:对right 值操作
		return right;
	}
	else if(q->nodetype == TOKEN_NOT)
	{
		//表示exp-> ！exp
		ValHashTable right = Exp(q->next);
		//转成正确的类型返回即可
		//TODO:对right 值操作
		return right;
	}
	else if(q->nodetype == TOKEN_ID)
	{
		ValHashTable tmp;
		//构建常量ID
		//TODO：检查符号表中是否有该ID，是否已经定义？
		//接下来可能是ID(Args)或者ID()
		if(q->next->next->nodetype == TYPE_Args)
		{
			//ID（Args）
			//得到参数列表
			vector* args = NULL;
			Args(q->next->next, args);
			//检查参数列表是否符合符号表
		}
		else
		{
			//ID()
			//检查ID是否是函数以及参数是否正确，利用返回值构建tmp
		}
		
		return tmp;
	}
	else if(q->nodetype == TOKEN_INT)
	{
		ValHashTable tmp;
		//构建常量int
		return tmp;
	}
	else if(q->nodetype == TOKEN_FLOAT)
	{
		ValHashTable tmp;
		//构建常量float
		return tmp;
	}
}

void Args(TreeNode* p, vector* args)
{
	if(p->firstChild == p->lastChild)
	{
		//说明args->exp
		ValHashTable arg = Exp(p->firstChild);
		//将arg加入到args中
	}
	else
	{
		//说明args->exp COMMA exps
		ValHashTable arg = Exp(p->firstChild);
		//将arg加入到args中
		Args(p->firstChild->next->next, args);//接着添加下一个参数
	}
	
}




/*=============================
 * 栈的顺序存储结构（顺序栈）
  =============================*/

#include "SqStack.h"

/*
 * 初始化
 *
 * 构造一个空栈。初始化成功则返回OK，否则返回ERROR。
 */
Status InitStack(SqStack *S)
{
	//构造一个空栈
	//首先要判断是否为空
	if(S == NULL)
	{
		return ERROR;
	}
	//申请一个地址空间
	(*S).base = (SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if((*S).base == NULL)
	{
		exit(OVERFLOW);
	}
	(*S).top = (*S).base;
	(*S).stacksize = STACK_INIT_SIZE;
	return OK;
}

/*
 * 判空
 *
 * 判断顺序栈中是否包含有效数据。
 *
 * 返回值：
 * TRUE : 顺序栈为空
 * FALSE: 顺序栈不为空
 */
Status EmptyStack(SqStack S)
{
	if(S.base == S.top)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/*
 * 取值-注意函数的定义类型
 *
 * 获取操作符栈的栈顶元素。
 *
 *【注】
 * 该操作的实现与传统的顺序栈的取值操作有些不同，但核心作用一致
 */
SElemType GetTop(SqStack S)
{
	//取值操作时候一般都要定义一个新的局部指针接受、保存最终形参的值
	SElemType e;
	if(S.base == NULL || S.top == S.base)
	{
		return '\0';
	}
	//不改变栈中元素
	e = *(S.top - 1);
	return e;
}

/*
 * 入栈
 *
 * 将元素e压入到栈顶。
 */
Status Push(SqStack *S,SElemType e)
{
	if(S == NULL || (*S).base == NULL)
	{
		return ERROR;
	}
	// 栈满时，追加存储空间
	if((*S).top - (*S).base >= (*S).stacksize)
	{
		(*S).base = (SElemType*)realloc((*S).base,((*S).stacksize + STACKINCREMENT) * sizeof(SElemType));
		if((*S).base == NULL)
		{
			exit(OVERFLOW);
		}
		(*S).top = (*S).base + (*S).stacksize;
		(*S).stacksize += STACKINCREMENT;
	}
	//每次添加完一个元素后(入栈)，S.top后移一个位置，即S.top指向这个刚添加的元素的下一个位置
	*(S->top++) = e;
	return OK;
	
}

/*
 * 出栈
 *
 * 将栈顶元素弹出，并用e接收。
 */
Status Pop(SqStack *S,SElemType *e)
{
	if(S == NULL || (*S).base == NULL)
	{
		return ERROR;
	}
	if((*S).top == (*S).base)
	{
		return ERROR;
	}
	// 出栈栈顶指针先递减，再赋值
	*e = *(--(*S).top);
	return OK;
}

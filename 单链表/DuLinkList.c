#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//全局的宏定义
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
//#define OVERFLOW -1
#define MAXSIZE 20

//注释即定义
typedef int Elem;
typedef int Status;

typedef struct DuLNode
{
    Elem data;
    struct DuLNode *prior; //前驱
    struct DuLNode *next;  //后继
} DuLNode, *DuLinkList;

/*
 * 初始化
 *
 * 初始化成功则返回OK，否则返回ERROR。
 */
Status InitList(DuLinkList *L)
{
    *L = (DuLinkList)malloc(sizeof(DuLNode));
    if (*L == NULL)
    {
        return ERROR;
    }
    (*L)->next = (*L)->prior = *L;
    return OK;
}

/*
 * 销毁(结构)
 *
 * 释放双向循环链表所占内存。
 */
Status DestoryList(DuLinkList *L)
{
    if (L == NULL || *L == NULL)
    {
        return ERROR;
    }
    ClearList(*L);
    free(*L);
    *L = NULL;
    return OK;
}

/*
 * 置空(内容)
 *
 * 这里需要释放双向循环链表中非头结点处的空间。
 */
Status ClearList(DuLinkList *L)
{
    DuLinkList p, q;
    if ((*L) == NULL)
    {
        return ERROR;
    }

    p = (*L)->next;

    while (p != NULL)
    {
        q = p->next;
        free(q);
        p = q;
    }
    (*L)->next = (*L)->prior = (*L);
    return OK;
}

int main()
{
    printf("▆▆▆▆▆ 循环链表 ▆▆▆▆▆\n");
    system("pause");
    return 0;
}
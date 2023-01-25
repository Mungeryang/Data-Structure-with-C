#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_SIZE 100
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

typedef int TElemtype;
typedef int Status;

/*
双亲表示方法：
如果树中的元素过多时候，我们急需要关注父亲节点也需要关注孩子节点时，
此时我们就需要扩充此时的存储结构以便提高效率。
*/
typedef struct PTnode
{
    TElemtype data;
    int data;
} PTnode;

typedef struct
{
    PTnode nodes[MAX_TREE_SIZE];
    int r, n;
} PTree;
/*
***********************************************
*/

/*
孩子兄弟表示法
*/
typedef struct CTnode
{
    int child;
    struct CTnode *next;
} * ChildPtr; //孩子节点

typedef struct CTnode
{
    TElemtype data;
    ChildPtr FirstChild;
} CTBox;

typedef struct
{
    CTBox nodes[MAX_TREE_SIZE];
    int r, n;
} CTree;

/*
双亲孩子表示法的改进
*/
typedef struct CTnode
{
    TElemtype data;
    TElemtype parent; //增加一列父亲节点标号
    ChildPtr FirstChild;
} CTBox;

/*
孩子兄弟表示法
*/
typedef struct CSnode
{
    TElemtype data;
    struct CSnode *firstchild, *rightsib;
} CSnode, *CSTree;

/*二叉链表*/
typedef struct BiTNode
{
    TElemtype data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

int main()
{
    printf("The different types of Creating a tree..\n");
    system("pause");
    return 0;
}
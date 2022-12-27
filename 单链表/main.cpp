#include<stdio.h>
#include<stdlib.h>


//在此程序中，*LinkList是变量的指针；LinkList为指针变量。

//单链表的增删改查
//线性表的链式表示就是单链表

#define Maxsize 50
#define InitSize 100

//定义一个整型类型的变量
typedef int ElemType;

//单链表结构创建-8个字节
typedef struct LNode {//单链表的结构

	ElemType data;//数据域
	struct LNode* next;//指针域

}LNode,*LinkList;
//LinkList为结构体指针等价于struct LNode*
//别名LNode可以和上面保持一致


//头插法插入新的节点
//创建单链表->带有头结点
//头结点只需要头指针指向，啥也不存
LinkList CreatList1(LinkList &L) {

	LNode* q;
	int x;
	L = (LinkList)malloc(sizeof(LNode));//带头结点的链表
	L->next = NULL;
	scanf_s("%d", &x);
	while (x != 9999) {
		q = (LinkList)malloc(sizeof(LNode));
		q->data = x;
		q->next = L->next;
		L->next = q;
		scanf_s("%d", &x);
	}
	return L;
}

//尾插法创建单链表
LinkList CreatList2(LinkList &L) {

	int x;
	L = (LinkList)malloc(sizeof(LNode));//带头结点的链表
	//在这里需要注意的是，r本身就是表尾节点,指向链表尾部
	LNode* s, * r = L;//等价于LinkList s,r=L;
	scanf_s("%d", &x);
	while (x != 9999) {
		s = (LinkList)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;//r指向新的表尾节点
		scanf_s("%d", &x);
	}
	r->next = NULL;//尾节点指针赋值为空
	return L;
}

//查找节点
LNode* GetElem(LinkList L, int i) {

	int j = 1;
	//初始指向虚拟头结点的下一个节点
	LNode* p = L->next;
	if (i == 0) {
		return L;
	}
	if (i < 1) {
		return NULL;
	}
	//p->非空
	while (p && j < i) {

		p = p->next;
		j++;
	}
	return p;
}

//任意两个节点之间插入节点
//第i个位置插入值为e的节点
bool InsertFrontList(LinkList L,int i,ElemType e) {

	LinkList p = GetElem(L,i - 1);
	if (NULL == p) {
		return false;
	}
	LinkList s = (LNode*)malloc(sizeof(LNode));//为新插入的节点申请内存空间
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

bool InsertBackList(LinkList L,ElemType e) {

	//L = (LinkList)malloc(sizeof(LNode));//带头结点的链表
	while (L->next != NULL) {
		L = L->next;
	}
	LNode* q;
	int x;
	scanf_s("%d", &x);
	while (x != 9999) {
		q = (LinkList)malloc(sizeof(LNode));
		q->data = x;
		L->next = q;
		q->next = NULL;
		scanf_s("%d", &x);
	}
	return L;

}

//无论是中间插入还是删除，找到需要操作节点的前驱节点是关键

//删除第i个位置的节点
bool DeleteList(LinkList L,int i) {

	//找到要删除元素的前驱结点
	LinkList p = GetElem(L, i - 1);
	LinkList q = p->next;
	if (p == NULL) {

		return false;//要删除的位置不存在
	}
	p->next = q->next;//断链
	free(q);
	q = NULL;
	return true;

}


void PrintList(LinkList L) {

	//头结点
	L = L->next;
	while (L != NULL) {
		printf("%d\t", L->data);
		L = L->next;
	}
}

//查找第几个元素
LinkList LocateElem(LinkList L, ElemType e) {

	int j = 1;
	LinkList p = L->next;
	while (p != NULL && p->data != e) {
		p = p->next;
		j++;
	}
	return p;

}


int main() {

	//定义链表头,结构体指针类型
	LinkList L;
	LinkList search;//用来存储拿到的某一个节点
	LinkList search1;
	printf("请在下方输入单链表的值：（^_^大于5个元素且输入9999终止^_^）\n");
	CreatList1(L);
	printf("头插法的结果为：");
	PrintList(L);
	search = GetElem(L, 2);
	if (search != NULL) {

		printf("\n按序号查找成功！~\n");
		printf("该位置的值为：%3d\n", search->data);
	}
	search1 = LocateElem(L, 5);
	/*
	if (search1 != NULL) {

		printf("\n按序号查找成功！~\n");
		printf("该的值为：%3d", search->data);
	}
	*/
	InsertFrontList(L, 3, 30);
	PrintList(L);
	printf("\n-----------\n");
	printf("删除后的结果为：\n");
	DeleteList(L, 3);
	PrintList(L);
	printf("\n-----------\n");
	printf("请在下方输入单链表的值：（^_^大于5个元素且输入9999终止^_^）\n");
	CreatList2(L);
	printf("尾插法的结果为：");
	PrintList(L);
	return 0;

}
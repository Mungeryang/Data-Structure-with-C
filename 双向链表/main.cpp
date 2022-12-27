#include<stdio.h>
#include<stdlib.h>


//学一下双向链表的创建与操作
//对后面学习树的结构创建打基础

#define Maxsize 50
#define InitSize 100

//定义一个整型类型的变量
typedef int ElemType;

typedef struct Dnode {
	ElemType data;//数据域
	struct Dnode* prior;//前驱指针
	struct Dnode* next;//后继指针
}Dnode,*DinkList;

DinkList creatList(DinkList& L) {

	Dnode* s;
	int x;
	L = (DinkList)malloc(sizeof(Dnode));
	L->next = NULL;
	L->prior = NULL;
	scanf_s("%d", &x);
	while (x != 9999) {
		s = (DinkList)malloc(sizeof(Dnode));
		s->data = x;
		s->next = L->next;
		if (L->next != NULL) {
			L->next->prior = s;
		}
		s->prior = L;
		L->next = s;
		scanf_s("%d", &x);
	}
	return L;
}

void PrintList(DinkList L) {

	L = L->next;
	while (L != NULL) {
		printf("%d", L->data);
		L = L->next;
	}
	printf("\n");
}



int main() {

	DinkList L;
	creatList(L);
	PrintList(L);
	return 0;


}
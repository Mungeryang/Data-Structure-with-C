#include<stdio.h>
#include<stdlib.h>


//ѧһ��˫������Ĵ��������
//�Ժ���ѧϰ���Ľṹ���������

#define Maxsize 50
#define InitSize 100

//����һ���������͵ı���
typedef int ElemType;

typedef struct Dnode {
	ElemType data;//������
	struct Dnode* prior;//ǰ��ָ��
	struct Dnode* next;//���ָ��
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
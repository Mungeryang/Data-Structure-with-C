#include<stdio.h>
#include<stdlib.h>


//�ڴ˳����У�*LinkList�Ǳ�����ָ�룻LinkListΪָ�������

//���������ɾ�Ĳ�
//���Ա����ʽ��ʾ���ǵ�����

#define Maxsize 50
#define InitSize 100

//����һ���������͵ı���
typedef int ElemType;

//������ṹ����-8���ֽ�
typedef struct LNode {//������Ľṹ

	ElemType data;//������
	struct LNode* next;//ָ����

}LNode,*LinkList;
//LinkListΪ�ṹ��ָ��ȼ���struct LNode*
//����LNode���Ժ����汣��һ��


//ͷ�巨�����µĽڵ�
//����������->����ͷ���
//ͷ���ֻ��Ҫͷָ��ָ��ɶҲ����
LinkList CreatList1(LinkList &L) {

	LNode* q;
	int x;
	L = (LinkList)malloc(sizeof(LNode));//��ͷ��������
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

//β�巨����������
LinkList CreatList2(LinkList &L) {

	int x;
	L = (LinkList)malloc(sizeof(LNode));//��ͷ��������
	//��������Ҫע����ǣ�r������Ǳ�β�ڵ�,ָ������β��
	LNode* s, * r = L;//�ȼ���LinkList s,r=L;
	scanf_s("%d", &x);
	while (x != 9999) {
		s = (LinkList)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;//rָ���µı�β�ڵ�
		scanf_s("%d", &x);
	}
	r->next = NULL;//β�ڵ�ָ�븳ֵΪ��
	return L;
}

//���ҽڵ�
LNode* GetElem(LinkList L, int i) {

	int j = 1;
	//��ʼָ������ͷ������һ���ڵ�
	LNode* p = L->next;
	if (i == 0) {
		return L;
	}
	if (i < 1) {
		return NULL;
	}
	//p->�ǿ�
	while (p && j < i) {

		p = p->next;
		j++;
	}
	return p;
}

//���������ڵ�֮�����ڵ�
//��i��λ�ò���ֵΪe�Ľڵ�
bool InsertFrontList(LinkList L,int i,ElemType e) {

	LinkList p = GetElem(L,i - 1);
	if (NULL == p) {
		return false;
	}
	LinkList s = (LNode*)malloc(sizeof(LNode));//Ϊ�²���Ľڵ������ڴ�ռ�
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

bool InsertBackList(LinkList L,ElemType e) {

	//L = (LinkList)malloc(sizeof(LNode));//��ͷ��������
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

//�������м���뻹��ɾ�����ҵ���Ҫ�����ڵ��ǰ���ڵ��ǹؼ�

//ɾ����i��λ�õĽڵ�
bool DeleteList(LinkList L,int i) {

	//�ҵ�Ҫɾ��Ԫ�ص�ǰ�����
	LinkList p = GetElem(L, i - 1);
	LinkList q = p->next;
	if (p == NULL) {

		return false;//Ҫɾ����λ�ò�����
	}
	p->next = q->next;//����
	free(q);
	q = NULL;
	return true;

}


void PrintList(LinkList L) {

	//ͷ���
	L = L->next;
	while (L != NULL) {
		printf("%d\t", L->data);
		L = L->next;
	}
}

//���ҵڼ���Ԫ��
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

	//��������ͷ,�ṹ��ָ������
	LinkList L;
	LinkList search;//�����洢�õ���ĳһ���ڵ�
	LinkList search1;
	printf("�����·����뵥�����ֵ����^_^����5��Ԫ��������9999��ֹ^_^��\n");
	CreatList1(L);
	printf("ͷ�巨�Ľ��Ϊ��");
	PrintList(L);
	search = GetElem(L, 2);
	if (search != NULL) {

		printf("\n����Ų��ҳɹ���~\n");
		printf("��λ�õ�ֵΪ��%3d\n", search->data);
	}
	search1 = LocateElem(L, 5);
	/*
	if (search1 != NULL) {

		printf("\n����Ų��ҳɹ���~\n");
		printf("�õ�ֵΪ��%3d", search->data);
	}
	*/
	InsertFrontList(L, 3, 30);
	PrintList(L);
	printf("\n-----------\n");
	printf("ɾ����Ľ��Ϊ��\n");
	DeleteList(L, 3);
	PrintList(L);
	printf("\n-----------\n");
	printf("�����·����뵥�����ֵ����^_^����5��Ԫ��������9999��ֹ^_^��\n");
	CreatList2(L);
	printf("β�巨�Ľ��Ϊ��");
	PrintList(L);
	return 0;

}
#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct LinkNode {

	ElemType data;
	struct LinkNode* next;
}LinkNode;

typedef struct {

	struct LinkNode* front, * tail;

}LinkQueue;

bool InitQueue(LinkQueue& Q) {

	Q.front = Q.tail = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next = NULL;
	return true;
}

//β�巨���
void EnQueue(LinkQueue& Q, ElemType x) {

	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	Q.tail->next = s;
	Q.tail = s;

}


//ͷ�巨ɾ��
bool DeQueue(LinkQueue& Q, ElemType& x) {

	//�ж϶����Ƿ�Ϊ��
	if (Q.front == Q.tail)return false;
	//��ͷ���ӽڵ�
	LinkNode* p = Q.front->next;
	x = p->data;
	Q.front->next = p->next;
	if (Q.tail == p) {

		Q.front = Q.tail;
	}
	free(p);
	return true;
}

//��ν���
//���Ľṹ�彨��
typedef char BiElemType;
typedef struct BiTNode {

	BiElemType root;
	struct BiTNode* left;
	struct BiTNode* right;
}BiTNode,*BiTree;

//��ζ���
typedef struct tag {
	BiTree p;//����ĳһ���ڵ�ĵ�ַ
	struct tag* pnext;
}tag_t,*ptag_t;

//ǰ�����->������ȱ��� 
void PreOrder(BiTree p) {

	if (p != NULL) {
		putchar(p->root);
		PreOrder(p->left);
		PreOrder(p->right);
	}
	
}

//�������
void InOrder(BiTree p) {

	if (p != NULL) {
		InOrder(p->left);
		putchar(p->root);
		InOrder(p->right);
	}

}


//�������
void LastOrder(BiTree p) {

	if (p != NULL) {
		LastOrder(p->left);
		LastOrder(p->right);
		putchar(p->root);
	}

}

//�������->������ȱ���
void LevelOrder(BiTree T) {

}


 

int main(void) {

	BiTree pnew;
	int i, j, pos;
	char c;
	BiTree tree = NULL;//����  
	//��ν�����������
	ptag_t phead = NULL, ptail = NULL, listnew = NULL, pcur = NULL;
	while (scanf_s("%c", &c) != EOF) {

		if (c == '\n') {
			break;
		}

		pnew = (BiTree)calloc(1, sizeof(BiTNode));//calloc����ռ䲢�Կռ���г�ʼ��
		pnew->root = c;
		listnew = (ptag_t)calloc(1, sizeof(tag_t));
		listnew->p = pnew;
		if (tree == NULL) {
			tree = pnew;
			phead = listnew;//����ͷ
			ptail = listnew;//����β
			pcur = listnew;
			continue;
		}
		else {
			ptail->pnext = listnew;//�½ڵ���ӣ�β�巨
			ptail = listnew;
		}
		if (pcur->p->left == NULL) {
			pcur->p->left = pnew;//���½ڵ���뵽��ǰ�ڵ������
		}
		else if (pcur->p->right == NULL) {
			pcur->p->right = pnew;//���½ڵ���뵽��ǰ�ڵ������
			pcur = pcur->pnext;//���Ҷ����˽ڵ��pcurָ����е���һ��Ԫ��
		}
	}
	
	printf("\n-----------ǰ�����---------\n");
	PreOrder(tree);
	printf("\n-----------�������---------\n");
	InOrder(tree);
	printf("\n-----------�������---------\n");
	LastOrder(tree);
	return 0;

}

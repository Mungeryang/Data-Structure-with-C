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

//尾插法入队
void EnQueue(LinkQueue& Q, ElemType x) {

	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	Q.tail->next = s;
	Q.tail = s;

}


//头插法删除
bool DeQueue(LinkQueue& Q, ElemType& x) {

	//判断队列是否为空
	if (Q.front == Q.tail)return false;
	//队头出队节点
	LinkNode* p = Q.front->next;
	x = p->data;
	Q.front->next = p->next;
	if (Q.tail == p) {

		Q.front = Q.tail;
	}
	free(p);
	return true;
}

//层次建树
//树的结构体建立
typedef char BiElemType;
typedef struct BiTNode {

	BiElemType root;
	struct BiTNode* left;
	struct BiTNode* right;
}BiTNode,*BiTree;

//层次队列
typedef struct tag {
	BiTree p;//树的某一个节点的地址
	struct tag* pnext;
}tag_t,*ptag_t;

//前序遍历->深度优先遍历 
void PreOrder(BiTree p) {

	if (p != NULL) {
		putchar(p->root);
		PreOrder(p->left);
		PreOrder(p->right);
	}
	
}

//中序遍历
void InOrder(BiTree p) {

	if (p != NULL) {
		InOrder(p->left);
		putchar(p->root);
		InOrder(p->right);
	}

}


//后序遍历
void LastOrder(BiTree p) {

	if (p != NULL) {
		LastOrder(p->left);
		LastOrder(p->right);
		putchar(p->root);
	}

}

//层序遍历->广度优先遍历
void LevelOrder(BiTree T) {

}


 

int main(void) {

	BiTree pnew;
	int i, j, pos;
	char c;
	BiTree tree = NULL;//树根  
	//层次建树辅助队列
	ptag_t phead = NULL, ptail = NULL, listnew = NULL, pcur = NULL;
	while (scanf_s("%c", &c) != EOF) {

		if (c == '\n') {
			break;
		}

		pnew = (BiTree)calloc(1, sizeof(BiTNode));//calloc申请空间并对空间进行初始化
		pnew->root = c;
		listnew = (ptag_t)calloc(1, sizeof(tag_t));
		listnew->p = pnew;
		if (tree == NULL) {
			tree = pnew;
			phead = listnew;//队列头
			ptail = listnew;//队列尾
			pcur = listnew;
			continue;
		}
		else {
			ptail->pnext = listnew;//新节点入队，尾插法
			ptail = listnew;
		}
		if (pcur->p->left == NULL) {
			pcur->p->left = pnew;//把新节点放入到当前节点的左孩子
		}
		else if (pcur->p->right == NULL) {
			pcur->p->right = pnew;//把新节点放入到当前节点的左孩子
			pcur = pcur->pnext;//左右都放了节点后，pcur指向队列的下一个元素
		}
	}
	
	printf("\n-----------前序遍历---------\n");
	PreOrder(tree);
	printf("\n-----------中序遍历---------\n");
	InOrder(tree);
	printf("\n-----------后序遍历---------\n");
	LastOrder(tree);
	return 0;

}

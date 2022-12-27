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

int main(void) {

	LinkQueue Q;
	ElemType data;
	bool ret;
	InitQueue(Q);
	EnQueue(Q, 3);
	EnQueue(Q, 4);
	EnQueue(Q, 5);
	EnQueue(Q, 6);
	EnQueue(Q, 7);
	ret = DeQueue(Q, data);
	if (ret) {
		printf("出队成功！！！\n");
		printf("出队元素为：%d\n", data);
	}
	else {
		printf("出队失败~~\n");
	}
	return 0;
}
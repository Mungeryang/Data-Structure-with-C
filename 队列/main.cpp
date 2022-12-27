#include<stdio.h>
#include<stdlib.h>

//408常考的循环队列

#define Maxsize 5
typedef int ElemType;
//循环队列的结构 
typedef struct {
	ElemType data[Maxsize];
	int front, tail;
}SqQueue;

//初始化函数
void InitQueue(SqQueue& q) {
	q.front = q.tail = 0;
}

//判断是否为空
bool isEmpty(SqQueue q) {

	//队头指针==队尾指针
	if (q.front == q.tail) {
		return true;
	}
	else {
		return false;
	}
	 
}

//元素入队函数
bool EnQueue(SqQueue& q, ElemType x) {


	//先判断队列是否满队
	if ((q.tail + 1) % Maxsize == q.front) {
		return false;
	}
	q.data[q.tail + 1] = x;
	q.tail = (q.tail + 1) % Maxsize;
	return true;
}

int main() {

	SqQueue q;
	bool ret;
	ElemType m;
	InitQueue(q);
	EnQueue(q, 1);
	EnQueue(q, 2);
	EnQueue(q, 3);
	return 0;

}
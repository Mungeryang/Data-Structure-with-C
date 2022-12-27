#include<stdio.h>
#include<stdlib.h>

//408������ѭ������

#define Maxsize 5
typedef int ElemType;
//ѭ�����еĽṹ 
typedef struct {
	ElemType data[Maxsize];
	int front, tail;
}SqQueue;

//��ʼ������
void InitQueue(SqQueue& q) {
	q.front = q.tail = 0;
}

//�ж��Ƿ�Ϊ��
bool isEmpty(SqQueue q) {

	//��ͷָ��==��βָ��
	if (q.front == q.tail) {
		return true;
	}
	else {
		return false;
	}
	 
}

//Ԫ����Ӻ���
bool EnQueue(SqQueue& q, ElemType x) {


	//���ж϶����Ƿ�����
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
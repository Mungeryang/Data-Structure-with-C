#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;	/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int Boolean; /* Boolean�ǲ�������,��ֵ��TRUE��FALSE */
#define MAXSIZE 9
#define MAXEDGE 15
#define MAXVEX 9

//�ڽӾ���Ķ���
typedef char VertexType; /* ��������Ӧ���û����� */
typedef int EdgeType; /* ���ϵ�Ȩֵ����Ӧ���û����� */
typedef struct
{
	VertexType vexs[MAXVEX]; /* ����� */
	EdgeType arc[MAXVEX][MAXVEX];/* �ڽӾ��󣬿ɿ����߱� */
	int numVertexes, numEdges; /* ͼ�е�ǰ�Ķ������ͱ��� */

}MGraph;

/*�������õ��Ķ��нṹ*/

/* ѭ�����е�˳��洢�ṹ */
typedef struct
{
	int data[MAXSIZE];
	int front;
	int rear;
}Queue;

/*��ʼ��һ���ն���*/
Status InitQueue(Queue* q) {
	q->front = 0;
	q->rear = 0;
	return 0;
}

/*�ж϶����Ƿ�Ϊ��*/
Status QueueEmpty(Queue q) {
	if (q.front == q.rear) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

/* ������δ���������Ԫ��eΪQ�µĶ�βԪ�� */
Status EnQueue(Queue* q, int e) {
	if ((q->rear + 1) % MAXSIZE == q->front) {
		return ERROR;//��������
	}
	q->data[q->rear] = e;//��Ԫ��e��ֵ����β
	q->rear = (q->rear + 1) % MAXSIZE;//rearָ����ƶ�
	return OK;
}
/* �����в��գ���ɾ��Q�ж�ͷԪ�أ���e������ֵ */
Status DeQueue(Queue* q, int *e) {
	if (q->front == q->rear) {/* ���пյ��ж� */
		return ERROR;
	}
	*e = q->data[q->front];/* ����ͷԪ�ظ�ֵ��e */
	q->front = (q->front + 1) % MAXSIZE;/* frontָ�������һλ�ã����������ת������ͷ�� */
	return OK;
}

/* ****************************************************** */
void CreatMGraph(MGraph* G) {
	int i, j;
	G->numEdges = 15;
	G->numVertexes = 9;
	/* ���붥����Ϣ����������� */
	G->vexs[0] = 'A';
	G->vexs[1] = 'B';
	G->vexs[2] = 'C';
	G->vexs[3] = 'D';
	G->vexs[4] = 'E';
	G->vexs[5] = 'F';
	G->vexs[6] = 'G';
	G->vexs[7] = 'H';
	G->vexs[8] = 'I';

	/*����ͼ�ı�Ȩ��ֵ*/
	for (i = 0; i < G->numVertexes; i++) {
		for (j = 0; j < G->numVertexes; j++) {
			G->arc[i][j] = 0;
		}
	}

	G->arc[0][1] = 1;
	G->arc[0][5] = 1;

	G->arc[1][2] = 1;
	G->arc[1][8] = 1;
	G->arc[1][6] = 1;

	G->arc[2][3] = 1;
	G->arc[2][8] = 1;

	G->arc[3][4] = 1;
	G->arc[3][7] = 1;
	G->arc[3][6] = 1;
	G->arc[3][8] = 1;

	G->arc[4][5] = 1;
	G->arc[4][7] = 1;

	G->arc[5][6] = 1;

	G->arc[6][7] = 1;

	for (i = 0; i < G->numVertexes; i++) {
		for (j = 0; j < G->numVertexes; j++) {
			G->arc[j][i] = G->arc[i][j];
		}
	}
}

Boolean visited[MAXVEX];/* ���ʱ�־������ */
/* �ڽӾ����������ȵݹ��㷨 */
void DFS(MGraph G, int i) {
	int j;
	visited[i] = TRUE;
	cout << G.vexs[i] << endl;
	for (j = 0; j < G.numVertexes; j++) {
		if (G.arc[i][j] == 1 && !visited[j]) {
			DFS(G, j);/* ��Ϊ���ʵ��ڽӶ���ݹ���� */
		}
	}
	
}

/* �ڽӾ������ȱ������� */
void DFSTraverse(MGraph G) {
	int i;
	for (i = 0; i < G.numVertexes; i++) {
		visited[i] = FALSE;/* ��ʼ���ж���״̬����δ���ʹ�״̬ */
	}
	for (i = 0; i < G.numVertexes; i++) {
		if (!visited[i]) {/* ��δ���ʹ��Ķ������DFS��������ͨͼ��ֻ��ִ��һ�� */ 
			DFS(G, i);
		}
	}
}
/* �ڽӾ���Ĺ�ȱ����㷨 */
/*�ȴ�ӡ�ڵ���ȥ������в���,��ӳ��ӵĲ���ֻ��Ϊ��ȥѰ�Һ��ӽڵ�*/
void BFSTraverse(MGraph G) {
	int i, j;
	Queue q;
	for (i = 0; i < G.numVertexes; i++) {
		visited[i] = FALSE;
	}
	InitQueue(&q);/* ��ʼ��һ�����õĶ��� */
	for (i = 0; i < G.numVertexes; i++) {
		if (!visited[i]) {/* ����δ���ʹ��ʹ��� */
			visited[i] = TRUE;/* ���õ�ǰ������ʹ� */
			cout << G.vexs[i] << endl;
			EnQueue(&q, i);/* ���˶�������� */
			while (!QueueEmpty(q)) {
				DeQueue(&q, &i);
				for (j = 0; j < G.numVertexes; j++) {
					/* �ж������������뵱ǰ������ڱ���δ���ʹ�  */
					if (G.arc[i][j] == 1 && !visited[j]) {

						visited[j] = TRUE;
						cout << G.vexs[j] << endl;
						EnQueue(&q, j);
					}
				}
			}
		}
	}
}


int main() {

	MGraph G;
	CreatMGraph(&G);
	cout << "\n������ȱ��������\n" << endl;
	DFSTraverse(G);
	cout << "\n������ȱ��������\n" << endl;
	BFSTraverse(G);
	return 0;

}






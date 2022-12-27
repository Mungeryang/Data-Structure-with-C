#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 9 /* �洢�ռ��ʼ������ */
#define MAXEDGE 15
#define MAXVEX 9

typedef int Status;	/* Status�Ǻ���������,��ֵ�Ǻ������״̬����,��OK�� */
typedef int Boolean; /* Boolean�ǲ�������,��ֵ��TRUE��FALSE */

typedef char VertexType; /* ��������Ӧ���û����� */
typedef int EdgeType; /* ���ϵ�Ȩֵ����Ӧ���û����� */

/* �ڽӾ���ṹ */
typedef struct
{
	VertexType vexs[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

/* �ڽӱ�ṹ****************** */
typedef struct EdgeNode {
	int adjvex;/* �ڽӵ���,�洢�ö����Ӧ���±� */
	int weight;/* ���ڴ洢Ȩֵ,���ڷ���ͼ���Բ���Ҫ */
	struct EdgeNode* next;/* ����,ָ����һ���ڽӵ� */
}EdgeNode;

/*�����Ĺ���*/
typedef struct VertexNode /* ������� */
{
	int in;	/* ������� */
	char data; /* ������,�洢������Ϣ */
	EdgeNode* firstedge;/* �߱�ͷָ�� */
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numVertexes, numEdges; /* ͼ�е�ǰ�������ͱ��� */
}graphAdjList, * GraphAdjList;

/* �õ��Ķ��нṹ�뺯��********************************** */
/* ѭ�����е�˳��洢�ṹ */
typedef struct
{
	int data[MAXSIZE];
	int front;
	int rear;
}Queue;

Status InitQueue(Queue* q) {
	q->front = 0;
	q->rear = 0;
	return OK;
}

/* ������QΪ�ն���,�򷵻�TRUE,���򷵻�FALSE */
Status QueueEmpty(Queue q) {

	if (q.front == q.rear) {/* ���пյı�־ */
		return TRUE;
	}
	else {
		return FALSE;
	}
}
/*��Ӳ���,������δ��,�����Ԫ��eΪQ�µĶ�βԪ�� */
Status EnQueue(Queue* q, int e) {
	if ((q->rear + 1) % MAXSIZE == q->front) {
		return ERROR;
	}
	/*˼·�ǣ���e����Ȼ��βָ����ƶ�*/
	q->data[q->rear] = e;
	q->rear = (q->rear + 1) % MAXSIZE;
	return OK;
}
/* �����в���,��ɾ��Q�ж�ͷԪ��,��e������ֵ */
Status DeQueue(Queue* q, int* e) {
	if (q->front == q->rear) {
		return ERROR;
	}
	/*ɾ��Q�ж�ͷԪ��*/
	*e = q->data[q->front];
	q->front = (q->front + 1) % MAXSIZE;
	return OK;
}

void CreateMGraph(MGraph* G) {
	int i, j;
	G->numEdges = 15;
	G->numVertexes = 9;

	/* ���붥����Ϣ,��������� */
	G->vexs[0] = 'A';
	G->vexs[1] = 'B';
	G->vexs[2] = 'C';
	G->vexs[3] = 'D';
	G->vexs[4] = 'E';
	G->vexs[5] = 'F';
	G->vexs[6] = 'G';
	G->vexs[7] = 'H';
	G->vexs[8] = 'I';

	for (i = 0; i < G->numVertexes; i++)/* ��ʼ��ͼ */
	{
		for (j = 0; j < G->numVertexes; j++)
		{
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

	for (i = 0; i < G->numVertexes; i++)
	{
		for (j = i; j < G->numVertexes; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}

}

/* �����ڽӾ��󹹽��ڽӱ� */
void CreateALGraph(MGraph G, GraphAdjList* GL)
{
	int i, j;
	EdgeNode* e;

	*GL = (GraphAdjList)malloc(sizeof(graphAdjList));

	(*GL)->numVertexes = G.numVertexes;
	(*GL)->numEdges = G.numEdges;
	for (i = 0; i < G.numVertexes; i++) /* ���붥����Ϣ,��������� */
	{
		(*GL)->adjList[i].in = 0;
		(*GL)->adjList[i].data = G.vexs[i];
		(*GL)->adjList[i].firstedge = NULL; 	/* ���߱���Ϊ�ձ� */
	}

	for (i = 0; i < G.numVertexes; i++) /* �����߱� */
	{
		for (j = G.numVertexes - 1; j >= 0; j--)
		{
			if (G.arc[i][j] == 1)
			{
				e = (EdgeNode*)malloc(sizeof(EdgeNode));

				//����6��������ֻ��Ϊ����ͼ���е�206ҳͼƥ�䣬�����ɵĶ��з�������ͼʾ��
				//ʵ�ʹ�������������ֻ����⵱ǰ���ǹ���һ��ͼ�ṹ���ڽӱ���
				if (i == 1 && j == 8)
					e->adjvex = 6;
				else if (i == 1 && j == 6)
					e->adjvex = 8;
				else
					e->adjvex = j;					/* �ڽ����Ϊj */

				//��������������
				//e->adjvex=j;					/* �ڽ����Ϊj */   

				e->next = (*GL)->adjList[i].firstedge;	/* ����ǰ�����ϵ�ָ��Ľ��ָ�븳ֵ��e */
				(*GL)->adjList[i].firstedge = e;		/* ����ǰ�����ָ��ָ��e */
				(*GL)->adjList[j].in++;

			}
		}
	}
}

Boolean visited[MAXSIZE];
/* �ڽӱ��������ȵݹ��㷨 */
void DFS(GraphAdjList GL, int i) {
	EdgeNode* p;
	visited[i] = TRUE;
	cout << GL->adjList[i].data << endl;
	p = GL->adjList[i].firstedge;
	while (p) {
		if (!visited[p->adjvex]) {
			DFS(GL, p->adjvex);
		}
		p = p->next;
	}
}

/* �ڽӱ����ȱ������� */
void DFSTraverse(GraphAdjList GL) {
	int i;
	for (i = 0; i < GL->numVertexes; i++) {
		visited[i] = FALSE;
	}
	for (i = 0; i < GL->numVertexes; i++) {
		if (!visited[i]) {
			DFS(GL, i);
		}
	}
}
/* �ڽӱ�Ĺ�ȱ����㷨 */
void BFSTraverse(GraphAdjList GL) {
	int i;
	EdgeNode* p;
	Queue q;
	for (i = 0; i < GL->numVertexes; i++) {
		visited[i] = FALSE;
	}
	InitQueue(&q);
	for (i = 0; i < GL->numVertexes; i++) {
		if (!visited[i]) {
			visited[i] = TRUE;
			cout << GL->adjList[i].data << endl;
			EnQueue(&q, i);
			while (!QueueEmpty(q)) {
				DeQueue(&q, &i);
				p = GL->adjList[i].firstedge;
				while (p) {
					if (!visited[p->adjvex]) {
						visited[p->adjvex] = TRUE;
						cout << GL->adjList[p->adjvex].data << endl;
						EnQueue(&q, p->adjvex);

					}
					p = p->next;
				}
			}
		}
	}
}

int main() {

	MGraph G;
	GraphAdjList GL;
	CreateMGraph(&G);
	CreateALGraph(G, &GL);
	cout << "\n��ȱ���:" << endl;
	//printf("\n��ȱ���:");
	DFSTraverse(GL);
	cout << "\n��ȱ���:" << endl;
	//printf("\n��ȱ���:");
	BFSTraverse(GL);
	return 0;

}
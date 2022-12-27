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

#define MAXSIZE 9 /* 存储空间初始分配量 */
#define MAXEDGE 15
#define MAXVEX 9

typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码,如OK等 */
typedef int Boolean; /* Boolean是布尔类型,其值是TRUE或FALSE */

typedef char VertexType; /* 顶点类型应由用户定义 */
typedef int EdgeType; /* 边上的权值类型应由用户定义 */

/* 邻接矩阵结构 */
typedef struct
{
	VertexType vexs[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

/* 邻接表结构****************** */
typedef struct EdgeNode {
	int adjvex;/* 邻接点域,存储该顶点对应的下标 */
	int weight;/* 用于存储权值,对于非网图可以不需要 */
	struct EdgeNode* next;/* 链域,指向下一个邻接点 */
}EdgeNode;

/*顶点表的构建*/
typedef struct VertexNode /* 顶点表结点 */
{
	int in;	/* 顶点入度 */
	char data; /* 顶点域,存储顶点信息 */
	EdgeNode* firstedge;/* 边表头指针 */
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numVertexes, numEdges; /* 图中当前顶点数和边数 */
}graphAdjList, * GraphAdjList;

/* 用到的队列结构与函数********************************** */
/* 循环队列的顺序存储结构 */
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

/* 若队列Q为空队列,则返回TRUE,否则返回FALSE */
Status QueueEmpty(Queue q) {

	if (q.front == q.rear) {/* 队列空的标志 */
		return TRUE;
	}
	else {
		return FALSE;
	}
}
/*入队操作,若队列未满,则插入元素e为Q新的队尾元素 */
Status EnQueue(Queue* q, int e) {
	if ((q->rear + 1) % MAXSIZE == q->front) {
		return ERROR;
	}
	/*思路是：将e插入然后尾指针后移动*/
	q->data[q->rear] = e;
	q->rear = (q->rear + 1) % MAXSIZE;
	return OK;
}
/* 若队列不空,则删除Q中队头元素,用e返回其值 */
Status DeQueue(Queue* q, int* e) {
	if (q->front == q->rear) {
		return ERROR;
	}
	/*删除Q中队头元素*/
	*e = q->data[q->front];
	q->front = (q->front + 1) % MAXSIZE;
	return OK;
}

void CreateMGraph(MGraph* G) {
	int i, j;
	G->numEdges = 15;
	G->numVertexes = 9;

	/* 读入顶点信息,建立顶点表 */
	G->vexs[0] = 'A';
	G->vexs[1] = 'B';
	G->vexs[2] = 'C';
	G->vexs[3] = 'D';
	G->vexs[4] = 'E';
	G->vexs[5] = 'F';
	G->vexs[6] = 'G';
	G->vexs[7] = 'H';
	G->vexs[8] = 'I';

	for (i = 0; i < G->numVertexes; i++)/* 初始化图 */
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

/* 利用邻接矩阵构建邻接表 */
void CreateALGraph(MGraph G, GraphAdjList* GL)
{
	int i, j;
	EdgeNode* e;

	*GL = (GraphAdjList)malloc(sizeof(graphAdjList));

	(*GL)->numVertexes = G.numVertexes;
	(*GL)->numEdges = G.numEdges;
	for (i = 0; i < G.numVertexes; i++) /* 读入顶点信息,建立顶点表 */
	{
		(*GL)->adjList[i].in = 0;
		(*GL)->adjList[i].data = G.vexs[i];
		(*GL)->adjList[i].firstedge = NULL; 	/* 将边表置为空表 */
	}

	for (i = 0; i < G.numVertexes; i++) /* 建立边表 */
	{
		for (j = G.numVertexes - 1; j >= 0; j--)
		{
			if (G.arc[i][j] == 1)
			{
				e = (EdgeNode*)malloc(sizeof(EdgeNode));

				//下面6句代码仅仅只是为了与图书中的206页图匹配，让生成的队列符合书中图示。
				//实际构建无需这样，只需理解当前就是构建一个图结构的邻接表即可
				if (i == 1 && j == 8)
					e->adjvex = 6;
				else if (i == 1 && j == 6)
					e->adjvex = 8;
				else
					e->adjvex = j;					/* 邻接序号为j */

				//正常代码下如下
				//e->adjvex=j;					/* 邻接序号为j */   

				e->next = (*GL)->adjList[i].firstedge;	/* 将当前顶点上的指向的结点指针赋值给e */
				(*GL)->adjList[i].firstedge = e;		/* 将当前顶点的指针指向e */
				(*GL)->adjList[j].in++;

			}
		}
	}
}

Boolean visited[MAXSIZE];
/* 邻接表的深度优先递归算法 */
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

/* 邻接表的深度遍历操作 */
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
/* 邻接表的广度遍历算法 */
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
	cout << "\n深度遍历:" << endl;
	//printf("\n深度遍历:");
	DFSTraverse(GL);
	cout << "\n广度遍历:" << endl;
	//printf("\n广度遍历:");
	BFSTraverse(GL);
	return 0;

}
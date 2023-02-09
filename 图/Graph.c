#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//邻接矩阵

typedef char VertexType;
typedef int EdgeType;
#define MAXVEX 100
#define INFINITY 10000
#define Maxval 9

bool visited[Maxval];


typedef struct 
{
	VertexType vexs[MAXVEX];//顶点数组
	EdgeType arc[MAXVEX][MAXVEX];
	int numNodes,numEdges;
}MGraph;

//建立无向图
void Creat_MGraph(MGraph *G){
	int i,j,k,w;
	printf("输入顶点数和边数：\n");
	scanf("%d,%d",&G->numNodes,&G->numEdges);
	//判断有多少个节点
	for(i = 0;i < G->numNodes;i++){
		scanf(&G->vexs[i]);
	}
	//初始化邻接矩阵
	for(i = 0;i < G->numNodes;i++){
		for(j = 0;j < G->numNodes;j++){
			G->arc[i][j] = INFINITY;
		}
	}
	for(k = 0;k < G->numEdges;k++){
		printf("请输入边(vi,vj)所对对应的下标i，下标j和权重w\n");
		scanf("%d,%d,%d",&i,&j,&w);
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j];
	}
}


//邻接表
typedef struct EdgeNode{//边表节点
	int adjvex;
	EdgeType info;//用于存放权重，无向图可以为空
	struct EdgeNode *next;
}EdgeNode;

typedef struct VertexNode{//顶点表节点
	VertexType data;
	EdgeNode *firstedge;
}VertexNode,AdjList[MAXVEX];

typedef struct 
{
	AdjList adjlist;
	int numNodes,numEdges;
}GraphAdjList;

void Creat_AdjGraph(GraphAdjList *G){
	
	int i,j,k;
	EdgeNode *e;
	printf("输入顶点数和边数：\n");
	scanf("%d,%d",&G->numNodes,&G->numEdges);
	for(i = 0;i<G->numNodes;i++){
		scanf(&G->adjlist[i].data);
		G->adjlist[i].firstedge = NULL;
	}
	for(k = 0;k < G->numEdges;j++){
		printf("请输入边(vi,vj)上的顶点序号：\n");
		scanf("%d,%d",&i,&j);
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->adjvex = j;
		e->next = G->adjlist[i].firstedge;
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->adjvex = i;
		e->next = G->adjlist[j].firstedge;
		G->adjlist[j].firstedge = e;
		
	}
}


//DFS深度优先遍历



#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
//一本书的结构包含：书名、价格、剩余数量
struct bookInfo
{
	char name[100];
	float price;
	int num;
};
//单链表的结构设计
struct Node
{
	struct bookInfo data;
	struct Node *next;
};
//结构体指针的初始化
struct Node *list = NULL;

//初始化头结点
struct Node *creatFirstHead(){
	struct Node *headNode = (struct Node*)malloc(sizeof(struct Node));
	if(headNode == NULL){
		return;
	}
	headNode->next = NULL;
	return headNode;
};

//新建结点
struct Node* creatNode(struct bookInfo data){
	
	//申请内存空间
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	if(newNode == NULL) return;
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
};

void insertBook(struct Node *headNode,struct bookInfo data){
	
	//创建一个新的节点
	struct Node *newNode = creatNode(data);
	//头插法插入
	newNode->next = headNode->next;
	headNode->next = newNode;
}

void readInfo(char *filename,struct Node *HeadNode){
	//打开文件
	FILE *fp = fopen(filename,"r");
	if(fp == NULL){
		fp = fopen(filename,"w");
		return;
	}
	//读取
	struct bookInfo temp;
	//易错点就是scanf前面读取不加&
	while(fscanf(fp,"%s %f %d\n",temp.name,&temp.price,&temp.price) != EOF){
		insertBook(list,temp);
	}
	
	//关闭
	fclose(fp);
	
	
}

void saveInfo(char *filename,struct Node *HeadNode){
	//打开文件
	FILE *fp = fopen(filename,"w");
	if(fp == NULL){
		return;
	}
	//写入文件
	struct Node *move = HeadNode->next;
	while(move!=NULL){
		fprintf(fp,"%s %.1f %d\n",move->data.name,move->data.price,move->data.num);
		move = move->next;
	}
	//关闭文件
	fclose(fp);
	
}

void showInfo(struct Node *headNode){
	struct Node *move = headNode->next;
	while(move != NULL){
		printf("%s %.1f %d\n",move->data.name,move->data.price,move->data.num);
		move = move->next;
	}
}

void deleteInfo(struct Node *headNode,char *name){
	
	struct Node *move = headNode->next;
	struct Node *prev = headNode;
	while(move != NULL && strcmp(move->data.name,name)){
		//TODO
		prev = move;
		move = move->next;
	}
	if(move == NULL){
		return;
	}
	else{
		printf("删除成功！\n");
		prev->next = move->next;
		free(move);
		move = NULL;
	}
	
}

void sortInfo(struct Node *headNode){

	//链表冒泡排序的新思路
	//节点位置不动，单纯交换节点的值
	for(struct Node *first = headNode->next;first != NULL;first = first->next){
		for(struct Node* second = headNode->next; second != NULL; second = second->next){
			if(second->next != NULL){
				if(second->data.num > second->next->data.num){
					int temp = second->data.num;
					second->data.num = second->next->data.num;
					second->next->data.num = temp;
				}
			}
		}
	}
	struct Node *point = headNode->next;
	while(point != NULL){
		printf("%s %.1f %d\n",point->data.name,point->data.price,point->data.num);
		point = point->next;
	}
}

struct Node* findInfo(struct Node *headNode,char *name){
	
	struct Node *move = headNode->next;
	while(move != NULL && strcmp(move->data.name,name)){
		
		move = move->next;
	}
	return move;
}



//按钮时间
void buttonEvent(){
	
	int key = 0;
	//初始化一个图书结构体方便后序操作
	struct bookInfo temp;
	struct Node *result;
	scanf("%d",&key);
	//Switch案例选取
	switch (key) {
	case 0:
		printf("【录入】\n");
		printf("请输入书籍的信息：名字、价格、数量\n");
		//bookInfo结构体
		//细节：这里scanf可以不加&的原因是结构体中name[100]
		//本身就是一个数组，数组传参会自动出入地址！
		scanf("%s%f%d",temp.name,&temp.price,&temp.num);
		//对float进行格式化输出
		//printf("%s,%.2f,%d\n",temp.name,temp.price,temp.num);
		//--------------------------------------------------------------------------
		//链表的作用
		//对文件的增删改查过于麻烦，所以建立单链表进行操作，最后总的操作完在覆盖文件
		//-------------------------------------------
		//同步到链表中
		insertBook(list,temp);
		//同步到文件中
		saveInfo("book.txt",list);
		
		break;
	case 1:
		printf("【速览】\n");
		showInfo(list);
		break;
	case 2:
		printf("【借阅】\n");
		printf("借阅的书名是：\n");
		scanf("%s",temp.name);
		result = findInfo(list,temp.name);
		if(result == NULL){
			printf("未找到书名，无法借阅\n");
		}
		else{
			//printf("书的相关信息为：\n");
			//printf("%s %.1f %d\n",result->data.name,result->data.price,result->data.num);
			if(result->data.num > 0){
				result->data.num--;
				printf("书籍借阅成功！");
				printf("书籍剩余数量为：%d\n",result->data.num);
				saveInfo("book.txt",list);
			}
			else{
				printf("抱歉，当前本书没有库存无法借阅！^_^");
				
			}
		}
		break;
	case 3:
		printf("【归还】\n");
		printf("归还的书名是：\n");
		scanf("%s",temp.name);
		result = findInfo(list,temp.name);
		if(result == NULL){
			printf("未找到书名，无法归还^_^\n");
		}
		else{
			result->data.num++;
			printf("书籍归还成功！^_^");
			printf("书籍剩余数量为：%d\n",result->data.num);
			saveInfo("book.txt",list);
		}
		break;
	case 4:
		printf("【查找】\n");
		printf("查询的书名是：\n");
		scanf("%s",temp.name);
		result = findInfo(list,temp.name);
		if(result == NULL){
			printf("未找到文件^_^\n");
		}
		else{
			printf("书的相关信息为：\n");
			printf("%s %.1f %d\n",result->data.name,result->data.price,result->data.num);
		}
		break;
	case 5:
		printf("【删除】\n");
		printf("删除的书名是：\n");
		scanf("%s",temp.name);
		//result = findInfo(list,temp.name);
		deleteInfo(list,temp.name);
		saveInfo("book.txt",list);
		break;
		
	case 6:
		printf("【排序】\n");
		printf("按库存数量的排序结果为：\n");
		sortInfo(list);
		saveInfo("book.txt",list);
		break;
		
	case 7:
		printf("【退出】\n");
		exit(0);
		break;
	
	default:
		break;
	}
	
}

//创建功能选项卡
void menu(){
	
	printf("\n-------------------------------------\n");
	printf("+欢迎登录桂淼图书借阅系统\n");
	printf("+0.录入书籍\n");
	printf("+1.速览书籍\n");
	printf("+2.借阅书籍\n");
	printf("+3.归还书籍\n");
	printf("+4.查找书籍\n");
	printf("+5.删除书籍\n");
	printf("+6.排序书籍\n");
	printf("+7.退出系统\n");
	printf("-------------------------------------\n");
	printf("请输入0~7:\n");
}

int main(){
	//每次项目启动时初始化头指针
	list = creatFirstHead();
	//读取原来文件的数据
	readInfo("book.txt",list);
	//
	while(1){
		menu();
		buttonEvent();
		system("pause");
		system("cls");
	}
	
	
}

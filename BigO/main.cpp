#include<stdio.h>
//养成增量编写的习惯
//define全局变量后面不加分号->宏
#define InitSize 100
#define Maxsize 50

//定义一个任意类型的变量
typedef int ElemType;//顺序表中元素的类型

//静态数组的创建
typedef struct {
	ElemType data[Maxsize];//定义的数组用来存取元素
	int length;//当前顺序表中有多少个元素
}SeqList;


//i代表的是插入位置，从1开始，e要插入的元素
bool ListInster(SeqList& L, int i, ElemType e) {

	//base case
	if (i < 1 || i > L.length + 1) {
		return false;
	}
	//超出空间了
	if (L.length > Maxsize) {
		return false;
	}
	//因为插入之后扩容，j必须等于length;j = L.length-1会读不出末尾元素。
	for (int j = L.length; j >= i; j--) {
		//i后面的所有元素先后移动
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;//从数组下标与索引之间的关系
	L.length += 1;
	return true;

}

//注意删除和插入是ElemType参数的取值规范
//插入时直接插入一个新值无需传入地址ElemType e；而删除时必须传入地址参数ElemType &e
bool ListDelete(SeqList& L, int i, ElemType &e) {
	//base case
	if (i < 1 || i > L.length + 1) {
		return false;
	}
	if (L.length == 0) {
		return false;
	}
	e = L.data[i - 1];//获取相应的元素，赋值给e
	//向前移动元素
	for (int j = i; j < L.length; j++) {
		L.data[j - 1] = L.data[j];
	}
	L.length -= 1;
	return true;
}

//查找时只需要传入值即可ElemType e
int FindElem(SeqList& L,ElemType e) {
	
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == e) {
			printf("恭喜您找到了该元素!!!!\n");
			return i + 1;
		}
	}
	printf("NO Find~\n");
	return 0;
}

//打印函数
void printList(SeqList& L) {
	for (int i = 0; i < L.length; i++) {
		printf("%d\t", L.data[i]);
	}
	printf("\n");
}

int main() {

	SeqList L;//顺序表的名称
	ElemType del;//要删除的元素
	bool ret;//查看返回值，布尔类型TRUE或者FALSE
	int n;
	printf("please input the numbers in lineartable(less than 50):\n");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &L.data[i]);
	}
	L.length = n;
	//手动对顺序表进行赋值
	//L.data[0] = 1;
	//L.data[1] = 2;
	//L.data[2] = 3;
	//L.length = 3;
	for (int i = 0; i < L.length; i++) {
		printf("%d\t", L.data[i]);
	}
	//执行插入操作
	ret = ListInster(L, 2, 5);
	if (ret) {
		printf("\n插入成功！！\n");
		printList(L);
	}
	else {
		printf("\n插入失败~~");
		//printList(L);

	}
	ret = ListDelete(L, 1, del);
	if (ret) {
		printf("\n删除成功！！\n");
		printf("删除的元素为:%d\n", del);
		printList(L);
	}
	else {
		printf("\n删除失败~~");
		//printList(L);

	}
	int m;
	printf("请输入您要查找的元素:");
	scanf_s("%d", &m);
	//FindElem(L, m);
	printf("在数组中的位置为：%d", FindElem(L, m));
	return 0;
}




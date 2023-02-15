#include<stdio.h>
#include<stdlib.h>

#define MaxSize 1000
#define TRUE 1
#define FALSE 0
typedef int Status; 
//定义线性表结构体
typedef struct{
	int r[MaxSize+1];
	int length;
}Sqlist;



void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Print_arr(int *a,int size){
	
	for(int i = 0;i < size;i++){
		printf("%d\t",a[i]);
	}
	printf("\n\n");
}

//定义交换函数
void swap1(Sqlist *L,int i,int j){
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

//不满足两两交换的思想
void BubbleSort0(Sqlist *L){
	
	int i,j;
	for(i = 1;i < L->length;i++){
		
		for(j = i;j < L->length;j++){
			if(L->r[i] > L->r[j]){
				swap1(L,i,j);
			}
		}
	}
}

void BubbleSort1(Sqlist *L){
	
	int i,j;
	for(i = 1;i < L->length;i++){
		
		for(j = L->length-1;j >= i;j--){//注意这里j的取值是从尾部向前循环
			if(L->r[j] > L->r[j+1]){//真正的自底向上起泡
				swap1(L,j,j+1);
			}
		}
	}
}
//冒泡排序的改进
//不发生数据交换flag的值为false,不在进行比较
void BubbleSort2(Sqlist *L){
	
	int i,j;
	Status flag = TRUE;
	for(i = 1;i < L->length;i++){
		flag = FALSE;
		for(j = L->length-1;j >= i;j--){//注意这里j的取值是从尾部向前循环
			if(L->r[j] > L->r[j+1]){//真正的自底向上起泡
				swap1(L,j,j+1);
				flag = TRUE;
			}
		}
	}
}

//简单选择排序
void SelectSort(Sqlist *L){
	
	int i,j,min;
	for(i = 1;i<L->length;i++){
		min = i;
		for(j = i+1;j<=L->length;j++){
			
			if(L->r[min] > L->r[j]){
				min = j;
			}
		}
		if(i != min){
			swap1(L,i,min);
		}
	}
}
//插入排序
//开始要设置一个哨兵监视
void InsertSort(Sqlist *L){
	
	int i,j;
	for(int i = 2;i <= L->length;i++){
		
		if(L->r[i] < L->r[i - 1]){
			L->r[0] = L->r[i];
			for(j = i -1;L->r[j]>L->r[0];j--){
				L->r[j+1] = L->r[j];
			}
			L->r[j+1] = L->r[0];
		}
	}
}

//堆排序
void Heap_Sort(Sqlist *L){
	int i;
	//调整最大堆
	for(i = L->length/2;i>0;i--){
		HeapAdjust(L,i,L->length);
	}
	//
	for(i = L->length;i>1;i--){
		swap1(L,1,i);
		HeapAdjust(L,1,i-1);
	}
}

//大顶堆调整函数
void HeapAdjust(Sqlist *L,int s,int m){
	int temp,j;
	temp = L->r[s];
	for(j = 2*s;j<=m;j*=2){
		if(j<m && L->r[j]<L->r[j+1]){
			++j;
		}
		if(temp>=L->r[j]){
			break;
		}
		L->r[s] = L->r[j];
		s = j;
	}
	L->r[s] = temp;	
}



void Quick_sort(int a[],int low,int high){
	//int pivot;
	if(low < high){
		
		int pivot = Partition(a,low,high);
		Quick_sort(a,low,pivot);
		Quick_sort(a,pivot+1,high);
		
	}
}

int Partition(int a[],int low,int high){
	
	int pivotkey;
	//三选一进行数轴量的选取
	int mid = low + (high - low)/2;
	if(a[low] > a[high]){
		swap(&a[low],&a[high]);
	}
	if(a[mid] > a[high]){
		swap(&a[mid],&a[high]);
	}
	if(a[mid] > a[low]){
		swap(&a[mid],&a[low]);
	}
	pivotkey = a[0];
	while(low < high){
		
		while(low < high && a[low] <= pivotkey)
			low++;
		a[high] = a[low];
		while(low < high && a[high] >= pivotkey)
			high--;
		a[low] = a[high];
	}
	a[low] = a[0];
	return low;
}


int main(){
	
	int size;
	printf("please input the length of arr:\n");
	scanf("%d",&size);
	int nums[size];
	for(int i = 0;i < size;i++){
		scanf("%d",&nums[i]);
	}
	int array[5] = {-1,32,42,345,1};
	int length = sizeof(array)/sizeof(int);
	Quick_sort(array,0,length-1);
	Print_arr(array,length);
	return 0;

}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//冒泡排序
void bubble_sort(int arr[],int len){
    int i , j , temp;
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - 1 -i ; j++) {
            if (arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }

        }

    }

}
//选择排序
//交换两个数
void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selection_sort(int arr[],int len)
{
    int i,j;
    for(i=0;i<len-1;i++)
    {
        int min = i;
        for (j=i+1;j<len;j++)
        {
            if(arr[j]<arr[min])
            {
                min = j;
            }
        }
        swap(&arr[min],&arr[i]);
    }
}
//插入排序
void insertion_sort(int arr[],int len)
{
    int i,j,key;
    for (int i=0;i<len;i++)
    {
        key = arr[i];
        j=i-1;
        while ((j>=0)&&(arr[j]>key))
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;

    }
}
//快速排序递归法
void swap1(int *x, int *y) {
    //交换函数
    int t = *x;
    *x = *y;
    *y = t;
}
void quick_sort_recursive(int arr[],int start,int end)
{
    if(start >=end)
    {
        return;
    }
    int mid = arr[end];
    int left = start,right = end - 1;
    while (left < right){
        while (arr[left] < mid && left <right)
            left++;
        while (arr[right] >= mid && left<right)
            right--;
        swap1(&arr[left],&arr[right]);
    }
    if(arr[left] >= arr[right])
        swap1(&arr[left], &arr[end]);
    else
        left++;
    if(left)
        quick_sort_recursive(arr,start,left -1);
    quick_sort_recursive(arr,left+1,end);

}
void quick_sort(int arr[],int len)
{
    quick_sort_recursive(arr,0,len - 1);
}
//希尔排序
void shell_sort(int arr[],int len)
{
    int gap,i,j;
    int temp;
    for (gap = len>>1;gap>0;gap>>=1)
        for (i=gap;i<len;i++){
            temp = arr[i];
            for (j =i-gap;j>=0 && arr[j]>temp;j-=gap)
                arr[j+gap] = arr[j];
            arr[j+gap] = temp;
        }

}
//归并排序
void merge_sort_recursive(int arr[],int reg[],int start,int end)
{
    if(start >= end)
        return;
    int len = end-start,mid =(len >> 1)+start;
    int start1 = start,end1 = mid;
    int start2 = mid+1,end2 = end;
    merge_sort_recursive(arr,reg,start1,end1);
    merge_sort_recursive(arr,reg,start2,end2);
    int k = start;
    while (start1 <= end1 && start2 <= end2)
        reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
    while (start1 <= end1)
        reg[k++] = arr[start1++];
    while (start2 <= end2)
        reg[k++] = arr[start2++];
    for (k = start; k <= end; k++)
        arr[k] = reg[k];
}
void merge_sort(int arr[],const int len)
{
    int reg[len];
    merge_sort_recursive(arr,reg,0,len -1);
}
//归并排序
void merge1(int arr[],int lo,int mid,int li){
    int temp[100];
    for (int i = lo; i < li; i++) {
        temp[i] = arr[i];
    }
    // 数组双指针技巧，合并两个有序数组
    int i = lo,j = mid+1;
    for (int p = lo; p <= li ; ++p) {
        if(i == mid+1){
            // 左半边数组已全部被合并
            arr[p] = temp[j++];

        } else if(j == li+1){
            // 右半边数组已全部被合并
            arr[p] = temp[i++];

        }else if(temp[i] > temp[j]){
            arr[p] = temp[j++];
        } else{
            arr[p] = temp[i++];
        }

    }



}
void merge_sort1(int arr[],int lo,int li){
    if(lo == li){
        //单个元素不用排序
        return ;
    }
    int mid = lo+(li-lo)/2;
    //先对左部分排序
    merge_sort1(arr,lo,mid);
    //对右部分排序
    merge_sort1(arr,mid+1,li);
    //然后合并两个排序数组
    merge1(arr,lo,mid,li);

}


//堆排序
void max_heapify(int arr[], int start, int end) {
    // 建立父亲结点指标和子节点指标
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) { // 若子节点指标在范围内才做比較
        if (son + 1 <= end && arr[son] < arr[son + 1]) // 先比较再选择
            son++;
        if (arr[dad] > arr[son]) //如果父亲结点过大直接跳出
            return;
        else { // 否则交换父亲节点与子节点在比较
            swap(&arr[dad], &arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}
void heap_sort(int arr[], int len) {
    int i;
    // 初始化，i从最后一个父亲结点开始比较
    for (i = len / 2 - 1; i >= 0; i--)
        max_heapify(arr, i, len - 1);
    // 先将第一个元素和已排好元素前一位做交换，再重新调整，直到排序完毕
    for (i = len - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        max_heapify(arr, 0, i - 1);
    }
}
//计数排序
void print_arr(int *arr, int n) {
    int i;
    printf("%d", arr[0]);
    for (i = 1; i < n; i++)
        printf(" %d", arr[i]);
    printf("\n");
}

void counting_sort(int *ini_arr, int *sorted_arr, int n) {
    int *count_arr = (int *) malloc(sizeof(int) * 100);
    int i, j, k;
    for (k = 0; k < 100; k++)
        count_arr[k] = 0;
    for (i = 0; i < n; i++)
        count_arr[ini_arr[i]]++;
    for (k = 1; k < 100; k++)
        count_arr[k] += count_arr[k - 1];
    for (j = n; j > 0; j--)
        sorted_arr[--count_arr[ini_arr[j - 1]]] = ini_arr[j - 1];
    free(count_arr);
}


int main() {
    printf("——————————————————————————————————————");
    printf("欢迎来到小杨设计的排序器：\n");
    printf("请输入你想要排序的数组：\n");
    int size;

    //进行排序数据录入
    for(int i=0;i <= size;i++){

    }
//    int arr[ ] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9};
//    int len = (int) sizeof (arr) / sizeof (*arr);
//    //bubble_sort(arr,len);
//    heap_sort(arr,len);
//    int i;
//    for (int i = 0; i < len; i++) {
//        printf("%d,",arr[i]);
//
//    }
//    //printf("Hello, World!\n");
//    return 0;

}

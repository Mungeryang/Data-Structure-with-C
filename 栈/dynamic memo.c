#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//动态内存申请必须引入stdlib库函数

int main() {
	//程序是放在瓷盘上的有序指集合
	//程序启动起来才叫进程
	//进程需要占用内存->进程地址空间
	//地址空间分为两部分：堆空间、栈空间
	//栈是自动分配，堆需要自己申请->图书馆申请
	int i = 20;
	char *p;
	scanf("%d", &i);//输入要申请的空间大小
	p = (char*)malloc(i);//动态内存申请
	strcpy(p, "malloc success");
	//gets(p);
	puts(p);
	free(p);//free发生偏移时必须使用malloc申请时返回时指针时，不能进行任何偏移
	p = NULL;//如果不把P置为NULL；那么P就是野指针。
	printf("free success\n");
	return 0;
}
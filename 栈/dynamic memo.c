#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//��̬�ڴ������������stdlib�⺯��

int main() {
	//�����Ƿ��ڴ����ϵ�����ָ����
	//�������������Žн���
	//������Ҫռ���ڴ�->���̵�ַ�ռ�
	//��ַ�ռ��Ϊ�����֣��ѿռ䡢ջ�ռ�
	//ջ���Զ����䣬����Ҫ�Լ�����->ͼ�������
	int i = 20;
	char *p;
	scanf("%d", &i);//����Ҫ����Ŀռ��С
	p = (char*)malloc(i);//��̬�ڴ�����
	strcpy(p, "malloc success");
	//gets(p);
	puts(p);
	free(p);//free����ƫ��ʱ����ʹ��malloc����ʱ����ʱָ��ʱ�����ܽ����κ�ƫ��
	p = NULL;//�������P��ΪNULL����ôP����Ұָ�롣
	printf("free success\n");
	return 0;
}
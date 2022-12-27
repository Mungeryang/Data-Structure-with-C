#include<stdio.h>
//����������д��ϰ��
//defineȫ�ֱ������治�ӷֺ�->��
#define InitSize 100
#define Maxsize 50

//����һ���������͵ı���
typedef int ElemType;//˳�����Ԫ�ص�����

//��̬����Ĵ���
typedef struct {
	ElemType data[Maxsize];//���������������ȡԪ��
	int length;//��ǰ˳������ж��ٸ�Ԫ��
}SeqList;


//i������ǲ���λ�ã���1��ʼ��eҪ�����Ԫ��
bool ListInster(SeqList& L, int i, ElemType e) {

	//base case
	if (i < 1 || i > L.length + 1) {
		return false;
	}
	//�����ռ���
	if (L.length > Maxsize) {
		return false;
	}
	//��Ϊ����֮�����ݣ�j�������length;j = L.length-1�������ĩβԪ�ء�
	for (int j = L.length; j >= i; j--) {
		//i���������Ԫ���Ⱥ��ƶ�
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;//�������±�������֮��Ĺ�ϵ
	L.length += 1;
	return true;

}

//ע��ɾ���Ͳ�����ElemType������ȡֵ�淶
//����ʱֱ�Ӳ���һ����ֵ���贫���ַElemType e����ɾ��ʱ���봫���ַ����ElemType &e
bool ListDelete(SeqList& L, int i, ElemType &e) {
	//base case
	if (i < 1 || i > L.length + 1) {
		return false;
	}
	if (L.length == 0) {
		return false;
	}
	e = L.data[i - 1];//��ȡ��Ӧ��Ԫ�أ���ֵ��e
	//��ǰ�ƶ�Ԫ��
	for (int j = i; j < L.length; j++) {
		L.data[j - 1] = L.data[j];
	}
	L.length -= 1;
	return true;
}

//����ʱֻ��Ҫ����ֵ����ElemType e
int FindElem(SeqList& L,ElemType e) {
	
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == e) {
			printf("��ϲ���ҵ��˸�Ԫ��!!!!\n");
			return i + 1;
		}
	}
	printf("NO Find~\n");
	return 0;
}

//��ӡ����
void printList(SeqList& L) {
	for (int i = 0; i < L.length; i++) {
		printf("%d\t", L.data[i]);
	}
	printf("\n");
}

int main() {

	SeqList L;//˳��������
	ElemType del;//Ҫɾ����Ԫ��
	bool ret;//�鿴����ֵ����������TRUE����FALSE
	int n;
	printf("please input the numbers in lineartable(less than 50):\n");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &L.data[i]);
	}
	L.length = n;
	//�ֶ���˳�����и�ֵ
	//L.data[0] = 1;
	//L.data[1] = 2;
	//L.data[2] = 3;
	//L.length = 3;
	for (int i = 0; i < L.length; i++) {
		printf("%d\t", L.data[i]);
	}
	//ִ�в������
	ret = ListInster(L, 2, 5);
	if (ret) {
		printf("\n����ɹ�����\n");
		printList(L);
	}
	else {
		printf("\n����ʧ��~~");
		//printList(L);

	}
	ret = ListDelete(L, 1, del);
	if (ret) {
		printf("\nɾ���ɹ�����\n");
		printf("ɾ����Ԫ��Ϊ:%d\n", del);
		printList(L);
	}
	else {
		printf("\nɾ��ʧ��~~");
		//printList(L);

	}
	int m;
	printf("��������Ҫ���ҵ�Ԫ��:");
	scanf_s("%d", &m);
	//FindElem(L, m);
	printf("�������е�λ��Ϊ��%d", FindElem(L, m));
	return 0;
}




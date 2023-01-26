#include<stdio.h>
#include<stdlib.h>
//�����������Ľ���
//��������������������ֵ��С��root->val,������������ֵ������root->val
//�ݹ���ú���������Ҳ�Ƕ���������

typedef int Elemtype;

//���Խṹ�Ĵ���
typedef struct BSTNode {

	Elemtype root;
	struct BSTNode* left;
	struct BSTNode* right;
}BSTNode,*BiTree;

//���뺯��
int Insert_BST(BiTree& T, Elemtype k) {

	//base case���ڵ����
	if (T == NULL) {
		//ΪT�����µĵ�ַ�ռ�
		T = (BiTree)malloc(sizeof(BSTNode));
		T->root = k;
		T->left = T->right = NULL;
		return 1;
	}
	else if (T->root == k) {
		//����ͬ��Ԫ�ز��ܲ���
		return 0;
	}
	//�ݹ�����µĽڵ�
	else if (T->root < k) {//������C++������
		return Insert_BST(T->right, k);//����������ɺ����ӻ�͸��ڵ��Զ���������
	}
	else if (T->root > k) {
		return Insert_BST(T->left, k);
	}
}

//��������������
void Creat_BST(BiTree &T,Elemtype arr[],int n) {
	T = NULL;
	int i = 0;
	while (i < n) {
		Insert_BST(T, arr[i]);
		i++;
	}
}

//�������
void InOrder(BiTree p) {

	if (p != NULL) {
		InOrder(p->left);
		//putchar(p->root);
		printf("%d\t", p->root);
		InOrder(p->right);
	}

}

BSTNode* BST_Search(BiTree T, Elemtype k, BiTree& p) {

	p = NULL;
	while (T != NULL && k != T->root) {

		p == T;
		if (k < T->root) {
			T = T->right;
		}
		else {
			T = T->left;
		}
		return T;

	}


}


//������
int main() {

	BiTree root = NULL;//����
	Elemtype arr[] = { 5,2,8,0,10,7,18,20,30,12,15,1 };
	BiTree search;
	BiTree parent;
	Creat_BST(root, arr, 12);
	printf("the sorted of the result is:\n");
	InOrder(root);
	printf("\n");
	search = BST_Search(root, 464, parent);
	if (search) {
		printf("���ڸýڵ㣬ֵΪ=%d\n", search->root);
	}
	else {
		printf("�����ڸýڵ�\n");
	}
	return 0;
}
#include<stdio.h>
#include<stdlib.h>
//二叉排序树的建立
//建立规则：所有左子树的值都小于root->val,所有右子树的值都大于root->val
//递归调用后，左右子树也是二叉排序树

typedef int Elemtype;

//属性结构的创建
typedef struct BSTNode {

	Elemtype root;
	struct BSTNode* left;
	struct BSTNode* right;
}BSTNode,*BiTree;

//插入函数
int Insert_BST(BiTree& T, Elemtype k) {

	//base case根节点操作
	if (T == NULL) {
		//为T申请新的地址空间
		T = (BiTree)malloc(sizeof(BSTNode));
		T->root = k;
		T->left = T->right = NULL;
		return 1;
	}
	else if (T->root == k) {
		//有相同的元素不能插入
		return 0;
	}
	//递归插入新的节点
	else if (T->root < k) {//设置了C++的引用
		return Insert_BST(T->right, k);//函数调用完成后，左孩子会和父节点自动关联起来
	}
	else if (T->root > k) {
		return Insert_BST(T->left, k);
	}
}

//创建二叉排序树
void Creat_BST(BiTree &T,Elemtype arr[],int n) {
	T = NULL;
	int i = 0;
	while (i < n) {
		Insert_BST(T, arr[i]);
		i++;
	}
}

//中序遍历
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


//主函数
int main() {

	BiTree root = NULL;//树根
	Elemtype arr[] = { 5,2,8,0,10,7,18,20,30,12,15,1 };
	BiTree search;
	BiTree parent;
	Creat_BST(root, arr, 12);
	printf("the sorted of the result is:\n");
	InOrder(root);
	printf("\n");
	search = BST_Search(root, 464, parent);
	if (search) {
		printf("存在该节点，值为=%d\n", search->root);
	}
	else {
		printf("不存在该节点\n");
	}
	return 0;
}
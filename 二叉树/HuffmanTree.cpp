#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include "Status.h"

using namespace std;

typedef struct
{
    unsigned int weight;
    unsigned int parent, lchild, rchild;

} HfNode, *HuffmanTree;

typedef char **HuffmanCode; //动态分配数组存储哈夫曼数组表

void select(HuffmanTree *T, int n, int s1, int s2);

void HuffmanCodeing(HuffmanTree &T, HuffmanCode &HC, int *w, int n)
{
    // w存放n个字符的权值，构造哈夫曼树HT，求出n个字符的哈夫曼编码
    if (n <= 1)
    {
        return;
    }
    m = n * 2 - 1;
    HT = (HuffmanTree)malloc(sizeof(HfNode) * (m + 1));
    for (p = HT, i = 1; i <= n; ++i, ++p, ++w)
    {
        *p = {*w, 0, 0, 0};
    }
    for (; i <= m; ++i, ++p)
    {
        *p = {0, 0, 0, 0};
    }
    for (int i = n + 1; i <= m; ++i)
    {
        //在HT中选择parent为0且权重最小的两个节点，其序号分别为s1,s2
        select(HT, i - 1, s1, s2);
        HT[s1].parent = i, HT[s2].parent = i;
        HT[i].lchild = s1, HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
    //从叶子节点逆向求编码
    HC = (HuffmanCode)malloc((n + 1) * sizeof(char *));
    cd = (char *)malloc(n * sizeof(char));
    cd[n - 1] = "\0";
    for (int i = 1; i <= n; i++)
    {
        int start = n - 1;
        for (char c = i, char f = HT[i].parent; f != 0; c = f, f = HT[f].parent)
        {
            if (HT[f].lchild == c)
                cd[--start] = "0";
            else
                cd[--start] = "1";
        }
        HC[i] = (char *)malloc((n - start) * sizeof(char));
        strcpy(HC[i], &cd[start]);
    }
    free(cd);
}

int main()
{
    // printf("HuffmanTree.cpp!");
    HuffmanTree T;
    char w[5] = {2, 1, 3, 4, 6};
    HuffmanCode HC;
    HuffmanCodeing(&T, &HC, w, 5);
    cout << "HuffmanTree!" << endl;
    system("pause");
    return 0;
}
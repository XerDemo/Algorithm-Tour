#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100                                 // 最大存储节点数

/**
 *  哈夫曼树是一种带权路径长度最小的二叉树，也成为最优二叉树（没有度为1的节点）
 *      n1 = 0
 *      n0 = n2 + 1
 *      （总节点数）n0 + n1 + n2 = 2n0 - 1
 *
 *  此处已知权值w = {5， 6， 2， 9， 7}
 *     可知叶子节点数为5 总节点数：2*5-1 = 9
 *
 */

typedef struct{
    int weight;                                     // 权值
    int leftChild;                                  // 左孩子
    int rightChild;                                 // 右孩子
    int parent;                                     // 父亲
}huffmanNode;

void createHuffmanTree(huffmanNode * pArr, int n0);                          // 创建哈夫曼树
void showHuffmanTree(huffmanNode * pArr, int n0);                            // 打印哈夫曼树
void selectMin(huffmanNode * pArr, int index, int * index1, int * index2);   // 选择最小值和次小值下标


int main(void)
{
    huffmanNode arr[MAXSIZE];
    int n0;
    printf("请输入叶子节点个数：");
    scanf("%d", &n0);
    createHuffmanTree(arr, n0);


    return 0;
}

void createHuffmanTree(huffmanNode * pArr, int n0)
{
    int i;
    int val,index1,index2;
    // 初始化
    for (i = 0; i < 2 * n0 - 1; ++i)
    {
        pArr[i].weight = 0;
        pArr[i].leftChild = -1;
        pArr[i].rightChild = -1;
        pArr[i].parent = -1;
    }
    // 输入权值
    printf("请%d个输入权值：", n0);
    for (i = 0; i < n0; ++i)
    {
        scanf("%d", &val);
        pArr[i].weight = val;
    }
    // 打印数组内容
    showHuffmanTree(pArr, n0);

    // 创建哈夫曼树
    for (i = n0; i < 2 * n0 - 1; ++i)
    {
        printf("--------------------------\n");
        // 选择两个权值最小的数 的下标
        selectMin(pArr, i-1, &index1, &index2);
        pArr[i].weight = pArr[index1].weight + pArr[index2].weight;
        pArr[i].leftChild = index1;
        pArr[i].rightChild = index2;
        pArr[index1].parent = i;
        pArr[index2].parent = i;

        showHuffmanTree(pArr, n0);
    }

}


void showHuffmanTree(huffmanNode * pArr, int n0)
{
    int i;
    printf("哈夫曼树如下：\n");
    printf("index  weight  leftChild  rightChild  parent\n");
    for (i = 0; i < 2 * n0 - 1; ++i)
    {
        printf("  %d\t %d\t  %d\t    %d\t       %d\t\n", i, pArr[i].weight, pArr[i].leftChild, pArr[i].rightChild, pArr[i].parent);
    }
}

// 选择最小值和次下值
void selectMin(huffmanNode * pArr, int index, int * index1, int * index2)
{

    int i = 0, j = 0;
    // 如果当前索引已被选过 i++
    while (pArr[i].parent != -1)
    {
        i++;
    }
    // j是i后面一个 j<= index   如果索引为j的元素未被选过 且 j的权值比 i的权值小 更新索引i
    for (j = i + 1; j <= index; ++j)
    {
        if (pArr[j].parent==-1 && pArr[j].weight < pArr[i].weight)
        {
            i = j;
        }
    }
    *index1 = i;                            // 最小值下标

    i = 0;                                  // 将i恢复成0 计算出 次小值下标
    // 如果索引i已经被选中过 或者 次小值得索引和最小值得索引相等 i++
    while (pArr[i].parent != -1 || i == *index1)
    {
        i++;
    }
    for (j = i + 1; j <= index; ++j)
    {
        if (pArr[j].parent == -1 && pArr[j].weight < pArr[i].weight && j != *index1)
        {
            i = j;
        }
    }
    *index2 = i;                            // 次小值下标

    printf("最小值索引： %d  次小值索引：%d\n", *index1, *index2);
}

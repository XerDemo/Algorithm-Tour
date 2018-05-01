#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100                                 // ���洢�ڵ���

/**
 *  ����������һ�ִ�Ȩ·��������С�Ķ�������Ҳ��Ϊ���Ŷ�������û�ж�Ϊ1�Ľڵ㣩
 *      n1 = 0
 *      n0 = n2 + 1
 *      ���ܽڵ�����n0 + n1 + n2 = 2n0 - 1
 *
 *  �˴���֪Ȩֵw = {5�� 6�� 2�� 9�� 7}
 *     ��֪Ҷ�ӽڵ���Ϊ5 �ܽڵ�����2*5-1 = 9
 *
 */

typedef struct{
    int weight;                                     // Ȩֵ
    int leftChild;                                  // ����
    int rightChild;                                 // �Һ���
    int parent;                                     // ����
}huffmanNode;

void createHuffmanTree(huffmanNode * pArr, int n0);                          // ������������
void showHuffmanTree(huffmanNode * pArr, int n0);                            // ��ӡ��������
void selectMin(huffmanNode * pArr, int index, int * index1, int * index2);   // ѡ����Сֵ�ʹ�Сֵ�±�


int main(void)
{
    huffmanNode arr[MAXSIZE];
    int n0;
    printf("������Ҷ�ӽڵ������");
    scanf("%d", &n0);
    createHuffmanTree(arr, n0);


    return 0;
}

void createHuffmanTree(huffmanNode * pArr, int n0)
{
    int i;
    int val,index1,index2;
    // ��ʼ��
    for (i = 0; i < 2 * n0 - 1; ++i)
    {
        pArr[i].weight = 0;
        pArr[i].leftChild = -1;
        pArr[i].rightChild = -1;
        pArr[i].parent = -1;
    }
    // ����Ȩֵ
    printf("��%d������Ȩֵ��", n0);
    for (i = 0; i < n0; ++i)
    {
        scanf("%d", &val);
        pArr[i].weight = val;
    }
    // ��ӡ��������
    showHuffmanTree(pArr, n0);

    // ������������
    for (i = n0; i < 2 * n0 - 1; ++i)
    {
        printf("--------------------------\n");
        // ѡ������Ȩֵ��С���� ���±�
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
    printf("�����������£�\n");
    printf("index  weight  leftChild  rightChild  parent\n");
    for (i = 0; i < 2 * n0 - 1; ++i)
    {
        printf("  %d\t %d\t  %d\t    %d\t       %d\t\n", i, pArr[i].weight, pArr[i].leftChild, pArr[i].rightChild, pArr[i].parent);
    }
}

// ѡ����Сֵ�ʹ���ֵ
void selectMin(huffmanNode * pArr, int index, int * index1, int * index2)
{

    int i = 0, j = 0;
    // �����ǰ�����ѱ�ѡ�� i++
    while (pArr[i].parent != -1)
    {
        i++;
    }
    // j��i����һ�� j<= index   �������Ϊj��Ԫ��δ��ѡ�� �� j��Ȩֵ�� i��ȨֵС ��������i
    for (j = i + 1; j <= index; ++j)
    {
        if (pArr[j].parent==-1 && pArr[j].weight < pArr[i].weight)
        {
            i = j;
        }
    }
    *index1 = i;                            // ��Сֵ�±�

    i = 0;                                  // ��i�ָ���0 ����� ��Сֵ�±�
    // �������i�Ѿ���ѡ�й� ���� ��Сֵ����������Сֵ��������� i++
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
    *index2 = i;                            // ��Сֵ�±�

    printf("��Сֵ������ %d  ��Сֵ������%d\n", *index1, *index2);
}

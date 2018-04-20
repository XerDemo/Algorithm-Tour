#include <stdio.h>
#include <stdlib.h>

/**
 *  �õݹ��������������� �ݹ������������
 */

typedef int elemType;                       // ��int����ȡ������ ������������������

typedef struct Node{
    elemType data;                           // ����ڵ��������
    struct Node * pLChild;                   // ����ڵ����ָ��
    struct Node * pRChild;                   // ����ڵ����ָ��
}BiTNode;

BiTNode * createTree();                      // ���õݹ�ķ�ʽ����������
void preOrderTraverse(BiTNode * pT);         // �������
void inOrderTraverse(BiTNode * pT);          // �������
void postOrderTraverse(BiTNode * pT);        // �������

int main(void)
{

    BiTNode * pT = createTree();
    printf("�������: ");
    preOrderTraverse(pT);

    printf("\n�������: ");
    inOrderTraverse(pT);

    printf("\n�������: ");
    postOrderTraverse(pT);

}

// �������������˳�� �ݹ�������������
BiTNode * createTree()
{
    BiTNode * pT;
    elemType val;
    scanf("%d", &val);

    // �������0 ˵���ýڵ�Ϊ��
    if (val == 0)
    {
        pT = NULL;
    }
    else
    {
        pT = (BiTNode *) malloc(sizeof(BiTNode));
        if (!pT)
        {
            printf("malloc is failed!\n");
            exit(-1);
        }
        // �� ���� DLR  �����ҵ�˳��ݹ�����
        pT->data = val;                              // ���ɸ��ڵ�
        printf("������%d�ڵ�����ӣ�\n", pT->data);
        pT->pLChild = createTree();                // ���ɸýڵ������
        printf("������%d�ڵ���Һ��ӣ�\n", pT->data);
        pT->pRChild = createTree();                // ���ɸýڵ���Һ���

    }
    return pT;
}


void preOrderTraverse(BiTNode * pT)
{
    // ���pT ��= NULL
    if (pT)
    {
        printf(" %d ", pT->data);           // �ȱ������ڵ�
        preOrderTraverse(pT->pLChild);      // �ٱ���������
        preOrderTraverse(pT->pRChild);      // �ٱ���������
    }
}

void inOrderTraverse(BiTNode * pT)
{
    // ���pT ��= NULL
    if (pT)
    {
        inOrderTraverse(pT->pLChild);       // ����������
        printf(" %d ", pT->data);           // �������ڵ�
        inOrderTraverse(pT->pRChild);       // ����������
    }
}

void postOrderTraverse(BiTNode * pT)
{

    // ���pT ��= NULL
    if (pT)
    {
        postOrderTraverse(pT->pLChild);       // ����������
        postOrderTraverse(pT->pRChild);       // ����������
        printf(" %d ", pT->data);           // �������ڵ�
    }
}






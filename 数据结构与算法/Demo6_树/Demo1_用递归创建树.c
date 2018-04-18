#include <stdio.h>
#include <stdlib.h>
/**
 *  �õݹ��������� �ݹ������
 */

typedef struct Node{
    char data;                               // ����ڵ��������
    struct Node * pLChild;                  // ����ڵ����ָ��
    struct Node * pRChild;                  // ����ڵ����ָ��
}BiTNode;

void createBiTree(BiTNode ** ppT);          // ���õݹ�ķ�ʽ����������   ˫��ָ��
void preOrderTraverse(BiTNode * pT);        // �������
void inOrderTraverse(BiTNode * pT);         // �������
void postOrderTraverse(BiTNode * pT);       // �������

int main(void)
{
    // Ϊʲô���� BiTNode * pT = createBiTree();
    BiTNode * pT = NULL;
    createBiTree(&pT);

    printf("�������: ");
    preOrderTraverse(pT);

    printf("\n�������: ");
    inOrderTraverse(pT);

    printf("\n�������: ");
    postOrderTraverse(pT);

}

// �������� ������
void createBiTree(BiTNode **ppT)
{
    char ch;
    scanf("%c", &ch);

    // �������'#' ˵���ýڵ�Ϊ��
    if (ch == '#')
    {
        *ppT = NULL;
    }
    else
    {
        *ppT = (BiTNode *) malloc(sizeof(BiTNode));
        // *ppT->data = ch;  *����������ȼ���++ һ�� ��->С ��ʱ�൱�� *(ppT->data) = ch  ��Ȼ�ᱨ��
        (*ppT)->data = ch;                  // ���ɸ��ڵ� �� �� ��
        createBiTree(&(*ppT)->pLChild);      // ����������
        createBiTree(&(*ppT)->pRChild);      // ����������
    }
}

// ΪʲôͻȻ�ֱ���� ����ָ��
void preOrderTraverse(BiTNode * pT)
{
    // ���pT ��= NULL
    if (pT)
    {
        printf(" %c ", pT->data);           // �ȱ������ڵ�
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
        printf(" %c ", pT->data);           // �������ڵ�
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
        printf(" %c ", pT->data);           // �������ڵ�
    }
}






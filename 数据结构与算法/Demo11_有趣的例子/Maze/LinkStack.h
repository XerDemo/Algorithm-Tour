#include <stdio.h>
#include <stdlib.h>
#include "MazeData.h"

// ������ջ
typedef struct sNode {
    Node data;					 // ������ 
    struct sNode *pNext;	     // ָ���� 
} stackNode;

typedef struct {
    stackNode *pTop;			// ջ��ָ�� 
} LinkStack;

// ������ջ
LinkStack *createStack()
{
    LinkStack *pS = (LinkStack *) malloc(sizeof(LinkStack));
    if (!pS)
    {
        printf("malloc is failed!\n");
        exit(-1);
    }
    // ��ʼ�� ��ΪNULL 
    pS->pTop = NULL;
    return pS;
}

// �ж���ջ�Ƿ�Ϊ�� ��ջû���������
int isEmpty(LinkStack *pS)
{
    return NULL == pS->pTop;
}

// ��ջ
void push(LinkStack *pS, Node val)
{
    stackNode *pNew = (stackNode *) malloc(sizeof(stackNode));
    // ʡ���ж�pNew�Ƿ�Ϊ��
    pNew->data = val;
    pNew->pNext = pS->pTop;
    pS->pTop = pNew;
    // printf("(%d %d)��ջ��\n", val.rowNo, val.colNo);
}

// ��ջ
Node pop(LinkStack *pS)
{
    if (isEmpty(pS))
    {
        printf("linkStack is empty! pop is failed\n");
    } else
    {
        stackNode *pTemp = pS->pTop;         // ��һ�����pTemp��ʱ��סpS->pTop��λ��
        Node p = pTemp->data;
        pS->pTop = pTemp->pNext;
        free(pTemp);                         // ɾ��pTemp����ΪNULL
        pTemp = NULL;
        //  printf("(%d %d)��ջ��\n", p.rowNo, p.colNo);
        return p;
    }

}

// ������ջ
void traverseStack(LinkStack *pS)
{
    if (isEmpty(pS))
    {
        printf("linkStack is empty! traverseStack is failed\n");
        return;
    }
    stackNode *p = pS->pTop;
    printf("path:\n");
    while (p)
    {
        printf("< %d %d %d >\n", p->data.rowNo, p->data.colNo);
        p = p->pNext;
    }
    printf("\n");
}




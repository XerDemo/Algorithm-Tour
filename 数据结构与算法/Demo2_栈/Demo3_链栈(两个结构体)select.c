#include <stdio.h>
#include <stdlib.h>

/**
* ��ʽջ--���ϡ�����ȳ� ���Ĵ洢�ṹ --����ʵ��
* ��ջ�����һ�� �����ŵ�����  pTop ��ջ��ָ�� �൱�������ͷָ��ָ�����ͷ�ڵ�
*/


typedef struct Node
{
    int data;
    struct Node *pNext;
} StackNode;


/*
 *  ��ջ ΪʲôҪ�ýṹ������� ������ ֱ�� StackNode *pTop;   ?
 *  
 *  ��ջ ֻ��һ���ṹ��ʵ��  ����ͷ�ڵ�   Ч�����������ṹ��һ��
 *  ��� ֻ��һ���ṹʵ��    ����ͷ���   ��ôpTop��ֵҲ����ջ��ָ��(ͷָ��) ÿ��ջ���ջһ�ξ�Ҫ�޸�һ��
 */
typedef struct Stack
{
    StackNode *pTop;                                           // ջ��ָ��  ָ����ǽڵ�
} LinkStack;

void initLinkStack(LinkStack *pS);                             // ��ʼ����ʽ1����ջ�з���
LinkStack *createLinkStack();                                  // ��ʼ����ʽ2���ڶ��з���  (�˴�ѡ���ڡ��ѡ��з���)
void push(LinkStack *pS, int val);                             // ��ջ
int pop(LinkStack *pS, int *pVal);                             // ��ջ
int lengthLinkStack(LinkStack *pS);                           // �ж���ջ�� Ԫ�صĸ���
int emptyLinkStack(LinkStack *pS);                            // �ж���ջ�Ƿ�Ϊ��  �� �������������
void clearLinkStack(LinkStack *pS);                            // �����ջ
void traverse(LinkStack *pS);                                  // ����

int main(void)
{
    // ��ʼ����ʽ1�� ʹ�� ���������ķ�ʽ �ڣ�ջ��"�ڿ�"
    LinkStack S;
    initLinkStack(&S);

    // ��ʼ����ʽ2�� ʹ�� malloc  �ڣ��ѣ�  "�ڿ�"  malloc��Ҫͷ�ļ� stdlib.h
    // �ڴ�ѡ�õڶ��ַ�ʽ
    LinkStack *pS = createLinkStack();
    int val;
    printf("length is : %d\n", lengthLinkStack(pS));
    push(pS, 1);
    push(pS, 2);
    push(pS, 3);
    if (pop(pS, &val))
    {
        printf("pop is : %d\n", val);
    }
    push(pS, 4);
    traverse(pS);
    printf("length is : %d\n", lengthLinkStack(pS));

    printf("After clearLinkStack!\n");
    clearLinkStack(pS);
    printf("length is : %d\n", lengthLinkStack(pS));

    push(pS, 10);
    push(pS, 11);
    push(pS, 12);
    if (pop(pS, &val))
    {
        printf("pop is : %d\n", val);
    }
    push(pS,13);
    traverse(pS);
    printf("length is : %d\n", lengthLinkStack(pS));
    return 0;
}

void initLinkStack(LinkStack *pS)
{
    pS->pTop = NULL;
}

LinkStack *createLinkStack()
{
    LinkStack *pS = (LinkStack *) malloc(sizeof(LinkStack));
    if (!pS)
    {
        printf("malloc is failed!\n");
        exit(-1);
    }
    pS->pTop = NULL;
}

void push(LinkStack *pS, int val)
{
    StackNode *pNew = (StackNode *) malloc(sizeof(StackNode));
    // ʡ���ж� pNew�Ƿ�Ϊ��
    pNew->data = val;
    pNew->pNext = pS->pTop;
    pS->pTop = pNew;
}

int emptyLinkStack(LinkStack *pS)
{
    return NULL == pS->pTop;
}

int pop(LinkStack *pS, int *pVal)
{
    if (emptyLinkStack(pS))
    {
        printf("linkStack is empty! pop is failed!\n");
        return -1;
    } else
    {
        // ����һ����ʱ�Ľڵ�pTemp ���� pTop   ��һ��ָ��������Ҫ��ջ��ֵ  Ȼ��pTop������һλ   ɾ��pTemp
        StackNode *pTemp = pS->pTop;
        *pVal = pTemp->data;
        pS->pTop = pTemp->pNext;
        free(pTemp);             // pTemp ��ָ����ڴ汻�ͷ�(��)     ָ�����pTemp������ĵ�ַ��û�б��ͷ�(ջ)
        pTemp = NULL;            // ��Ȼʹ��free����֮��ָ�����pTemp������ĵ�ַ��û�иı䣬�����Ǿ���Ҫ���°�pTemp��ֵ��ΪNULL(������Ϊ��Ұָ�롱)
        return 1;
    }
}

int lengthLinkStack(LinkStack *pS)
{
    int i;
    StackNode *p = pS->pTop;
    while (p != NULL)
    {
        p = p->pNext;
        i++;
    }
    return i;
}

void clearLinkStack(LinkStack *pS)
{
    if (emptyLinkStack(pS))
    {
        printf("linkStack is empty! clear is failed!\n");
        return;
    } else
    {
        StackNode *p = pS->pTop;     // p��q��ǰ��
        StackNode *q = NULL;
        while (p != NULL)
        {
            q = p->pNext;
            free(p);
            p = NULL;
            p = q;
        }
        pS->pTop = NULL;
//        printf("pS->pTop is : %p\n", pS->pTop);
    }
}

void traverse(LinkStack *pS)
{
    if (emptyLinkStack(pS))
    {
        printf("linkStack is empty! traverse is failed!\n");
        return;
    }
    // ����һ����ʱ�Ľڵ����pTop ��������֮��Ͳ���ı�pTop��ֵ �ı����p
    StackNode *p = pS->pTop;
    printf("linkStack is : ");
    while (p != NULL)
    {
        printf(" %d ", p->data);
        p = p->pNext;
    }
    printf("\n");
}

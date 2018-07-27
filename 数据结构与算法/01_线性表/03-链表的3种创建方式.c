#include <stdio.h>
#include <stdlib.h>

/**
 * ��������ִ�����ʽ
 */

typedef struct Node{
    int data;                                                   // ������
    struct Node * pNext;                                        // ָ����
}LinkNode;

LinkNode * createLinkList_1();                                  // ��һ�֣� ������ͷ������ڵ�  ����ͷ��� ��ջ��
void traverse_1(LinkNode * pHead);

LinkNode * createLinkList_2();                                  // �ڶ��֣� ������β������ڵ�  ����ͷ���
void traverse_2(LinkNode * pHead);

LinkNode * createLinkList_3();                                  // �����֣� ������β������ڵ�  ��ͷ���   (��������Ĭ�϶��ǵ�����)
void traverse_3(LinkNode * pHead);

int main(void)
{
    LinkNode * pHead_1 = createLinkList_1();
    traverse_1(pHead_1);

    LinkNode * pHead_2 = createLinkList_2();
    traverse_2(pHead_2);

    LinkNode * pHead_3 = createLinkList_3();
    traverse_3(pHead_3);

    return 0;
}

// ��һ�֣� ������ͷ������ڵ�  ����ͷ��� ��ջ��
LinkNode * createLinkList_1()
{
    LinkNode * pHead = NULL;
    int x;
    printf("��������٣��ո������ ��-1������\n");
    scanf("%d", &x);
    while (-1 != x)
    {
        LinkNode * pNew = (LinkNode *) malloc(sizeof(LinkNode));
        if (!pNew)
        {
            printf("malloc is failed!\n");
            exit(-1);
        }
        pNew->data = x;
        pNew->pNext = pHead;
        pHead = pNew;
        scanf("%d", &x);
    }
    return pHead;
}

void traverse_1(LinkNode * pHead)
{
    LinkNode * p = pHead;
    printf("LinkList�� is : ");
    while (p != NULL)
    {
        printf(" %d ", p->data);
        p = p->pNext;
    }
    printf("\n");

}

// �ڶ��֣� ������β������ڵ�  ����ͷ���
LinkNode * createLinkList_2()
{
    LinkNode * pHead, *pTail;
    pHead = pTail = NULL;
    int x;
    printf("��������ڣ��ո������ ��-1������\n");
    scanf("%d", &x);
    while (-1 != x)
    {
        LinkNode * pNew = (LinkNode *)malloc(sizeof(LinkNode));
        pNew->data = x;
        pNew->pNext = NULL;
        if (pHead == NULL)
        {
            pHead = pNew;
        } else
        {
            pTail->pNext = pNew;
        }
        pTail = pNew;
        scanf("%d", &x);
    }
    return pHead;
}

void traverse_2(LinkNode * pHead)
{
    LinkNode * p = pHead;
    printf("LinkList�� is : ");
    while (p != NULL)
    {
        printf(" %d ", p->data);
        p = p->pNext;
    }
    printf("\n");
}

// �����֣� ������β������ڵ�  ��ͷ���   (��������Ĭ�϶��ǵ�����)
LinkNode * createLinkList_3()
{
    LinkNode * pHead = (LinkNode *)malloc(sizeof(LinkNode));
    LinkNode * pTail = pHead;
    pTail->pNext = NULL;
    int x;
    printf("��������ۣ��ո������ ��-1������\n");
    scanf("%d", &x);
    while (-1 != x)
    {
        LinkNode * pNew = (LinkNode * ) malloc(sizeof(LinkNode));
        pNew->data = x;
        pNew->pNext = NULL;
        pTail->pNext = pNew;
        pTail = pNew;
        scanf("%d", &x);
    }
    return pHead;
}

void traverse_3(LinkNode *pHead)
{
    LinkNode * p = pHead->pNext;
    printf("LinkList�� is : ");
    while (p!=NULL)
    {
        printf(" %d ", p->data);
        p = p->pNext;
    }
    printf("\n");
}

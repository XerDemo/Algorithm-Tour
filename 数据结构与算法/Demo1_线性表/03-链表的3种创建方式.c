#include <stdio.h>
#include <stdlib.h>

/**
 * 链表的三种创建方式
 */

typedef struct Node{
    int data;                                                   // 数据域
    struct Node * pNext;                                        // 指针域
}LinkNode;

LinkNode * createLinkList_1();                                  // 第一种： 从链表头部插入节点  不带头结点 （栈）
void traverse_1(LinkNode * pHead);

LinkNode * createLinkList_2();                                  // 第二种： 在链表尾部插入节点  不带头结点
void traverse_2(LinkNode * pHead);

LinkNode * createLinkList_3();                                  // 第三种： 在链表尾部插入节点  带头结点   (建立链表默认都是第三种)
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

// 第一种： 从链表头部插入节点  不带头结点 （栈）
LinkNode * createLinkList_1()
{
    LinkNode * pHead = NULL;
    int x;
    printf("输入链表①：空格隔开， 以-1结束：\n");
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
    printf("LinkList① is : ");
    while (p != NULL)
    {
        printf(" %d ", p->data);
        p = p->pNext;
    }
    printf("\n");

}

// 第二种： 在链表尾部插入节点  不带头结点
LinkNode * createLinkList_2()
{
    LinkNode * pHead, *pTail;
    pHead = pTail = NULL;
    int x;
    printf("输入链表②：空格隔开， 以-1结束：\n");
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
    printf("LinkList② is : ");
    while (p != NULL)
    {
        printf(" %d ", p->data);
        p = p->pNext;
    }
    printf("\n");
}

// 第三种： 在链表尾部插入节点  带头结点   (建立链表默认都是第三种)
LinkNode * createLinkList_3()
{
    LinkNode * pHead = (LinkNode *)malloc(sizeof(LinkNode));
    LinkNode * pTail = pHead;
    pTail->pNext = NULL;
    int x;
    printf("输入链表③：空格隔开， 以-1结束：\n");
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
    printf("LinkList③ is : ");
    while (p!=NULL)
    {
        printf(" %d ", p->data);
        p = p->pNext;
    }
    printf("\n");
}

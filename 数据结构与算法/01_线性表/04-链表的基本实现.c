#include <stdio.h>
#include <stdlib.h>

/**
    2018/4/6/17点34分
    链表的基本实现  带头节点
    画图整个链表的各种操作原理都很简单
    pHead 头指针   pHead-> 头结点   pHead->pNext   首节点
    插入 删除 都必须知道其前驱
    关于malloc free 参考资料： http://itopic.org/c-malloc-free.html
    测试数据： 1 2 3 4 5 -1
 */
typedef struct Node
{
    int data;                                               // 数据域
    struct Node *pNext;                                    // 指针域
} LinkNode, *LinkList;                                      // LinkNode等价于 struct Node 、 LinkList等价于 struct Node *

LinkNode *createLinkList();                                // 创建链表
void traverse(LinkNode *pHead);                            // 遍历
int emptyLinkList(LinkNode *pHead);                        // 判断链表是否为空
int lengthLinkList(LinkNode *pHead);                       // 返回链表的长度
LinkNode *findLinkList(LinkNode *pHead, int val);          // 查找元素val在链表中的位置  返回其地址 为了方便插入删除
LinkNode *searchLinkList(LinkNode *pHead, int pos);        // 查找第pos个位置 对应链表的位置 方便插入删除
int insertLinkList_1(LinkNode *pHead, int pos, int val);   // 插入  配合 searchLinkList使用
int insertLinkList_2(LinkNode *pHead, int pos, int val);   // 插入  其实就是将searchLinkList + insertLinkList_1结合
int deleteLinkList_1(LinkNode *pHead, int pos, int *pVal); // 删除  配合 searchLinkList使用
int deleteLinkList_2(LinkNode *pHead, int pos, int *pVal); // 删除  其实就是将searchLinkList + deleteLinkList_1结合
int deleteLinkList_3(LinkNode *pHead, int val);            // 删除  根据 元素的值 来删除

int main(void)
{
    int val;
    LinkNode *pHead = createLinkList();
    printf("LinkList length is : %d\n", lengthLinkList(pHead));

    insertLinkList_1(pHead, 1, 99);
    insertLinkList_2(pHead, 3, 88);
    traverse(pHead);

    if (deleteLinkList_1(pHead, 7, &val))
    {
        printf("delete: %d \n", val);
    }
    if (deleteLinkList_2(pHead, 1, &val))
    {
        printf("delete: %d \n", val);
    }
    // 这里根据 val=2 删除了 2
    deleteLinkList_3(pHead, 2);

    traverse(pHead);
    printf("LinkList length is : %d\n", lengthLinkList(pHead));
    return 0;
}

LinkNode *createLinkList()
{
    int x;                                              // 输入的数据   -1代表结束
    LinkNode *pHead = (LinkNode *) malloc(sizeof(LinkNode));
    if (!pHead)
    {
        printf("malloc is failed!\n");
        exit(-1);
    }
    LinkNode *pTail = pHead;
    pTail->pNext = NULL;

    printf("请输入链表(空格隔开，-1结束)：\n");
    scanf("%d", &x);
    while (-1 != x)
    {
        LinkNode *pNew = (LinkNode *) malloc(sizeof(LinkNode));
        // 我省略判断 pNew是否为空
        pNew->data = x;
        pNew->pNext = NULL;
        pTail->pNext = pNew;
        pTail = pNew;
        scanf("%d", &x);
    }
    return pHead;
}

int emptyLinkList(LinkNode *pHead)
{
    return pHead->pNext == NULL;
}

LinkNode *findLinkList(LinkNode *pHead, int val)
{
    LinkNode *p = pHead->pNext;                    // p指向首节点 （第一个有效数据的节点）
    while (p != NULL && val != p->data)
    {
        p = p->pNext;
    }
    // 此写法错误 当p==NULL  p->data 会报错  NULL->data 明显错误
//    if (val == p->data)
//    {
//        return p;
//    } else{
//        return NULL;
//    }
    return p;
}

// 按照给定第pos个位置 在链表中 查 对应的元素    返回 NULL 说明没找
LinkNode *searchLinkList(LinkNode *pHead, int pos)
{
    int i = 0;                                          // 这里是从i=0 头节点  i=1 首节点.......类推  为什么不从i=1开始 结合insertLinkList_1就知道了
    LinkNode *p = pHead;
    while (p != NULL && i < pos)
    {
        p = p->pNext;
        i++;
    }
    // 当进行到这一步  说明 p == NULL || i == pos
    if (pos == i)
    {
        return p;
    } else
    {
        return NULL;
    }
}

int lengthLinkList(LinkNode *pHead)
{
    int i;
    LinkNode *p = pHead->pNext;
    while (p != NULL)
    {
        i++;
        p = p->pNext;
    }
    return i;
}

int insertLinkList_1(LinkNode *pHead, int pos, int val)
{
    // 当pos = 1时 p为第0个元素也就是头节点 如果searchLinkList的i是从1开始 则明明可以插入 却返回的是NULL
    LinkNode *p = searchLinkList(pHead, pos - 1);                           // p是p第pos元素的前驱
    // 如果前驱节点的地址为空 说明 插入错误
    if (p == NULL)
    {
        printf("insertLinkList_1 is failed!\n");
        return 0;
    } else
    {
        LinkNode *pNew = (LinkNode *) malloc(sizeof(LinkNode));
        pNew->data = val;
        pNew->pNext = p->pNext;
        p->pNext = pNew;
        return 1;
    }
}

int insertLinkList_2(LinkNode *pHead, int pos, int val)
{
    int i = 0;
    LinkNode *p = pHead;                // 从头节点开始
    while (p != NULL && i < pos - 1)
    {
        p = p->pNext;
        ++i;
    }
    //退出while循环 只有两种可能 1.p==NULL  2.i >= pos-1(这里又可以两种i==pos-1，这就是我们要找的第pos-1个节点， 另外一种i>pos-1,这种情况 直接0)
    if (p == NULL || i > pos - 1)
    {
        return 0;
    } else
    {                     // pos - 1 == i   现在p 已经是pos的前驱节点
        LinkNode *pNew = (LinkNode *) malloc(sizeof(LinkNode));
        //省略判断pNew是否为空
        pNew->data = val;
        pNew->pNext = p->pNext;
        p->pNext = pNew;
        return 1;
    }
}

int deleteLinkList_1(LinkNode *pHead, int pos, int *pVal)
{
    LinkNode *p = searchLinkList(pHead, pos - 1);              // p为 第pos个元素的前驱
    if (p == NULL)
    {
        printf("deleteLinkList_1 is failed!\n");
        return 0;
    }
    LinkNode *pTemp = p->pNext;
    *pVal = pTemp->data;
    p->pNext = pTemp->pNext;
    free(pTemp);                                               // pTemp 所指向的内存被释放(堆)     指针变量pTemp本身保存的地址比没有被释放(栈)
    pTemp = NULL;                                              // 既然使用free函数之后指针变量pTemp本身保存的地址并没有改变，那我们就需要重新把pTemp的值变为NULL(否则会成为“野指针”)
    return 1;
}

int deleteLinkList_2(LinkNode *pHead, int pos, int *pVal)
{
    int i = 0;
    LinkNode *p = pHead;                   // 从头节点开始
    // 与插入这里不同的是 插入只要有头节点 就能在第一个有效位置插入 删除则不同 如果没有有效元素拿命删除
    while (p->pNext != NULL && i < pos - 1)
    {
        p = p->pNext;
        ++i;
    }
    if (p->pNext == NULL || i > pos - 1)
    {
        return 0;
    } else
    {
        LinkNode *pTemp = p->pNext;
        *pVal = pTemp->data;
        p->pNext = pTemp->pNext;
        free(pTemp);
        pTemp = NULL;
        return 1;
    }
}

int deleteLinkList_3(LinkNode *pHead, int val)
{
    LinkNode *p = pHead->pNext;           // 从首节点开始  也可以从头节点开始  那么依次改为p = pHead    p->pNext != NULL   p->pNext = NULL
    LinkNode *q = NULL;                   // 用来保存p的前驱
    while (p != NULL && val != p->data)
    {
        q = p;
        p = p->pNext;
    }
    if (p == NULL)
    {
        return -1;
    } else
    {
        q->pNext = p->pNext;
        free(p);
        p = NULL;
        return 1;
    }

}

void traverse(LinkNode *pHead)
{
    if (emptyLinkList(pHead))
    {
        printf("LinkList is empty!\n");
        return;
    }
    printf("LinkList is : ");
    LinkNode *p = pHead->pNext;
    while (p != NULL)
    {
        printf(" %d ", p->data);
        p = p->pNext;
    }
    printf("\n");
}



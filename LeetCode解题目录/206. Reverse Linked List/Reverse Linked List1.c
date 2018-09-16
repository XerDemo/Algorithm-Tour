//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct Node {
//    int data;
//    struct Node *next;
//} LinkNode;
//
//
//// 第二种： 在链表尾部插入节点  不带头结点
//LinkNode * createLinkList_2()
//{
//    LinkNode * pHead, *pTail;
//    pHead = pTail = NULL;
//    int x;
//    printf("输入链表②：空格隔开， 以-1结束：\n");
//    scanf("%d", &x);
//    while (-1 != x)
//    {
//        LinkNode * pNew = (LinkNode *)malloc(sizeof(LinkNode));
//        pNew->data = x;
//        pNew->next = NULL;
//        if (pHead == NULL)
//        {
//            pHead = pNew;
//        } else
//        {
//            pTail->next = pNew;
//        }
//        pTail = pNew;
//        scanf("%d", &x);
//    }
//    return pHead;
//}
//
//
//void traverse_2(LinkNode * pHead)
//{
//    LinkNode * p = pHead;
//    printf("LinkList② is : ");
//    while (p != NULL)
//    {
//        printf(" %d ", p->data);
//        p = p->next;
//    }
//    printf("\n");
//}
//
//LinkNode *reaverseLinkList(LinkNode *head) {
//    LinkNode *pre = NULL;
//    LinkNode *cur = head;
//    while (cur != NULL) {
//        LinkNode *next = cur->next;
//        cur->next = pre;
//        pre = cur;
//        cur = next;
//    }
//    return pre;
//}
//
//int main(void) {
//    LinkNode *head = createLinkList_2();
//    traverse_2(head);
//    traverse_2(reaverseLinkList(head));
//}
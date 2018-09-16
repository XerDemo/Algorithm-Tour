#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} LinkNode;

// ����ͷ���ĵ�����
LinkNode *createLinkList_2() {
    LinkNode *head, *tail;
    head = tail = NULL;
    int val;
    printf("input value:  ");
    scanf("%d", &val);
    while (-1 != val) {
        LinkNode *pNew = (LinkNode *) malloc(sizeof(LinkNode));
        pNew->data = val;
        pNew->next = NULL;
        if (head == NULL) {
            head = pNew;
        } else {
            tail->next = pNew;
        }
        tail = pNew;
        scanf("%d", &val);
    }
    return head;
}

// ��ӡ����
void printLinkList(LinkNode *pHead) {
    LinkNode *p = pHead;
    printf("LinkList is : ");
    while (p != NULL) {
        printf(" %d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// ��ת����
LinkNode *reaverseLinkList(LinkNode *head) {
    LinkNode *cur = head;
    LinkNode *pre = NULL;
    while (cur) {
        LinkNode *temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    return pre;
}


a
int main(void) {
    LinkNode *head = createLinkList_2();
    printLinkList(head);
    printLinkList(reaverseLinkList(head));
}
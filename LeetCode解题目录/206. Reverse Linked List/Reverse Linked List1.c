#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} LinkNode;

// ������ͷ�ڵ�ĵ����� ���� -1 ����
LinkNode *createList() {
    LinkNode *head = (LinkNode *) malloc(sizeof(LinkNode));
    LinkNode *tail = head;
    tail->next = NULL;
    int val = 0;
    printf("input value: ");
    scanf("%d", &val);
    while (val != -1) {
        LinkNode *pNew = (LinkNode *) malloc(sizeof(LinkNode));
        pNew->data = val;
        pNew->next = NULL;
        tail->next = pNew;
        tail = pNew;
        scanf("%d", &val);
    }
    return head;
}

// ��ӡ������
void printLinkList(LinkNode *head) {
    LinkNode *p = head->next;
    printf("linkList is : ");
    while (p != NULL) {
        printf("%d  ", p->data);
        p = p->next;
    }
    printf("\n");
}

// ��ת������
LinkNode *reaverseLinkList(LinkNode *head) {
    LinkNode *pre = NULL;
    LinkNode *cur = head->next;
    while (cur != NULL) {
        LinkNode *next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    head->next = pre;
	return head;
}


int main(void) {
    LinkNode *head = createList();
    printLinkList(head);
    printLinkList(reaverseLinkList(head));
}

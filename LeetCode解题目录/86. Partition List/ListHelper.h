#ifndef ALGORITHM_LISTHELPER_H
#define ALGORITHM_LISTHELPER_H
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} LinkNode;


// 不带头结点
LinkNode *createList(int arr[], int n) {
    if (n == 0) {
        return NULL;
    }

    LinkNode *head = (LinkNode *) malloc(sizeof(LinkNode));
    head->val = arr[0];
    LinkNode *curNode = head;
    int i;
    for (i = 1; i < n; ++i) {
        LinkNode *newNode = (LinkNode *) malloc(sizeof(LinkNode));
        newNode->val = arr[i];
        newNode->next = NULL;
        curNode->next = newNode;
        curNode = newNode;
    }
    return head;
}

LinkNode * printList(LinkNode * head) {
    LinkNode *curNode = head;
    printf("list is:");
    while (curNode){
        printf("%d  ", curNode->val);
        curNode = curNode->next;
    }
    printf("\n");
}
#endif //ALGORITHM_LISTHELPER_H

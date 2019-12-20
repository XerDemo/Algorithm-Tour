//
// Created by XerDemo on 2019/7/22.
//

#ifndef ALGORITHM_LINKEDLISTHELPER_H
#define ALGORITHM_LINKEDLISTHELPER_H
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int val;
    struct Node *next;
}LinkNode;

// 创建带头节点的链表
LinkNode * createLinkList_dummy(int * data, int n){
    LinkNode *dummyHead = (LinkNode *) malloc(sizeof(LinkNode));
    LinkNode * tail = dummyHead;
    tail->next = NULL;
    for (int i = 0; i < n; ++i) {
        LinkNode *newNode = (LinkNode *) malloc(sizeof(LinkNode));
        newNode->next = NULL;
        newNode->val = data[i];
        tail->next = newNode;
        tail = newNode;
    }
    return dummyHead;
}

// 创建不带头节点的链表
LinkNode * createLinkList_withoutDummy(int * data, int n){
    return createLinkList_dummy(data, n)->next;
}


void printLinkList(LinkNode * head) {
    LinkNode * cur = head;
    printf("List is:");
    while (cur !=NULL) {
        if (cur->next != NULL){
            printf("%d -> ", cur->val);
        } else{
            printf("%d", cur->val);
        }
        cur = cur->next;
    }
    printf("\n");
}

#endif //ALGORITHM_LINKEDLISTHELPER_H


#ifndef ALGORITHM_LINKSTACKHELPER_H
#define ALGORITHM_LINKSTACKHELPER_H
#include <stdio.h>
#include <stdlib.h>
#include "ListHelper.h"

typedef struct {
    LinkNode * pTop;
}LinkStack;

LinkStack * createStack(){
    LinkStack *pS = (LinkStack *) malloc(sizeof(LinkStack));
    pS->pTop = NULL;
    return pS;
}

void push(LinkStack * pS, int val){
    LinkNode *pNew = (LinkNode *) malloc(sizeof(LinkNode));
    pNew->val = val;
    pNew->next = pS->pTop;
    pS->pTop = pNew;
}

int pop(LinkStack * pS){
    LinkNode *pTemp = pS->pTop;
    int popData = pTemp->val;
    pS->pTop = pTemp->next;
    free(pTemp);
    return popData;
}

int emptyStack(LinkStack * pS){
    return NULL == pS->pTop;
}

void printLinkStack(LinkStack * pS){
    if (NULL == pS->pTop) {
        printf("linkStack is empty!\n");
    } else {
        printf("linkStack is : ");
        LinkNode *curNode = pS->pTop;
        while (curNode) {
            printf("%d  ", curNode->val);
            curNode = curNode->next;
        }
    }
    printf("\n");
}


#endif //ALGORITHM_LINKSTACKHELPER_H

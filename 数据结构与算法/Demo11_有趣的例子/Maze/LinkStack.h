#include <stdio.h>
#include <stdlib.h>
#include "MazeData.h"

// 定义链栈
typedef struct sNode {
    Node data;					 // 数据域 
    struct sNode *pNext;	     // 指针域 
} stackNode;

typedef struct {
    stackNode *pTop;			// 栈顶指针 
} LinkStack;

// 创建链栈
LinkStack *createStack()
{
    LinkStack *pS = (LinkStack *) malloc(sizeof(LinkStack));
    if (!pS)
    {
        printf("malloc is failed!\n");
        exit(-1);
    }
    // 初始化 置为NULL 
    pS->pTop = NULL;
    return pS;
}

// 判断链栈是否为空 链栈没有满的情况
int isEmpty(LinkStack *pS)
{
    return NULL == pS->pTop;
}

// 入栈
void push(LinkStack *pS, Node val)
{
    stackNode *pNew = (stackNode *) malloc(sizeof(stackNode));
    // 省略判断pNew是否为空
    pNew->data = val;
    pNew->pNext = pS->pTop;
    pS->pTop = pNew;
    // printf("(%d %d)入栈！\n", val.rowNo, val.colNo);
}

// 出栈
Node pop(LinkStack *pS)
{
    if (isEmpty(pS))
    {
        printf("linkStack is empty! pop is failed\n");
    } else
    {
        stackNode *pTemp = pS->pTop;         // 用一个结点pTemp暂时记住pS->pTop的位置
        Node p = pTemp->data;
        pS->pTop = pTemp->pNext;
        free(pTemp);                         // 删除pTemp并置为NULL
        pTemp = NULL;
        //  printf("(%d %d)出栈！\n", p.rowNo, p.colNo);
        return p;
    }

}

// 遍历链栈
void traverseStack(LinkStack *pS)
{
    if (isEmpty(pS))
    {
        printf("linkStack is empty! traverseStack is failed\n");
        return;
    }
    stackNode *p = pS->pTop;
    printf("path:\n");
    while (p)
    {
        printf("< %d %d %d >\n", p->data.rowNo, p->data.colNo);
        p = p->pNext;
    }
    printf("\n");
}




#include <stdio.h>
#include <stdlib.h>

/**
 *   链栈 只用一个结构体实现    带有头节点  效果跟用两个结构体一样
 *   只用一个结构实现            不带头结点  那么pTop的值也就是栈顶指针(头指针) 每入栈或出栈一次就要修改一次 
 */

typedef struct Node{
    int data;
    struct Node * pNext;
}StackNode;

StackNode * createLinkStack();                                          // 创建链栈
void push(StackNode * pTop, int val);                                   // 入栈
int pop(StackNode * pTop, int *pVal);                                   // 出栈
void traverse(StackNode * pTop);                                        // 遍历
int lengthLinkStack(StackNode * pTop);                                  // 链栈元素的个数

int main(void)
{
    StackNode * pTop = createLinkStack();                               // 栈顶指针  pTop 头指针 pTop-> 头节点  pTop->pNext 首节点
    int val;
    printf("length is : %d\n", lengthLinkStack(pTop));
    push(pTop, 1);
    push(pTop, 2);
    push(pTop, 3);
    if (pop(pTop, &val))
    {
        printf("pop is : %d\n", val);
    }
    push(pTop, 4);
    traverse(pTop);
    printf("length is : %d\n", lengthLinkStack(pTop));
    return 0;
}

StackNode * createLinkStack()
{
    StackNode * pTop = (StackNode *) malloc(sizeof(StackNode));
    if (!pTop)
    {
        printf("malloc is failed!\n");
        exit(-1);
    }
    pTop->pNext = NULL;
}

void push(StackNode * pTop, int val)
{
    StackNode * pNew = (StackNode *)malloc(sizeof(StackNode));
    // 省略判断pNew是否为空
    pNew->data = val;
    pNew->pNext = pTop->pNext;
    pTop->pNext = pNew;
}

int emptyLinkStack(StackNode * pTop)
{
    return NULL == pTop->pNext;
}

int pop(StackNode * pTop, int *pVal)
{
    if (emptyLinkStack(pTop))
    {
        printf("linkStack is empty! pop is failed!\n");
        return -1;
    }
    StackNode * pTemp = pTop->pNext;
    *pVal = pTemp->data;
    pTop->pNext = pTemp->pNext;
    free(pTemp);
    pTemp = NULL;
    return 1;
}

int lengthLinkStack(StackNode * pTop)
{
    int i;
    StackNode * p = pTop;
    while (p->pNext!=NULL)
    {
        p = p->pNext;
        i++;
    }
    return i;
}

void traverse(StackNode * pTop)
{
    if (emptyLinkStack(pTop))
    {
        printf("linkStack is empty! traverse is failed!\n");
        return ;
    }
    printf("linkStack is : ");
    StackNode *p = pTop->pNext;
    while(p!=NULL)
    {
        printf(" %d ",p->data);
        p = p->pNext;
    }
    printf("\n");
}
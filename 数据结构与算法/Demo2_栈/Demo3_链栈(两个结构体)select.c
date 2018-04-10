#include <stdio.h>
#include <stdlib.h>

/**
* 链式栈--符合“后进先出 ”的存储结构 --链表实现
* 将栈想象成一个 竖着排的链表  pTop 是栈顶指针 相当于链表的头指针指向的是头节点
*/


typedef struct Node
{
    int data;
    struct Node *pNext;
} StackNode;


/*
 *  链栈 为什么要用结构体包起来 而不是 直接 StackNode *pTop;   ?
 *  
 *  链栈 只用一个结构体实现  带有头节点   效果跟用两个结构体一样
 *  如果 只用一个结构实现    不带头结点   那么pTop的值也就是栈顶指针(头指针) 每入栈或出栈一次就要修改一次
 */
typedef struct Stack
{
    StackNode *pTop;                                           // 栈顶指针  指向的是节点
} LinkStack;

void initLinkStack(LinkStack *pS);                             // 初始化方式1：在栈中分配
LinkStack *createLinkStack();                                  // 初始化方式2：在堆中分配  (此处选用在“堆”中分配)
void push(LinkStack *pS, int val);                             // 入栈
int pop(LinkStack *pS, int *pVal);                             // 出栈
int lengthLinkStack(LinkStack *pS);                           // 判断链栈内 元素的个数
int emptyLinkStack(LinkStack *pS);                            // 判断链栈是否为空  链 不存在满的情况
void clearLinkStack(LinkStack *pS);                            // 清空链栈
void traverse(LinkStack *pS);                                  // 遍历

int main(void)
{
    // 初始化方式1： 使用 声明变量的方式 在（栈）"挖坑"
    LinkStack S;
    initLinkStack(&S);

    // 初始话方式2： 使用 malloc  在（堆）  "挖坑"  malloc需要头文件 stdlib.h
    // 在此选用第二种方式
    LinkStack *pS = createLinkStack();
    int val;
    printf("length is : %d\n", lengthLinkStack(pS));
    push(pS, 1);
    push(pS, 2);
    push(pS, 3);
    if (pop(pS, &val))
    {
        printf("pop is : %d\n", val);
    }
    push(pS, 4);
    traverse(pS);
    printf("length is : %d\n", lengthLinkStack(pS));

    printf("After clearLinkStack!\n");
    clearLinkStack(pS);
    printf("length is : %d\n", lengthLinkStack(pS));

    push(pS, 10);
    push(pS, 11);
    push(pS, 12);
    if (pop(pS, &val))
    {
        printf("pop is : %d\n", val);
    }
    push(pS,13);
    traverse(pS);
    printf("length is : %d\n", lengthLinkStack(pS));
    return 0;
}

void initLinkStack(LinkStack *pS)
{
    pS->pTop = NULL;
}

LinkStack *createLinkStack()
{
    LinkStack *pS = (LinkStack *) malloc(sizeof(LinkStack));
    if (!pS)
    {
        printf("malloc is failed!\n");
        exit(-1);
    }
    pS->pTop = NULL;
}

void push(LinkStack *pS, int val)
{
    StackNode *pNew = (StackNode *) malloc(sizeof(StackNode));
    // 省略判断 pNew是否为空
    pNew->data = val;
    pNew->pNext = pS->pTop;
    pS->pTop = pNew;
}

int emptyLinkStack(LinkStack *pS)
{
    return NULL == pS->pTop;
}

int pop(LinkStack *pS, int *pVal)
{
    if (emptyLinkStack(pS))
    {
        printf("linkStack is empty! pop is failed!\n");
        return -1;
    } else
    {
        // 定义一个临时的节点pTemp 接收 pTop   用一个指针来接受要出栈的值  然后pTop往下移一位   删除pTemp
        StackNode *pTemp = pS->pTop;
        *pVal = pTemp->data;
        pS->pTop = pTemp->pNext;
        free(pTemp);             // pTemp 所指向的内存被释放(堆)     指针变量pTemp本身保存的地址比没有被释放(栈)
        pTemp = NULL;            // 既然使用free函数之后指针变量pTemp本身保存的地址并没有改变，那我们就需要重新把pTemp的值变为NULL(否则会成为“野指针”)
        return 1;
    }
}

int lengthLinkStack(LinkStack *pS)
{
    int i;
    StackNode *p = pS->pTop;
    while (p != NULL)
    {
        p = p->pNext;
        i++;
    }
    return i;
}

void clearLinkStack(LinkStack *pS)
{
    if (emptyLinkStack(pS))
    {
        printf("linkStack is empty! clear is failed!\n");
        return;
    } else
    {
        StackNode *p = pS->pTop;     // p是q的前驱
        StackNode *q = NULL;
        while (p != NULL)
        {
            q = p->pNext;
            free(p);
            p = NULL;
            p = q;
        }
        pS->pTop = NULL;
//        printf("pS->pTop is : %p\n", pS->pTop);
    }
}

void traverse(LinkStack *pS)
{
    if (emptyLinkStack(pS))
    {
        printf("linkStack is empty! traverse is failed!\n");
        return;
    }
    // 定义一个临时的节点结束pTop 这样遍历之后就不会改变pTop的值 改变的是p
    StackNode *p = pS->pTop;
    printf("linkStack is : ");
    while (p != NULL)
    {
        printf(" %d ", p->data);
        p = p->pNext;
    }
    printf("\n");
}

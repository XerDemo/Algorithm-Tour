#include <stdio.h>
#include <stdlib.h>
/*
	 链式队列：
	 	 
*/
typedef struct node {
    int data;
    struct node *pNext;
} queueNode;

typedef struct {
    queueNode *front;
    queueNode *rear;
    int count;
} Queue;


Queue *createQueue();                                          // 创建队列
void inQueue(Queue *pQ, int val);                              // 进队
int outQueue(Queue *pQ);                                       // 出队
int emptyQueue(Queue *pQ);                                     // 判断队列是否为空
void traverseQueue(Queue *pQ);                                 // 遍历队列
void clearQueue(Queue *pQ);                                    // 清空队列
void destroyQueue(Queue *pQ);                                  // 销毁队列

int main(void)
{
    Queue *pQ = createQueue();
    printf("pQ->front = %p   pQ->rear = %p\n", pQ->front,pQ->rear);
    inQueue(pQ,1);
    inQueue(pQ,2);
    inQueue(pQ,3);
    printf("出队元素：%d\n", outQueue(pQ));
    inQueue(pQ,4);
    printf("队列长度：%d\n", pQ->count);
    traverseQueue(pQ);

    printf("清空队列！\n");
    clearQueue(pQ);
    printf("队列长度：%d\n", pQ->count);
    traverseQueue(pQ);

    inQueue(pQ,10);
    inQueue(pQ,11);
    printf("队列长度：%d\n", pQ->count);
    traverseQueue(pQ);

    printf("销毁队列！\n");
    destroyQueue(pQ);
    printf("pQ->front = %p   pQ->rear = %p\n", pQ->front,pQ->rear);
    return 0;
}

// 初始化队列
Queue *createQueue()
{
    Queue *pQ = (Queue *) malloc(sizeof(Queue));
    pQ->front = (queueNode *) malloc(sizeof(queueNode));
    // 省略判断 pQ  pQ->front 是否为空
    pQ->rear = pQ->front;
    pQ->rear->pNext = NULL;
    pQ->count = 0;
    return pQ;
}

void inQueue(Queue *pQ, int val)
{
    queueNode *pNew = (queueNode *) malloc(sizeof(queueNode));
    pNew->data = val;
    pNew->pNext = NULL;
    pQ->rear->pNext = pNew;
    pQ->rear = pNew;
    pQ->count++;
}

// 判断队列是否为空
int emptyQueue(Queue *pQ)
{
    return NULL == pQ->front;
}

int outQueue(Queue *pQ)
{
    int val;
    if (emptyQueue(pQ))
    {
        printf("链式队列为空！\n");
        return -999999;
    }
    queueNode *pTemp = pQ->front->pNext;
    val = pTemp->data;
    pQ->front->pNext = pTemp->pNext;
    free(pTemp);
    pTemp = NULL;
    pQ->count--;
    return val;
}

void traverseQueue(Queue *pQ)
{
    queueNode *p = pQ->front->pNext;
    if (emptyQueue(pQ))
    {
        printf("链队列空 !\n");
        return;
    }
    printf("链式队列：");
    while (p)
    {
        printf(" %d ", p->data);
        p = p->pNext;
    }
    printf("\n");
}

// 清空队列  定义两个临时节点  从头节点之后的第一个有效的节点开始 释放空间
void clearQueue(Queue *pQ)
{
    queueNode *p = pQ->front->pNext;      // 首节点  （第一个有效元素的节点）
    queueNode *q;
    while (p)
    {
        q = p->pNext;
        free(p);
        p = q;
    }
    /*  上面的另外一种写法
    PNODE p = pQ->front->pNext;      // 首节点  （第一个有效元素的节点）
    while (p)                        // 不为空 就执行
    {
        PNODE temp = p;
        p = p->pNext;
        free(temp);
    }
    */

    // 当while执行完 头节点之后的都被删除了  count为0     头节点的pNext = NULL   rear指向头节点
    pQ->count = 0;
    pQ->front->pNext = NULL;
    pQ->rear = pQ->front;
}

// 销毁队列
void destroyQueue(Queue *pQ)
{
    queueNode *p = pQ->front->pNext;
    queueNode *q;
    while (p)
    {
        q = p->pNext;
        free(p);
        p = q;
    }
    pQ->count = 0;
    pQ->front = pQ->rear = NULL;
}

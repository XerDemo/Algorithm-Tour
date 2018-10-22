#include <stdio.h>
#include <stdlib.h>

typedef struct Node {                // 链式队列节点
    int data;
    struct Node *next;
} LinkNode;

typedef struct {                    // 链式队列
    LinkNode *front;                // 队头指针
    LinkNode *rear;                 // 队尾指针
} LinkQueue;

// 创建队列
LinkQueue *createQueue() {
    LinkQueue *pQ = (LinkQueue *) malloc(sizeof(LinkQueue));
    pQ->front = pQ->rear = (LinkNode *) malloc(sizeof(LinkNode));
    pQ->rear->next = NULL;
    return pQ;
}

// 入队  时间复杂度O(1)
void enQueue(LinkQueue *pQ, int val) {
    LinkNode *newNode = (LinkNode *) malloc(sizeof(LinkNode)); // 建新节点newNode
    newNode->data = val;
    newNode->next = NULL;
    pQ->rear->next = newNode; // 将newNode挂到rear后面
    pQ->rear = newNode;
}

// 判断队列是否空
int isEmpty(LinkQueue *pQ) {
    return pQ->rear == pQ->front;
}

// 出队
int deQueue(LinkQueue *pQ, int *pVal) {
    if (isEmpty(pQ)) {
        printf("LinkQueue is empty.\n");
        return -1;
    }
    LinkNode *p = pQ->front->next;
    *pVal = p->data;
    pQ->front->next = p->next;
    if (pQ->rear == p) {                // 如果只有一个节点
        pQ->rear = pQ->front;
    }
    free(p);
    return 1;
}

int length(LinkQueue *pQ) {
    LinkNode * p = pQ->front->next;
    int i= 0;
    while (p) {
        i++;
        p = p->next;
    }
    return i;
}

// 打印
void printQueue(LinkQueue *pQ) {
    if (isEmpty(pQ)) {
        printf("LinkNode is empty.\n");
        return;
    }
    printf("LinkNode is:");
    LinkNode *p = pQ->front->next;
    while (p) {
        printf("%d   ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main(void) {
    LinkQueue *pQ = createQueue();
    int val;
    enQueue(pQ, 1);
    enQueue(pQ, 2);
    enQueue(pQ, 3);
    enQueue(pQ, 4);
    enQueue(pQ, 5);
    printf("length: %d\n", length(pQ));
    printQueue(pQ);
    if (deQueue(pQ, &val)) {
        printf("delete is : %d\n", val);
    }
    printf("length: %d\n", length(pQ));
    printQueue(pQ);
    return 0;
}


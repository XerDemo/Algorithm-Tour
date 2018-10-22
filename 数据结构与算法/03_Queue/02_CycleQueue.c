#include <stdlib.h>
#include <stdio.h>

#define MAXSIZE 5

typedef struct {
    int data[MAXSIZE];
    int front;                // 队首指针：指向队首元素的前一个元素
    int rear;                 // 队尾指针：指向队尾元素
} CycleQueue;

// 创建循环队列  思考？为什么不是front = rear = -1?  [ front,rear )
CycleQueue *createQueue() {
    CycleQueue *pQ = (CycleQueue *) malloc(sizeof(CycleQueue));
    if (!pQ) {
        printf("malloc is fail.\n");
        exit(-1);
    }
    pQ->front = 0;
    pQ->rear = 0;
    return pQ;
}

// 判断队满
int isFull(CycleQueue * pQ){
    return pQ->front == (pQ->rear + 1) % MAXSIZE;
}

// 入队  O(1)
int enQueue(CycleQueue *pQ, int val) {
    if (isFull(pQ)) {
        printf("cycleQueue is full.\n");
        return -1;
    }
    pQ->rear = (pQ->rear + 1) % MAXSIZE;
    pQ->data[pQ->rear] = val;
    return 1;
}

// 判断是否空
int isEmpty(CycleQueue * pQ){
    return pQ->front == pQ->rear;
}

// 出队  O(1)
int deQueue(CycleQueue * pQ, int * pVal){
    if (isEmpty(pQ)) {
        printf("cycleQueue is empty!\n");
        return -1;
    }
    pQ->front = (pQ->front + 1) % MAXSIZE;
    *pVal = pQ->data[pQ->front];
    return 1;
}

int length(CycleQueue * pQ){
    return (pQ->rear - pQ->front + MAXSIZE) % MAXSIZE;
}

void printQueue(CycleQueue * pQ){
    if (isEmpty(pQ)) {
        printf("cycleQueue is empty.\n");
        return;
    }
    printf("cycleQueue is:");
    int i = pQ->front;
    while (i != pQ->rear) {
        i = (i + 1) % MAXSIZE;
        printf("%d  ", pQ->data[i]);
    }
    printf("\n");
}

int main(void) {
    CycleQueue *pQ = createQueue();
    int val;
    enQueue(pQ, 1);
    enQueue(pQ, 2);
    enQueue(pQ, 3);
    enQueue(pQ, 4);
    printf("length: %d\n", length(pQ));
    deQueue(pQ,&val);
    enQueue(pQ, 5);
    printQueue(pQ);
    printf("length: %d\n", length(pQ));
    return 0;
}
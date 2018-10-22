#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5                // 顺序队列的容量  如需扩增使用 realloc

typedef struct {
    int data[MAXSIZE];
    int fornt;                   // 队首指针：指向队首元素的前一个元素
    int rear;                    // 队尾指针：指向队尾元素
} SeqQueue;

// 创建队列
SeqQueue *createQueue() {
    SeqQueue *pQ = (SeqQueue *) malloc(sizeof(SeqQueue));
    if (!pQ) {
        printf("malloc is failed!\n");
        exit(-1);
    }
    pQ->fornt = -1;
    pQ->rear = -1;
    return pQ;
}

// 判断队满(并不是真正的队满，针对数组的容量)
int isFull(SeqQueue *pQ) {
    return MAXSIZE - 1 == pQ->rear;
}

// 入队 时间复杂度O(1)
// 跟队尾指针rear有关
int enQueue(SeqQueue *pQ, int val) {
    if (isFull(pQ)) {
        printf("seqQueue is full, enQueue is fail.\n");
        return -1;
    }
    pQ->data[++pQ->rear] = val;
    return 1;
}

// 判断队空
int isEmpty(SeqQueue *pQ) {
    return pQ->fornt == pQ->rear;
}

//  出队 数组中的元素 并没有被删除  只是front移动了而已
int deQueue(SeqQueue *pQ, int *pVal) {
    if (isEmpty(pQ)) {
        printf("seqQueue is empty, deQueue is fail.\n");
        return -1;
    }
    *pVal = pQ->data[++pQ->fornt];
    return 1;
}

// 取队头元素 O(1)
int getHead(SeqQueue *pQ) {
    if (isEmpty(pQ)) {
        printf("seqQueue is empty, getHead is fail.\n");
        return -1;
    }
    return pQ->data[pQ->fornt];
}

// 队列元素个数
int length(SeqQueue *pQ) {
    return pQ->rear - pQ->fornt;
}

// 打印队列
void printSeqQueue(SeqQueue *pQ) {
    if (isEmpty(pQ)) {
        printf("seqQueue is empty, printSeqQueue is fail.\n");
        return;
    }
    printf("seqQueue is: ");
    int i = pQ->fornt;
    while (i != pQ->rear) {
        printf("%d  ", pQ->data[++i]);
    }
    printf("\n");
}

int main(void) {
    SeqQueue *pQ = createQueue();
    int val;
    enQueue(pQ, 1);
    enQueue(pQ, 2);
    enQueue(pQ, 3);
    enQueue(pQ, 4);
    enQueue(pQ, 5);
    deQueue(pQ, &val);
    enQueue(pQ, 6);
    printf("head: %d \n", getHead(pQ));
    printSeqQueue(pQ);
    return 0;
}

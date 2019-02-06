#include <stdio.h>
#include <stdlib.h>

#define INITSIZE 5                // 队列初始容量
#define E int

/*
// 不能动态增长的节点定义
typedef struct {
    int data[INITSIZE];
    int front;
    int rear;
} LoopQueue;
*/

// 可以动态增长的节点定义
typedef struct {
    E *data;                     // 数组空间基址
    int capacity;                // 队列的容量
    int front;                   // 队首指针：指向队首
    int rear;                    // 队尾指针：指向队尾的后一个位置
} LoopQueue;

// 初始化队列
LoopQueue *initQueue() {
    LoopQueue *queue = (LoopQueue *) malloc(sizeof(LoopQueue));
    queue->data = (E *) malloc(sizeof(E) * INITSIZE);
    queue->capacity = INITSIZE;
    queue->front = queue->rear = 0;
}

// 获取循环队列的容量
int getCapacity(LoopQueue *queue) {
    return queue->capacity - 1;  // 牺牲一个空间来区分队空和队满
}

// 返回循环队列是否为空
int isEmpty(LoopQueue *queue) {
    return queue->front == queue->rear;
}

// 获取队列实际元素个数
int getSize(LoopQueue *queue) {
    return (queue->rear + queue->capacity - queue->front) % queue->capacity;
}

// 将数组空间的容量扩容成newCapacity大小 O(N)
void resize(LoopQueue *queue, int newCapacity) {
    E *newDate = (E *) malloc(sizeof(E) * newCapacity + 1); // 牺牲一个空间来区分队空和队满 所以补上一个空间
    int i;
    for (i = 0; i < getSize(queue); ++i) {
        newDate[i] = queue->data[(i + queue->front) % queue->capacity];
    }
    queue->data = newDate;
    queue->rear = getSize(queue);
    queue->front = 0;
    queue->capacity = newCapacity + 1;
}

// 入队 入队跟尾指针有关
// 不算resize操作  O(1)  其实算上resize的话(并不是每次都会触发resize) 用均摊复杂度来看也是O(1)
void enqueue(LoopQueue *queue, E e) {
    if ((queue->rear + 1) % queue->capacity == queue->front) { // 队列满
        resize(queue, 2 * queue->capacity);
    }
    queue->data[queue->rear] = e;
    queue->rear = (queue->rear + 1) % queue->capacity;
}

// 出队 只跟队头指针有关
// 不算resize操作  O(1)  其实算上resize的话(并不是每次都会触发resize) 用均摊复杂度来看也是O(1)
E dequeue(LoopQueue *queue) {
    if (isEmpty(queue)) {
        printf("dequeue failed. Queue is empty.\n");
        return -9999999;
    }
    E res = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    // 动态缩减数组
    // 为了防止复杂度震荡 设为元素个数为1/4时才缩减至一半 getSize(queue) == queue->capacity / 4 && queue->capacity / 2 != 0
    if (getSize(queue) == queue->capacity / 2) {
        resize(queue, queue->capacity / 2);
    }
    return res;
}

// 获取队头元素 O(1)
E getFront(LoopQueue *queue) {
    if (isEmpty(queue)) {
        printf("getFront failed. Queue is empty.\n");
        return -9999999;
    }
    return queue->data[queue->front];
}

// 打印循环队列信息
void printMessage(LoopQueue *queue) {
    printf("Queue:size = %d  , capacity = %d \n", getSize(queue), getCapacity(queue));
    if (isEmpty(queue)) {
        printf("printMessage failed. Queue is empty.\n");
        return;
    }
    int i;
    printf("%d  %d\n", queue->front, queue->rear);
    printf("front [");
    for (i = queue->front; i < queue->rear; ++i) {
        printf("%d", queue->data[i]);
        if (i != queue->rear - 1) {
            printf(", ");
        }
    }
    printf("] rear\n");
}

int main(void) {
    LoopQueue *queue = initQueue();
//    int i;
//    for (i = 0; i < 50; ++i) {
//        printf("----------------\n");
//        enqueue(queue, i);
//        printMessage(queue);
//        printf("%d   %d\n", queue->front, queue->rear);
//        printf("front: %d\n", getFront(queue));
//    }
////    printMessage(queue);
////    printf("front: %d\n", getFront(queue));
////
////    printf("----------------\n");
////    enqueue(queue,99);
////    printMessage(queue);
////
////    printf("----------------\n");
////    enqueue(queue,100);
////    printMessage(queue);
////
////    for (int j = 0; j < 40 ; ++j) {
////        printf("----------------\n");
////        dequeue(queue);
////        printMessage(queue);
////        printf("%d   %d\n", queue->front, queue->rear);
////        printf("front: %d\n", getFront(queue));
////    }

    enqueue(queue, 1);
    printMessage(queue);
    printf("%d \n", getFront(queue));
    printf("-------------\n");
    enqueue(queue, 2);
    printMessage(queue);
    printf("%d \n", getFront(queue));
    printf("-------------\n");
    enqueue(queue, 3);
    printMessage(queue);
    printf("%d \n", getFront(queue));
    printf("-------------\n");
    dequeue(queue);
    printMessage(queue);
    printf("%d \n", getFront(queue));
    printf("-------------\n");
    enqueue(queue, 99);
    printMessage(queue);
    printf("%d \n", getFront(queue));

    return 0;
}
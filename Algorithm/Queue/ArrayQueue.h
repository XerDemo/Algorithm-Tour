//
// Created by XerDemo on 2019/7/31.
//

#ifndef ALGORITHM_ARRAYQUEUE_H
#define ALGORITHM_ARRAYQUEUE_H
#include <stdio.h>
#include <stdlib.h>

#define INITSIZE 05.TreeHeight                // 顺序队列初始容量
#define E int

/*
// 不能动态增长的节点定义
typedef struct {
    int data[INITSIZE];
    int front;
    int rear;
} SeqQueue;
*/

// 可以动态增长的节点定义
typedef struct {
    E *data;                     // 数组空间基址
    int capacity;                // 顺序队列的容量
    int front;                   // 队首指针：指向队首
    int rear;                    // 队尾指针：指向队尾的后一个位置
} SeqQueue;

// 初始化队列
SeqQueue *initQueue() {
    SeqQueue *queue = (SeqQueue *) malloc(sizeof(SeqQueue));
    queue->data = (E *) malloc(sizeof(E) * INITSIZE);
    queue->capacity = INITSIZE;
    queue->front = queue->rear = 0;
}

// 获取顺序队列的容量
int getCapacity(SeqQueue *queue) {
    return queue->capacity;
}

// 返回顺序队列是否为空
int isEmpty(SeqQueue *queue) {
    return queue->front == queue->rear;
}

// 获取队列实际元素个数
int getSize(SeqQueue *queue) {
    return queue->rear - queue->front;
}

// 将数组空间的容量扩容成newCapacity大小 O(N)
void resize(SeqQueue *queue, int newCapacity) {
    E *newDate = (E *) malloc(sizeof(E) * newCapacity);
    int i,j = queue->front;
    for (i = 0; i < getSize(queue); ++i) {
        newDate[i] = queue->data[j++];
    }
    queue->data = newDate;
    queue->rear = getSize(queue);
    queue->front = 0;  // rear重新赋值的操作要放在front前
    queue->capacity = newCapacity;
}

// 入队 入队跟尾指针有关
// 不算resize操作  O(1)  其实算上resize的话(并不是每次都会触发resize) 用均摊复杂度来看也是O(1)
void enqueue(SeqQueue *queue, E e) {
    if (queue->rear == queue->capacity) { // 队列满
        resize(queue, 2 * queue->capacity);
    }
    queue->data[queue->rear] = e;
    queue->rear++;
}

// 出队 只跟队头指针有关
// 不算resize操作  O(1)  其实算上resize的话(并不是每次都会触发resize) 用均摊复杂度来看也是O(1)
E dequeue(SeqQueue *queue) {
    if (isEmpty(queue)) {
        printf("dequeue failed. Queue is empty.\n");
        return -9999999;
    }
    E res = queue->data[queue->front];
    queue->front++;

    // 动态缩减数组
    // 为了防止复杂度震荡 设为元素个数为1/4时才缩减至一半 getSize(queue) == queue->capacity / 4 && queue->capacity / 2 != 0
    if (getSize(queue) == queue->capacity / 2) {
        resize(queue, queue->capacity / 2);
    }

    return res;
}

// 获取队头元素 O(1)
E getFront(SeqQueue *queue) {
    if (isEmpty(queue)) {
        printf("getFront failed. Queue is empty.\n");
        return -9999999;
    }
    return queue->data[queue->front];
}

// 打印顺序队列信息
void printMessage(SeqQueue *queue) {
    printf("Queue:size = %d  , capacity = %d \n", getSize(queue), getCapacity(queue));
    if (isEmpty(queue)) {
        printf("printMessage failed. Queue is empty.\n");
        return;
    }
    int i;
    printf("front [");
    for (i = queue->front; i < queue->rear; ++i) {
        printf("%d", queue->data[i]);
        if (i != queue->rear - 1) {
            printf(", ");
        }
    }
    printf("] rear\n");
}

#endif //ALGORITHM_ARRAYQUEUE_H

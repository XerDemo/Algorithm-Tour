#include <stdio.h>
#include <stdlib.h>

#define E int

typedef struct Node {       // 链式队列节点
    E data;
    struct Node *next;
} LinkNode;

typedef struct {
    LinkNode *front;        // 队头指针
    LinkNode *rear;         // 队尾指针
    int size;               // 队列中元素个数  加入size变量可以使求长度操作的复杂度从O(N)降为O(1)
    // 不需要遍历求队列长度 只需要花费一点时间维护size
} LinkedQueue;

// 创建队列
LinkedQueue *createQueue() {
    LinkedQueue *pQ = (LinkedQueue *) malloc(sizeof(LinkedQueue));
    pQ->front = pQ->rear = (LinkNode *) malloc(sizeof(LinkNode));
    pQ->rear->next = NULL;
    pQ->size = 0;
    return pQ;
}

// 获取队列大小 O(1) 如果不加入size 则需要遍历链式队列求其容量大小需要O(N)
int getSize(LinkedQueue *pQ) {
    return pQ->size;
}

// 返回是否为空
int isEmpty(LinkedQueue *pQ) {
    // return pQ->front == pQ->rear  // 不加入size判断是否为空
    return 0 == pQ->size;
}


// 入队  时间复杂度O(1)
void enQueue(LinkedQueue *pQ, E e) {
    LinkNode *newNode = (LinkNode *) malloc(sizeof(LinkNode)); // 建新节点newNode
    newNode->data = e;
    newNode->next = NULL;
    pQ->rear->next = newNode; // 将newNode挂到rear后面
    pQ->rear = newNode;
    pQ->size++;
}

// 出队  O(1)
E deQueue(LinkedQueue *pQ) {
    if (isEmpty(pQ)) {
        printf("deQueue failed. LinkedQueue is empty.\n");
        return -9999999;
    }
    LinkNode *delNode = pQ->front->next;
    E res = delNode->data;
    pQ->front->next = delNode->next;
    if (pQ->rear == delNode) {                // 如果队列此时只有一个节点 出队后
        pQ->rear = pQ->front; // front 和 rear都指向 NULL
    }
    free(delNode);
    pQ->size--;
    return res;
}

// 得到队头元素 O(1)
E getFront(LinkedQueue *pQ) {
    if(isEmpty(pQ)){
        printf("getFront failed. LinkedQueue is empty.\n");
        return -9999999;
    }
    return pQ->front->next->data;
}

void printMessage(LinkedQueue *pQ) {
    if (isEmpty(pQ)) {
        printf("printMessage failed. LinkedQueue is empty.\n");
        return;
    }
    printf("LinkedQueue: front ");
    LinkNode * curNode = pQ->front->next;
    while (curNode!=NULL){
        printf("%d -> ", curNode->data);
        curNode = curNode->next;
    }
    printf("rear \n");
}

int main(void){
    LinkedQueue *queue = createQueue();
    int i;
    for (i = 0; i < 5; ++i) {
        enQueue(queue, i);
    }
    printf("size: %d  front:%d\n", getSize(queue), getFront(queue));
    printMessage(queue);
    printf("-----------\n");

    for (i = 0; i < 6; ++i) {
        deQueue(queue);
        printf("size: %d  front:%d\n", getSize(queue), getFront(queue));
        printMessage(queue);
        printf("-----------\n");
    }
    return 0;
}




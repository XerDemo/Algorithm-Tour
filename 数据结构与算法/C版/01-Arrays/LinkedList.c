#include <stdlib.h>
#include <stdio.h>

#define E int

typedef struct Node{
    E data;                       // 数据域
    struct Node * next;           // 指针域
}LinkNode;


// 初始化链表
LinkNode * initLink(){
    LinkNode *dummyHead = (LinkNode *) malloc(sizeof(LinkNode)); // 创建虚拟头节点
    dummyHead->next = NULL;
    return dummyHead;
}

// 获取链表中的元素个数  O(N)  可以通过加入size成员 来使复杂度降为O(1) 虽然需要维护size 见java版
int getSize(LinkNode * dummyHead){
    LinkNode *curNode = dummyHead->next;
    int size = 0, i;
    while (curNode != NULL) {
        size++;
        curNode = curNode->next;
    }
    return size;
}

// 返回链表是否为空
int isEmpty(LinkNode * dummyHead){
    return NULL == dummyHead->next;
}

// 在链表的索引为index位置添加新的元素e  index从0开始  O(N)
// dummyHead -> 1 -> 2 -> 3
// index        0    1    2    则index可以使在索引为0,1,2,3的位置插入 即index ∈ [0,getSize()]
void add(LinkNode * dummyHead,int index, E e){
    if (index < 0 || index > getSize(dummyHead)) {
        printf("Add failed. index index ∈ [0,getSize()]\n");
        return;
    }
    LinkNode *pre = dummyHead;
    int i;
    for (i = 0; i < index; ++i) {
        pre = pre->next;
    }
    LinkNode *newNode = (LinkNode *) malloc(sizeof(LinkNode));
    newNode->data = e;
    newNode->next = pre->next;
    pre->next = newNode;
}


// 在链表头添加新的元素e   O(1)
void addFirst(LinkNode * dummyHead,E e){
    add(dummyHead, 0, e);
}

// 在链表末尾添加新的元素e  O(N)
void addLast(LinkNode * dummyHead,E e){
    add(dummyHead, getSize(dummyHead), e);
}


// 获得链表的第index ∈ [0,getSize()-1]个位置的元素  O(N)
E get(LinkNode * dummyHead,int index){
    if (index < 0 || index >= getSize(dummyHead)) {
        printf("get failed. index index ∈ [0,getSize()-1]\n");
        return -9999999;
    }
    LinkNode *curNode = dummyHead->next;
    int i;
    for (i = 0; i < index; ++i) {
        curNode = curNode->next;
    }
    return curNode->data;
}

// 获得链表的第一个元素  O(1)
E getFirst(LinkNode *dummyHead) {
    return get(dummyHead, 0);
}

// 获得链表的最后一个元素  O(N)
E getLast(LinkNode *dummyHead){
    return get(dummyHead, getSize(dummyHead) - 1);
}

// 修改链表的第index ∈ [0,getSize()-1]个位置的元素为e  O(N)
void set(LinkNode *dummyHead, int index, E e){
    if (index < 0 || index >= getSize(dummyHead)) {
        printf("set failed. index index ∈ [0,getSize()-1]\n");
        return;
    }
    LinkNode *curNode = dummyHead->next;
    int i;
    for (i = 0; i < index; ++i) {
        curNode = curNode->next;
    }
    curNode->data = e;
}

// 查找链表中是否有元素e O(N)
int contains(LinkNode * dummyHead, E e){
    LinkNode *curNode = dummyHead->next;
    while (curNode != NULL) {
        if (curNode->data == e) {
            return 1;
        }
        curNode = curNode->next;
    }
    return 0;
}

// 从链表中删除index ∈ [0,getSize()-1]位置的元素, 返回删除的元素  O(N)
E Remove(LinkNode * dummyHead,int index){
    if (index < 0 || index >= getSize(dummyHead)){
        printf("remove failed. index ∈ [0,getSize()-1].\n");
        return -9999999;
    }
    LinkNode *pre = dummyHead;
    int i;
    for (i = 0; i < index; ++i) {
        pre = pre->next;
    }
    LinkNode *delNode = pre->next;
    E res = delNode->data;
    pre->next = delNode->next;
    free(delNode);
    delNode = NULL;
    return res;
}

// 从链表中删除第一个元素, 返回删除的元素  O(1)
E removeFirst(LinkNode * dummyHead){
    return Remove(dummyHead, 0);
}

// 从链表中删除最后一个元素, 返回删除的元素  O(N)
E removeLast(LinkNode * dummyHead){
    return Remove(dummyHead, getSize(dummyHead) - 1);
}

// 从链表中删除元素e  O(N)
void removeElement(LinkNode * dummyHead,E e){
    LinkNode *pre = dummyHead;
    while (pre->next != NULL) {
        if (pre->next->data == e){
            LinkNode *delNode = pre->next;
            pre->next = delNode->next;
            free(delNode);
            delNode = NULL;
            return;
        }
        pre = pre->next;
    }
}

// 打印信息
void printMessage(LinkNode *dummyHead){
    if (isEmpty(dummyHead)){
        printf("printMessage failed. LinkedList is empty.\n");
        return;
    }
    int i;
    printf("LinkedList : ");
    LinkNode * curNode = dummyHead->next;
    while (curNode != NULL) {
        printf("%d -> ", curNode->data);
        curNode = curNode->next;
    }
    printf("NULL\n");
}

/**
 * 链式栈和链式队列都可以由使链表操作的子集
 * 栈:addFirst()入栈   removeFirst()出栈    getFirst()取栈顶元素  都是O(1)
 * 队列: removeFirst()出队   addLast()入队   getFirst()队头元素    队列出队，取队头O(1),入队需要O(N) 但是如果在头指针的基础上设尾指针 降为O(1)
 */

int main(void){
    LinkNode *dummyHead = initLink();
    int i;
    for (i = 0; i < 10; ++i) {
        addLast(dummyHead, i);
    }
    printf("size: %d, first: %d, last: %d\n", getSize(dummyHead), getFirst(dummyHead), getLast(dummyHead));
    printMessage(dummyHead);
    printf("---------------------\n");

    printf("remove: %d\n",Remove(dummyHead, 2));
    printf("size: %d, first: %d, last: %d\n", getSize(dummyHead), getFirst(dummyHead), getLast(dummyHead));
    printMessage(dummyHead);
    printf("---------------------\n");

    printf("removeFirst: %d\n",removeFirst(dummyHead));
    printf("size: %d, first: %d, last: %d\n", getSize(dummyHead), getFirst(dummyHead), getLast(dummyHead));
    printMessage(dummyHead);
    printf("---------------------\n");

    printf("removeLast: %d\n",removeLast(dummyHead));
    printf("size: %d, first: %d, last: %d\n", getSize(dummyHead), getFirst(dummyHead), getLast(dummyHead));
    printMessage(dummyHead);
    printf("---------------------\n");


    set(dummyHead, 1, 99);
    printf("size: %d, first: %d, last: %d\n", getSize(dummyHead), getFirst(dummyHead), getLast(dummyHead));
    printMessage(dummyHead);
    printf("---------------------\n");

    removeElement(dummyHead, 99);
    printf("size: %d, first: %d, last: %d\n", getSize(dummyHead), getFirst(dummyHead), getLast(dummyHead));
    printMessage(dummyHead);
    printf("---------------------\n");

    printf("%d\n",contains(dummyHead, 8));
    printf("get: %d\n", get(dummyHead, 4));
    printf("---------------------\n");

    return 0;
}
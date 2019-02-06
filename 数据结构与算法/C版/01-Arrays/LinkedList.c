#include <stdlib.h>
#include <stdio.h>

#define E int

typedef struct Node{
    E data;                       // ������
    struct Node * next;           // ָ����
}LinkNode;


// ��ʼ������
LinkNode * initLink(){
    LinkNode *dummyHead = (LinkNode *) malloc(sizeof(LinkNode)); // ��������ͷ�ڵ�
    dummyHead->next = NULL;
    return dummyHead;
}

// ��ȡ�����е�Ԫ�ظ���  O(N)  ����ͨ������size��Ա ��ʹ���ӶȽ�ΪO(1) ��Ȼ��Ҫά��size ��java��
int getSize(LinkNode * dummyHead){
    LinkNode *curNode = dummyHead->next;
    int size = 0, i;
    while (curNode != NULL) {
        size++;
        curNode = curNode->next;
    }
    return size;
}

// ���������Ƿ�Ϊ��
int isEmpty(LinkNode * dummyHead){
    return NULL == dummyHead->next;
}

// �����������Ϊindexλ������µ�Ԫ��e  index��0��ʼ  O(N)
// dummyHead -> 1 -> 2 -> 3
// index        0    1    2    ��index����ʹ������Ϊ0,1,2,3��λ�ò��� ��index �� [0,getSize()]
void add(LinkNode * dummyHead,int index, E e){
    if (index < 0 || index > getSize(dummyHead)) {
        printf("Add failed. index index �� [0,getSize()]\n");
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


// ������ͷ����µ�Ԫ��e   O(1)
void addFirst(LinkNode * dummyHead,E e){
    add(dummyHead, 0, e);
}

// ������ĩβ����µ�Ԫ��e  O(N)
void addLast(LinkNode * dummyHead,E e){
    add(dummyHead, getSize(dummyHead), e);
}


// �������ĵ�index �� [0,getSize()-1]��λ�õ�Ԫ��  O(N)
E get(LinkNode * dummyHead,int index){
    if (index < 0 || index >= getSize(dummyHead)) {
        printf("get failed. index index �� [0,getSize()-1]\n");
        return -9999999;
    }
    LinkNode *curNode = dummyHead->next;
    int i;
    for (i = 0; i < index; ++i) {
        curNode = curNode->next;
    }
    return curNode->data;
}

// �������ĵ�һ��Ԫ��  O(1)
E getFirst(LinkNode *dummyHead) {
    return get(dummyHead, 0);
}

// �����������һ��Ԫ��  O(N)
E getLast(LinkNode *dummyHead){
    return get(dummyHead, getSize(dummyHead) - 1);
}

// �޸�����ĵ�index �� [0,getSize()-1]��λ�õ�Ԫ��Ϊe  O(N)
void set(LinkNode *dummyHead, int index, E e){
    if (index < 0 || index >= getSize(dummyHead)) {
        printf("set failed. index index �� [0,getSize()-1]\n");
        return;
    }
    LinkNode *curNode = dummyHead->next;
    int i;
    for (i = 0; i < index; ++i) {
        curNode = curNode->next;
    }
    curNode->data = e;
}

// �����������Ƿ���Ԫ��e O(N)
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

// ��������ɾ��index �� [0,getSize()-1]λ�õ�Ԫ��, ����ɾ����Ԫ��  O(N)
E Remove(LinkNode * dummyHead,int index){
    if (index < 0 || index >= getSize(dummyHead)){
        printf("remove failed. index �� [0,getSize()-1].\n");
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

// ��������ɾ����һ��Ԫ��, ����ɾ����Ԫ��  O(1)
E removeFirst(LinkNode * dummyHead){
    return Remove(dummyHead, 0);
}

// ��������ɾ�����һ��Ԫ��, ����ɾ����Ԫ��  O(N)
E removeLast(LinkNode * dummyHead){
    return Remove(dummyHead, getSize(dummyHead) - 1);
}

// ��������ɾ��Ԫ��e  O(N)
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

// ��ӡ��Ϣ
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
 * ��ʽջ����ʽ���ж�������ʹ����������Ӽ�
 * ջ:addFirst()��ջ   removeFirst()��ջ    getFirst()ȡջ��Ԫ��  ����O(1)
 * ����: removeFirst()����   addLast()���   getFirst()��ͷԪ��    ���г��ӣ�ȡ��ͷO(1),�����ҪO(N) ���������ͷָ��Ļ�������βָ�� ��ΪO(1)
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
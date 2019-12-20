//
// Created by XerDemo on 2019/7/31.
//

#ifndef ALGORITHM_ARRAYSTACK_H
#define ALGORITHM_ARRAYSTACK_H
#include <stdio.h>
#include <stdlib.h>

#define E char
#define INITSIZE 10                    // 数组的初始大小

//// 不能动态伸缩数组的节点定义
//typedef struct {
//    E data[capacity];
//    int top;
//} ArrayStack;

// 动态增长或缩减顺序栈的节点定义
typedef struct {
    E *data;        // 数组基址
    int capacity;   // 数组的最大容量
    int top;        // 栈顶指针  指向数组最后一个元素的下标  初始时为空：-1  有一个元素：0 以此类推
} ArrayStack;

// 初始化栈  top等于-1时 表示栈空    top等于MAXSIZE-1时 表示栈满
ArrayStack *initStack() {
    ArrayStack *stack = (ArrayStack *) malloc(sizeof(ArrayStack));
    stack->data = (E *) malloc(sizeof(E) * INITSIZE);
    stack->capacity = INITSIZE;
    stack->top = -1;
    return stack;
}

// 顺序栈是否为空
int isEmpty(ArrayStack *stack) {
    return -1 == stack->top;
}

// 获取顺序栈中元素个数
int getSize(ArrayStack *stack) {
    return stack->top + 1;
}

// 获取顺序栈的最大容量
int getCapacity(ArrayStack *stack) {
    return stack->capacity;
}

// 将数组空间的容量扩容成newCapacity大小  O(1)
void resize(ArrayStack *stack, int newCapacity) {
    E *newData = (E *) malloc(sizeof(E) * newCapacity);
    int i;
    for (i = 0; i <= stack->top; ++i) {
        newData[i] = stack->data[i];
    }
    stack->data = newData;
    stack->capacity = newCapacity;
}

// 入栈 不算resize()   O(1)
void push(ArrayStack *stack, E e) {
    if (stack->top + 1 == stack->capacity) { // 栈满
        resize(stack, 2 * stack->capacity);
    }
    stack->top++;
    stack->data[stack->top] = e;
}

// 出栈 并返回出栈元素  O(1) 并没有真正的删除栈顶元素 只是改变了栈顶指针的指向
E pop(ArrayStack *stack) {
    if (isEmpty(stack)){
        printf("pop failed. stack is empty.\n");
        return '\0';
    }
    E res = stack->data[stack->top];
    stack->top--;
    if (stack->top + 1 == stack->capacity / 2) {
        resize(stack, stack->capacity / 2);
    }
    return res;
}

// 获取栈顶元素  O(1)
E peek(ArrayStack *stack){
    if (isEmpty(stack)){
        printf("peek failed. stack is empty.\n");
        return '\0';
    }
    return stack->data[stack->top];
}

// 打印栈信息
void printMessage(ArrayStack *stack){
    if (isEmpty(stack)){
        printf("printMessage failed. stack is empty.\n");
        return ;
    }
    printf("Array:size = %d  , capacity = %d \n", getSize(stack), getCapacity(stack));
    int i;
    printf("stack : [");
    for (i = 0; i <= stack->top; ++i) {
        printf("%d", stack->data[i]);
        if (i != stack->top) {
            printf(", ");
        }
    }
    printf("] top\n");
}




#endif //ALGORITHM_ARRAYSTACK_H

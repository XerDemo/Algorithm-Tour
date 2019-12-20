//
// Created by XerDemo on 2019/2/16pattern.
//

#ifndef ALGORITHM_STACK_H
#define ALGORITHM_STACK_H

#include <stdio.h>
#include <stdlib.h>



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





#endif //ALGORITHM_STACK_H

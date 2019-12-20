//#include <stdio.h>
//#include <stdlib.h>
//
//#define E int
//#define ERROR -999999
//
//// 链式栈节点定义
//typedef struct stackNode{
//    E data;     // 数据域
//    struct stackNode * next; // 指针域
//}StackNode;
//
//typedef struct {
//    StackNode * top; // 栈顶指针
//    int size;        // 栈中元素个数  加入size变量可以使求长度操作的复杂度从O(N)降为O(1)
//                     // 不需要遍历求链栈长度 只需要花费一点时间维护size
//}LinkedStack;
//
//// 创建链栈
//LinkedStack * createStack(){
//    LinkedStack *stack = (LinkedStack *) malloc(sizeof(LinkedStack));
//    if (stack == NULL) {
//        printf("malloc is failed.\n");
//        exit(-1);
//    }
//    stack->top = NULL;
//    stack->size = 0;
//    return stack;
//}
//
//// 获取链式栈大小   O(1)
//int getSize(LinkedStack * stack){
//    return stack->size;
//}
//
//
////// 链栈的长度  O(N)  不加size时
////int getSize(LinkStack * stack){
////    stackNode * curNode = stack->top;
////    int count = 0;
////    while (curNode->next != NULL) {
////        count++;
////        curNode = curNode->next;
////    }
////    return count;
////}
//
//
//// 返回链式栈是否为空   O(1)
//int isEmpty(LinkedStack * stack){
//    return 0 == stack->size;
//}
//
//// 入栈 O(1)
//void push(LinkedStack * stack, E data){
//    StackNode *newNode = (StackNode *) malloc(sizeof(StackNode));
//    newNode->data = data;
//    newNode->next = stack->top;
//    stack->top = newNode;
//    stack->size++;
//}
//
//
//// 出栈  O(1)
//E pop(LinkedStack * stack){
//    if (isEmpty(stack)){
//        printf("LinkStack is empty, pop is failed.\n");
//        return ERROR;
//    }
//    StackNode * delNode = stack->top; // 待出栈节点
//    E res= delNode->data; // 出栈节点的数据域
//    stack->top = delNode->next; // 栈顶指针指向待出栈节点的后一个节点
//    free(delNode); // 释放待出栈节点
//    delNode = NULL;
//    stack->size--;
//    return res;
//}
//
//// 获取栈顶元素  O(1)
//E peek(LinkedStack * stack){
//    if (isEmpty(stack)){
//        printf("peek failed. LinkedStack is empty.\n");
//        return -9999999;
//    }
//    return stack->top->data;
//}
//
//// 打印栈信息
//void printMessage(LinkedStack * stack){
//    if (isEmpty(stack)){
//        printf("printMessage failed. LinkedStack is empty.\n");
//        return;
//    }
//    StackNode * curNode = stack->top;
//    printf("LinkedStack is: top ");
//    while (curNode != NULL) {
//        printf("%d -> ", curNode->data);
//        curNode = curNode->next;
//    }
//    printf("NULL \n");
//}
//
//
//int main(void) {
//    LinkedStack *stack = createStack();
//    int i;
//    for (i = 0; i < 05.TreeHeight; ++i) {
//        push(stack, i);
//    }
//    printf("size: %d  peek: %d\n", getSize(stack), peek(stack));
//    printMessage(stack);
//    printf("------------\n");
//
//    printf("pop: %d\n",pop(stack));
//    printf("size: %d  peek: %d\n", getSize(stack), peek(stack));
//    printMessage(stack);
//    printf("------------\n");
//
//    return 0;
//}
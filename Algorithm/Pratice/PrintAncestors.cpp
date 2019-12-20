//#include <stdio.h>
//#include <stdlib.h>
//
//
//#define E char
//#define Ee TreeNode *
//
//
//typedef struct Node{
//    E data;
//    struct Node * left;
//    struct Node * right;
//    char flag; // 存放描叙信息
//}TreeNode;
//
//
//
//// 链式栈节点定义
//typedef struct stackNode{
//    Ee data;     // 数据域
//    struct stackNode * next; // 指针域
//}StackNode;
//
//typedef struct {
//    StackNode * top; // 栈顶指针
//    int size;        // 栈中元素个数  加入size变量可以使求长度操作的复杂度从O(N)降为O(1)
//    // 不需要遍历求链栈长度 只需要花费一点时间维护size
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
//void push(LinkedStack * stack, Ee data){
//    StackNode *newNode = (StackNode *) malloc(sizeof(StackNode));
//    newNode->data = data;
//    newNode->next = stack->top;
//    stack->top = newNode;
//    stack->size++;
//}
//
//
//// 出栈  O(1)
//Ee pop(LinkedStack * stack){
//    if (isEmpty(stack)){
//        printf("LinkStack is empty, pop is failed.\n");
//        return NULL;
//    }
//    StackNode * delNode = stack->top; // 待出栈节点
//    Ee res= delNode->data; // 出栈节点的数据域
//    stack->top = delNode->next; // 栈顶指针指向待出栈节点的后一个节点
//    free(delNode); // 释放待出栈节点
//    delNode = NULL;
//    stack->size--;
//    return res;
//}
//
//// 获取栈顶元素  O(1)
//Ee peek(LinkedStack * stack){
//    if (isEmpty(stack)){
//        printf("peek failed. LinkedStack is empty.\n");
//        return NULL;
//    }
//    return stack->top->data;
//}
//
//// 递归宏观语义：先序创建二叉树
//TreeNode * createTree(){
//    TreeNode * root = (TreeNode *)malloc(sizeof(TreeNode));
//    E val;
//    scanf("%c", &val);
//    getchar();
//    if (val == '^') {
//        return NULL;
//    }
//    root->data = val;   // 访问根
//    printf("%c的左孩子：\n", root->data);
//    root->left = createTree();
//    printf("%c的右孩子：\n", root->data);
//    root->right = createTree();
//    return root;
//}
//
//
//void preOrder(TreeNode * root){
//    if (root == NULL) {
//        return;
//    }
//    printf("%c ", root->data);
//    preOrder(root->left);
//    preOrder(root->right);
//}
//
////// 递归宏观语义：返回以root为根节点的二叉树 是否含有key
////bool printAncestor(TreeNode * root, int key){
////    if (root == NULL) {    // 树空(包括了递归到最底层叶子结点的左右两个空NULL)
////        return false;
////    }
////    if (root->data == key) {  // 递归结束条件之一
////        return true;
////    }
////
////    bool left = printAncestor(root->left, key);  // 递归左子树是否含有key
////    bool right = printAncestor(root->right, key); // 递归右子树是否含有key
////    if (left || right) { // 只要左右子树一边含有key  那么root就是祖先结点
////        printf("%c \n", root->data);
////        return true;
////    }
////    return false;
////}
//
//
//
////void printAncestor(TreeNode * root){
////    if (root == NULL) {
////        return;
////    }
////    ArrayStack *stack = initStack();
////    Command *command = (Command *) malloc(sizeof(Command));
////    command->flag = 'g';
////    command->node = root;
////    push(stack, command);
////    while (!isEmpty(stack)) {
////        Command *topCom = pop(stack);
////        if (topCom->flag = 'p') {
////            printf("%c ");
////        } else{
////            Command *com = (Command *) malloc(sizeof(Command));
////            com->node = topCom->node;
////        }
////    }
////}
//
//
//
////void postOrder(TreeNode *root) {
////    if (root == NULL) {
////        return;
////    }
////    ArrayStack *stack = initStack();
////    TreeNode * curNode = root;
////    TreeNode *r = NULL;
////    while (curNode != NULL || !isEmpty(stack)) {
////        if (curNode != NULL) {
////            push(stack, curNode);
////            curNode = curNode->left;
////        } else{
////            TreeNode * top = peek(stack);
////            if (top->right != NULL && top->right != r){
////                curNode = top->right;
////                push(stack, curNode);
////                curNode = curNode->left;
////            } else{
////                TreeNode * top = pop(stack);
////                printf("%c ", top->data);
////                r = top;
////                curNode = NULL;
////            }
////        }
////    }
////}
//
//void 03.postOrder(TreeNode *root, E key) {
//    if (root == NULL) {
//        return;
//    }
//    LinkedStack *stack = createStack();
//    root->flag = 'g';
//    push(stack, root);
//    while (!isEmpty(stack)) {
//        TreeNode *top = pop(stack);
//        if (top->data == key){
//            break;
//        } else{
//            top->flag = 'p';
//            push(stack, top);
//            if (top->right != NULL) {
//                top->right->flag = 'g';
//                push(stack, top->right);
//            }
//            if (top->left != NULL) {
//                top->left->flag = 'g';
//                push(stack, top->left);
//            }
//
//        }
//    }
//
//    printf("----------\n");
//    while (!isEmpty(stack)){
//        TreeNode *top = pop(stack);
//        if (top->flag == 'p') {
//            printf("%c ", top->data);
//        }
//    }
//
//}
//
//int main (void) {
//    TreeNode * root = createTree();
//    preOrder(root);
//    printf("\n-------\n");
//    03.postOrder(root, '6');
//    return 0;
//}
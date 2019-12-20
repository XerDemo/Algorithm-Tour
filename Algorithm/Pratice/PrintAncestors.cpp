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
//    char flag; // ���������Ϣ
//}TreeNode;
//
//
//
//// ��ʽջ�ڵ㶨��
//typedef struct stackNode{
//    Ee data;     // ������
//    struct stackNode * next; // ָ����
//}StackNode;
//
//typedef struct {
//    StackNode * top; // ջ��ָ��
//    int size;        // ջ��Ԫ�ظ���  ����size��������ʹ�󳤶Ȳ����ĸ��Ӷȴ�O(N)��ΪO(1)
//    // ����Ҫ��������ջ���� ֻ��Ҫ����һ��ʱ��ά��size
//}LinkedStack;
//
//// ������ջ
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
//// ��ȡ��ʽջ��С   O(1)
//int getSize(LinkedStack * stack){
//    return stack->size;
//}
//
//
////// ��ջ�ĳ���  O(N)  ����sizeʱ
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
//// ������ʽջ�Ƿ�Ϊ��   O(1)
//int isEmpty(LinkedStack * stack){
//    return 0 == stack->size;
//}
//
//// ��ջ O(1)
//void push(LinkedStack * stack, Ee data){
//    StackNode *newNode = (StackNode *) malloc(sizeof(StackNode));
//    newNode->data = data;
//    newNode->next = stack->top;
//    stack->top = newNode;
//    stack->size++;
//}
//
//
//// ��ջ  O(1)
//Ee pop(LinkedStack * stack){
//    if (isEmpty(stack)){
//        printf("LinkStack is empty, pop is failed.\n");
//        return NULL;
//    }
//    StackNode * delNode = stack->top; // ����ջ�ڵ�
//    Ee res= delNode->data; // ��ջ�ڵ��������
//    stack->top = delNode->next; // ջ��ָ��ָ�����ջ�ڵ�ĺ�һ���ڵ�
//    free(delNode); // �ͷŴ���ջ�ڵ�
//    delNode = NULL;
//    stack->size--;
//    return res;
//}
//
//// ��ȡջ��Ԫ��  O(1)
//Ee peek(LinkedStack * stack){
//    if (isEmpty(stack)){
//        printf("peek failed. LinkedStack is empty.\n");
//        return NULL;
//    }
//    return stack->top->data;
//}
//
//// �ݹ������壺���򴴽�������
//TreeNode * createTree(){
//    TreeNode * root = (TreeNode *)malloc(sizeof(TreeNode));
//    E val;
//    scanf("%c", &val);
//    getchar();
//    if (val == '^') {
//        return NULL;
//    }
//    root->data = val;   // ���ʸ�
//    printf("%c�����ӣ�\n", root->data);
//    root->left = createTree();
//    printf("%c���Һ��ӣ�\n", root->data);
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
////// �ݹ������壺������rootΪ���ڵ�Ķ����� �Ƿ���key
////bool printAncestor(TreeNode * root, int key){
////    if (root == NULL) {    // ����(�����˵ݹ鵽��ײ�Ҷ�ӽ�������������NULL)
////        return false;
////    }
////    if (root->data == key) {  // �ݹ��������֮һ
////        return true;
////    }
////
////    bool left = printAncestor(root->left, key);  // �ݹ��������Ƿ���key
////    bool right = printAncestor(root->right, key); // �ݹ��������Ƿ���key
////    if (left || right) { // ֻҪ��������һ�ߺ���key  ��ôroot�������Ƚ��
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
//#include <stdio.h>
//#include <stdlib.h>
//
//#define E int
//typedef struct Node{
//    E data;
//    struct Node * left;
//    struct Node * right;
//}TreeNode;
//
//TreeNode *tail = NULL;   // 传递全局的尾指针  加入尾指针后  添加到链表尾O(1)
//                         // 或者是往头部插入数据的链表(栈)  只用头指针添加元素O(1)
//
//// 递归宏观语义：先序创建二叉树
//TreeNode * createTree(){
//    TreeNode * root = (TreeNode *)malloc(sizeof(TreeNode));
//    E val;
//    scanf("%d", &val);
//    getchar();
//    if (val == 0) {
//        return NULL;
//    }
//    root->data = val;   // 访问根
//    printf("%d的左孩子：\n", root->data);
//    root->left = createTree();
//    printf("%d的右孩子：\n", root->data);
//    root->right = createTree();
//    return root;
//}
//
//void preOrder(TreeNode * root){
//    if (root == NULL) {
//        return;
//    }
//
//    if (root->left == NULL && root->right == NULL) {
//        printf("left: %d \n", root->data);
//        tail->right = root;
//        tail = root;
//    }
//    preOrder(root->left);
//    preOrder(root->right);
//}
//
//void printLink(TreeNode * head) {
//    TreeNode *curNode = head->right;
//    while (curNode != NULL) {
//        printf("%d", curNode->data);
//        if (curNode->right != NULL){
//            printf("-> ");
//        }
//        curNode = curNode->right;
//    }
//}
//
//int main (void) {
//    TreeNode * root = createTree();
//    TreeNode *head = (TreeNode *) malloc(sizeof(TreeNode));
//    tail = head;
//    tail->right = NULL;
//
//    preOrder(root);
//    printLink(head);
//    return 0;
//}
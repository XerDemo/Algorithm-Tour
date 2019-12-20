//#include <stdio.h>
//#include <stdlib.h>
//#include "LoopQueue.h"
//
//#define E int
//
//// 递归宏观语义：先序创建二叉树
//TreeNode * createTree(){
//    TreeNode * root = (TreeNode *)malloc(sizeof(TreeNode));
//    E val;
//    scanf("%d", &val);
////    getchar();
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
//    printf("%d ", root->data);
//    preOrder(root->left);
//    preOrder(root->right);
//}
//
//void deleteTree(TreeNode * root) {
//    if (root == NULL) {
//        return;
//    }
//    deleteTree(root->left);
//    deleteTree(root->right);
//    free(root);
//}
//
//void search(TreeNode * root, E key) {
//    if (root == NULL) {
//        return;
//    }
//    LoopQueue *queue = initQueue();
//    if (root->data == key) {
//        deleteTree(root);
//        exit(0);
//    }
//    enqueue(queue, root);
//    while (!isEmpty(queue)) {
//        TreeNode *front = dequeue(queue);
//        if (front->left != NULL) {
//            if (front->left->data == key) {
//                deleteTree(front->left);
//                front->left = NULL;
//            } else{
//                enqueue(queue, front->left);
//            }
//        }
//        if (front->right != NULL) {
//            if (front->right->data == key) {
//                deleteTree(front->right);
//                front->right = NULL;
//            } else{
//                enqueue(queue, front->right);
//            }
//        }
//    }
//}
//
//int main (void) {
//    TreeNode * root = createTree();
//    search(root, 2);
//    return 0;
//}
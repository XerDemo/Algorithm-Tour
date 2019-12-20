//
//#include<stdio.h>
//#include <stdlib.h>
//
//typedef struct Node{
//    int data;
//    struct Node * left ;
//    struct Node* right;
//}TreeNode;
//
//
//void revise(TreeNode ** node){
//    free((*node));
//    *node = NULL;
////    free(node);
////    node = NULL;
//}
//
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
//int main()
//{
//    TreeNode * root = (TreeNode *) malloc (sizeof(TreeNode));
//    root->data = 1;
//    root->left = root->right = NULL;
//
//    TreeNode * leftNode = (TreeNode *) malloc (sizeof(TreeNode));
//    leftNode->data = 2;
//    leftNode->left = leftNode->right = NULL;
//
//    root->left = leftNode;
//    free(leftNode);
//    leftNode = NULL;
//
//    preOrder(root);
//}
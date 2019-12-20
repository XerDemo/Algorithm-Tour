//#include <iostream>
//#include "queue"
//#include "stack"
//#include "string.h"
//
//#define E int
//using namespace std;
//
//typedef struct Node {
//    E data;
//    struct Node *left;
//    struct Node *right;
//} TreeNode;
//
//void preOrderTraverse(TreeNode * root){
//    if (root == NULL) {
//        return;
//    }
//    cout << root->data << "  ";
//    preOrderTraverse(root->left);
//    preOrderTraverse(root->right);
//}
//
//
//// 递归宏观语义：返回先序序列和后序序列建立的二叉树
//TreeNode *buildTree(int *preOrder, int preStart, int preEnd, int *inOrder,int inStart, int inEnd)  {
//    if (preOrder == NULL || inOrder == NULL) {
//        return NULL;
//    }
//    if (preStart > preEnd || inStart > inEnd) {
//        return NULL;
//    }
//    int index = inStart; // index记录preOrder[preStart] 对应在中序中的数组下标
//    TreeNode *root = (TreeNode *) malloc(sizeof(TreeNode));
//    root->data = preOrder[preStart];
//    root->left = root->right = NULL;
//    for (int i = inStart; i < inEnd; ++i) {
//        if (inOrder[i] == root->data) {
//            index = i; // 寻找到preOrder[preStart]在中序对应数组下标
//            break;
//        }
//    }
//    root->left = buildTree(preOrder, preStart + 1, preEnd, inOrder, inStart, index - 1);
//    root->right = buildTree(preOrder, preStart + (index - inStart) + 1, preEnd, inOrder, index + 1, inEnd);
//    return root;
//}
//
//
//int main(void) {
//    E preOrder[5] = {3, 9, 20, 15, 7};
//    E inOrder[5] = {9, 3, 15, 20, 7};
//    TreeNode * root = buildTree(preOrder, 0, 4, inOrder, 0, 4);
//    preOrderTraverse(root);
//    return 0;
//}
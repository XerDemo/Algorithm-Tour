//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//
//#define Element TreeNode *
//typedef struct Node{
//    char data[10];
//    struct Node * left;
//    struct Node * right;
//}TreeNode;
//
//
//// 递归宏观语义：先序创建二叉树
//TreeNode * createTree(){
//    TreeNode * root = (TreeNode *)malloc(sizeof(TreeNode));
//    char val[10];
//    gets(val);
//    if (strcmp(val,"^") == 0) { // 判断字符串是否相等 strcmp
//        return NULL;
//    }
//    strcpy(root->data, val);
//    printf("%s的左孩子：\n", root->data);
//    root->left = createTree();
//    printf("%s的右孩子：\n", root->data);
//    root->right = createTree();
//    return root;
//}
//
//// 一开始错误的想法： 就是先后序遍历数 得到后序表达式 再由后序求中序
//// 太蛮烦  只要对树进行中序遍历 加上括号
//void inOrder(TreeNode * root, int depth){
//
//    if (root == NULL) {
//        return;
//    }
//    if (root->left == NULL && root->right == NULL) {
//        printf("%s", root->data);
//        return;
//    }
//    if (depth > 1) {
//        printf("(");
//    }
//    inOrder(root->left, depth + 1);
//    printf("%s", root->data);
//    inOrder(root->right, depth + 1);
//    if (depth > 1) {
//        printf(")");
//    }
//}
//
//int main (void) {
//    TreeNode * root = createTree();
//    inOrder(root, 1);
//    return 0;
//}
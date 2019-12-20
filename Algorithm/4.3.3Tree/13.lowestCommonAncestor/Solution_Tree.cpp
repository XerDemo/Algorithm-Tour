//#include <iostream>
//#include <stdlib.h>
//#include <stack>
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
//
//TreeNode *createTree() {
//    TreeNode *root = (TreeNode *) malloc(sizeof(TreeNode));
//    E val;
//    cin >> val;
//    if (val == 0) {
//        return NULL;
//    }
//    root->data = val;
//    cout << root->data << "->left:" << endl;
//    root->left = createTree();
//    cout << root->data << "->right:" << endl;
//    root->right = createTree();
//    return root;
//}
//
//void preOrder(TreeNode *root) {
//    if (root == NULL) {
//        return;
//    }
//    cout << root->data << "  ";
//    preOrder(root->left);
//    preOrder(root->right);
//}
//
//// 递归宏观语义：返回二分搜索树中p和q的最近公共祖先结点
//TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//    if (root == NULL || p == NULL || q == NULL) { // 树空 p空 q空
//        return NULL;
//    }
//    if (p == root || q == root) { // ① p或q就是root
//        return root;
//    }
//
//    TreeNode * left = lowestCommonAncestor(root->left, p , q);
//    TreeNode * right = lowestCommonAncestor(root->right, p , q);
//    // ② p和q分别在root两侧
//    if (left != NULL && right != NULL) {
//        return root;
//    }
//    // ③ p和q同时在root的一侧
//    return left == NULL ? right : left;
//}
//
//
//int main(void) {
//    TreeNode *root = createTree();
//
//
//    return 0;
//}

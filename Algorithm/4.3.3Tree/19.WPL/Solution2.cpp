//#include <iostream>
//#include "queue"
//
//#define E int
//using namespace std;
//
//typedef struct Node {
//    E weight;
//    struct Node *left;
//    struct Node *right;
//} TreeNode;
//
//TreeNode *createTree() {
//    TreeNode *root = (TreeNode *) malloc(sizeof(TreeNode));
//    E val;
//    cin >> val;
//    if (val == 0) {
//        return NULL;
//    }
//    root->weight = val;
//    cout << root->weight << "->left:" << endl;
//    root->left = createTree();
//    cout << root->weight << "->right:" << endl;
//    root->right = createTree();
//    return root;
//}
//
//// 递归宏观语义：返回以root为根节点的二叉树的WPL
//int WPL(TreeNode * root, int depth) {
//    if (root == NULL){
//        return 0;
//    }
//    if (root->left == NULL && root->right == NULL) {
//        return root->weight * (depth - 1);
//    }
//    return WPL(root->left, depth + 1) + WPL(root->right, depth + 1);
//}
//
//int main(void) {
//    TreeNode *root = createTree();
//    cout << "WPL: " << WPL(root,1) << endl;
//    return 0;
//}

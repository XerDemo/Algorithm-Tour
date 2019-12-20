//#include <iostream>
//#include <queue>
//
//#define E int
//using namespace std;
//
//typedef struct Node {
//    E data;
//    struct Node *left;
//    struct Node *right;
//    int lTag;
//    int rTag;
//} TreeNode;
//
//// 递归宏观语义：先序创建二叉树
//TreeNode *createTree() {
//    TreeNode *root = (TreeNode *) malloc(sizeof(TreeNode));
//    E val;
//    cin >> val;
//    if (val == 0) {
//        return NULL;
//    }
//    root->data = val;   // 访问根
//    cout << root->data << "->left:" << endl;
//    root->left = createTree();
//    cout << root->data << "->right:" << endl;
//    root->right = createTree();
//    return root;
//}
//
////TreeNode * inThread(TreeNode * root, TreeNode * pre){
////    if (root == NULL) {
////        return root;
////    }
////    inThread(root->left, pre);  // 线索化左子树
////    if (root->left == NULL) { // 左子树为空 创建前驱线索
////        root->left = pre;
////        root->lTag = 1;
////    }
////    if (pre != NULL && pre->right == NULL){ // 创建前驱节点的后继线索
////        pre->right = root;
////        pre->rTag = 1;
////    }
////    pre = root; // 更新pre
////    inThread(root->right, pre);
////    cout << "pre - " << pre->data;
////    return root;
////}
//
//
//TreeNode *inThread(TreeNode *root, TreeNode *&pre) {
//    if (root == NULL) {
//        return root;
//    }
//    inThread(root->left, pre);  // 线索化左子树
//    if (root->left == NULL) { // 左子树为空 创建前驱线索
//        root->left = pre;
//        root->lTag = 1;
//    }
//    if (pre != NULL && pre->right == NULL) { // 创建前驱节点的后继线索
//        pre->right = root;
//        pre->rTag = 1;
//    }
//    pre = root; // 更新pre
//    inThread(root->right, pre);
//    return root;
//}
//
//int main(void) {
//    TreeNode *root = createTree();
//    TreeNode *pre = NULL;
//    root = inThread(root, pre);
//    pre->right = NULL;
//    pre->rTag = 1;
//    return 0;
//}
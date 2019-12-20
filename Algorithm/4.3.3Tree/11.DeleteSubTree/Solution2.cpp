//#include <iostream>
//#include <stdlib.h>
//#include <queue>
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
//
//// 递归宏观语义：返回key的前驱节点
//TreeNode * findPreNode(TreeNode * root, E key) {
//    if (root == NULL) {
//        return NULL;
//    }
//    if (root->left != NULL && root->left->data == key) {
//        return root;
//    }
//    if (root->right != NULL && root->right->data == key) {
//        return root;
//    }
//    TreeNode * left = findPreNode(root->left, key);
//    TreeNode * right =  findPreNode(root->right, key);
//    return left == NULL ? right : left;  // 重复?
//}
//
//// 递归宏观语义：删除以root为根的二叉树
//void freeTree(TreeNode * root){
//    if (root == NULL) {
//        return;
//    }
//    freeTree(root->left);
//    freeTree(root->right);
//    free(root);
//    root = NULL;
//}
//
//// 缺陷：建立在二叉树所有节点值不重复的情况下
//void deleteSubTree(TreeNode * root,E key){
//    if (root == NULL) {
//        return ;
//    }
//    if (root->data == key) {  // 如果根节点就与key相等
//        freeTree(root); // 删除整个树
//        root = NULL; // 根节点置为NULL  在删除节点时 前驱节点的对应指针域做相应操作
//    }else {
//        TreeNode * preNode = findPreNode(root, key); // key的前驱节点
//        if (preNode->left->data == key) { // 在前驱节点的左子树
//            freeTree(root->left); // 递归删除key所在树
//            preNode->left = NULL; // 前驱节点 相应 置为NULL
//        }
//
//        if(preNode->right->data == key) { // 在前驱节点的右子树
//            freeTree(root->right); // 递归删除key所在树
//            preNode->right = NULL; // 前驱节点 相应 置为NULL
//        }
//    }
//}
//
//int main(void) {
//    TreeNode *root = createTree();
//    preOrder(root);
//    cout << "\n----------" << endl;
//    deleteSubTree(root, 2);  // 缺陷：建立在二叉树所有节点值不重复的情况下
//    preOrder(root);
//    cout << "\n----------" << endl;
//
//    return 0;
//}

//#include <iostream>
//#include <queue>
//
//#define E int
//using namespace std;
//
//typedef struct Node{
//    E data;
//    struct Node * left;
//    struct Node * right;
//}TreeNode;
//
//// 递归宏观语义：先序创建二叉树
//TreeNode * createTree(){
//    TreeNode * root = (TreeNode *)malloc(sizeof(TreeNode));
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
//void preOrder(TreeNode * root) {
//    if (root == NULL) {
//        return;
//    }
//    cout << root->data << " " ;
//    preOrder(root->left);
//    preOrder(root->right);
//}
//
//// 递归宏观语义：返回将以root为根节点的二叉树左右孩子互换后的树
//TreeNode* invertTree(TreeNode* root) {
//    if (root == NULL) {
//        return NULL;
//    }
//    TreeNode *temp = root->left;
//    root->left = invertTree(root->right);
//    root->right = invertTree(temp);
//    return root;
//}
//
//
//int main(void) {
//    TreeNode *root = createTree();
//    root = invertTree(root);
//    preOrder(root);
//    return 0;
//}
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
//// 递归宏观语义：返回以root为根的二叉树的双分支节点个数
//int DoubleNum(TreeNode * root){
//    if (root == NULL) {
//        return 0;
//    }
//    if (root->left != NULL && root->right != NULL) {
//        return 1 + DoubleNum(root->left) + DoubleNum(root->right);
//    }
//    return DoubleNum(root->left) + DoubleNum(root->right);
//}
//
//
//// 先序遍历求双分支节点
//int preOrder(TreeNode * root){
//    static int res = 0; // 全局静态变量
//    if (root == NULL) {
//        return 0;
//    }
//    if (root->left!= NULL && root->right != NULL) {  // 根
//        res++;
//    }
//    preOrder(root->left); // 左
//    preOrder(root->right); // 右
//    return res;
//}
//
//
//int main(void) {
//    TreeNode *root = createTree();
//    cout << "Double: " << DoubleNum(root) << endl;
//    cout << "Double: " << preOrder(root) << endl;
//    return 0;
//}
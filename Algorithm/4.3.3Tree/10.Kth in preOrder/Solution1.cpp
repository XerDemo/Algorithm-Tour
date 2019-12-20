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
//void preOrder(TreeNode * root, int k, int * res) {
//    static int NodeCount = 0;
//    if (root == NULL || k <= 0) {
//        return ;
//    }
//    NodeCount++;
//    if (NodeCount == k) {
//        *res = root->data;
//        return;
//    }
//    preOrder(root->left,k,res);
//    preOrder(root->right, k, res);
//}
//
//// 递归宏观：返回先序遍历中的第k个节点值
//int preOrder2(TreeNode * root, int k) {
//    static int NodeCount = 0;
//    if (root == NULL || k <= 0) {
//        return -9999999;  // 取理论上娶不到的值
//    }
//    NodeCount++;
//    if (NodeCount == k) {
//        return root->data;
//    }
//    int left = preOrder2(root->left,k);
//    int right = preOrder2(root->right, k);
//    return left == -9999999 ? right : left;
//}
//
//
//int main(void) {
//    TreeNode *root = createTree();
//    int res = 0;
//    cout << "Num: " << preOrder2(root, 6) << endl;
//    return 0;
//}
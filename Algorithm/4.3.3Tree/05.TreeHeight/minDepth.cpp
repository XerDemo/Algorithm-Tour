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
//// 递归宏观语义：先序创建二叉树
//TreeNode *createTree() {
//    TreeNode *root = (TreeNode *) malloc(sizeof(TreeNode));
//    E val;
//    cin >> val;
//    if (val == 0) {
//        return NULL;
//    }
//    root->data = val;   // 访问根
//    cout << root->data << " -> left:" << endl;
//    root->left = createTree();
//    cout << root->data << " -> right:" << endl;
//    root->right = createTree();
//    return root;
//}
//
//// 求树的最小高度
//// BFS  域最大高度不同 ：发现叶子节点 就返回depth
//// 时间复杂度O(N) 空间复杂度：O(M) M：queue size
//int minDepth(TreeNode* root) {
//    if (root == NULL) {
//        return 0;
//    }
//    int depth = 0; // 树深度
//    int size = 0;  // 当前depth下节点的个数
//    queue<TreeNode *> queue;
//    queue.push(root);
//    while (queue.size() != 0) {
//        depth++;
//        size = queue.size();
//        for (int i = 0; i < size; ++i) {
//            TreeNode *front = queue.front();
//            queue.pop();
//            if (front->left == NULL && front->right == NULL) { // 发现叶子节点 最小高度 终止
//                return depth;
//            }
//            if (front->left != NULL) {
//                queue.push(front->left);
//            }
//            if (front->right != NULL) {
//                queue.push(front->right);
//            }
//        }
//    }
//    return depth;
//}
//
//// 递归宏观语义：返回以root为根节点的二叉树最小深度
//// 时间复杂度O(N)  空间复杂度O(N) 系统栈大小
//int minDepth2(TreeNode *root) {
//    if (root == NULL) { // 树空(包括叶子节点左右孩子为NULL)
//        return 0;
//    }
//    if (root->left == NULL && root->right != NULL) {
//        return 1 + minDepth2(root->right);
//    }
//    if (root->right == NULL && root->left != NULL) {
//        return 1 + minDepth2(root->left);
//    }
//    int leftDepth = minDepth2(root->left);
//    int rightDepth = minDepth2(root->right);
//    return leftDepth < rightDepth ? leftDepth + 1 : rightDepth + 1;
//}
//
//int main(void) {
//    TreeNode *root = createTree();
//    cout << "minDepth:" << minDepth(root) << endl;
//    cout << "minDepth:" << minDepth2(root) << endl;
//    return 0;
//}
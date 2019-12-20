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
//// 求树的最大高度
//// BFS 用depth记录树的深度  遍历完二叉树后 返回depth
//// 时间复杂度O(N) 空间复杂度：O(M) M：queue size
//int maxDepth(TreeNode* root) {
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
//// 递归宏观语义：返回以root为根节点的二叉树最大深度
//// 时间复杂度O(N)  空间复杂度O(N) 系统栈大小
//int maxDepth2(TreeNode *root) {
//    if (root == NULL) { // 树空(包括叶子节点左右孩子为NULL)
//        return 0;
//    }
//    int leftDepth = maxDepth2(root->left);  // 左子树最大深度
//    int rightDepth = maxDepth2(root->right); // 右子树最大深度
//    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1; // max(左子树深度，右子树深度) + 1根节点
//}
//
//int main(void) {
//    TreeNode *root = createTree();
//    cout << "maxDepth:" << maxDepth(root) << endl;
//    cout << "maxDepth:" << maxDepth2(root) << endl;
//    return 0;
//}
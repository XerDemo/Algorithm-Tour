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
//void preOrder(TreeNode *root) {
//    if (root == NULL) {
//        return;
//    }
//    cout << root->data << " ";
//    preOrder(root->left);
//    preOrder(root->right);
//}
//
//// BFS 在将左右孩子入队的时候 将左右孩子互换
//TreeNode *invertTree(TreeNode *root) {
//    if (root == NULL) {
//        return NULL;
//    }
//    queue<TreeNode *> queue;
//    queue.push(root);
//    while (queue.size() != 0) {
//        TreeNode *front = queue.front();
//        queue.pop();
//
//        // 交换左右孩子
//        TreeNode *temp = front->left;
//        front->left = front->right;
//        front->right = temp;
//
//        if (front->left != NULL) {
//            queue.push(front->left);
//        }
//        if (front->right != NULL) {
//            queue.push(front->right);
//        }
//    }
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
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
//// 层次遍历是从上到下 左到右 题目要求下到上 右到左 这明显是倒着来 利用栈
//// 基本思想：按照正常的层次遍历来 将出队元素压入栈中 层次遍历完整颗树后 将栈内元素出栈就是从下到上 从右到左的顺序
//void leverOrder_1(TreeNode *root) {
//    if (root == NULL) {
//        return;
//    }
//    stack<int> stack;   // 存放出队元素
//    queue<TreeNode *> queue;
//    queue.push(root); // 根节点入队
//    while (!queue.empty()) {
//        TreeNode *front = queue.front(); // 获取队首元素
//        queue.pop();
//        stack.push(front->data); // 出队元素入栈
//        if (front->left != NULL) {
//            queue.push(front->left);
//        }
//        if (front->right != NULL) {
//            queue.push(front->right);
//        }
//    }
//
//    while (stack.size() != 0) {  // 栈中集合出栈
//        cout << stack.top() << "  ";
//        stack.pop();
//    }
//
//}
//
//// 将题目改为：自下向上 自左向右
//// 基本思想；在BFS的基础上 (0<=i<=n) 将第i层的节点全部存放在一个vector || 链表 || queue,最后将存放第i层的vector压入栈中
////          最后栈中vector出栈，并挨个访问vector中的元素就是答案
//void levelOrder_2(TreeNode *root) {
//    if (root == NULL) {
//        return;
//    }
//    stack<vector<int>> stack;
//    queue<TreeNode *> queue;
//    queue.push(root);
//    int depth = 0; // 遍历到二叉树当前的深度
//    int size = 0; //  depth层的节点个数
//    while (!queue.empty()) {
//        vector<int> resVector; // 存放当前节点数据的动态数组
//        depth++; // 深度+1
//        size = queue.size(); // 该层节点个数
//        for (int i = 0; i < size; ++i) {
//            TreeNode * front = queue.front();
//            queue.pop();
//            resVector.push_back(front->data); // 将第depth层的节点加入resVector
//            if (front->left != NULL) {
//                queue.push(front->left);
//            }
//            if (front->right != NULL) {
//                queue.push(front->right);
//            }
//        }
//        stack.push(resVector); // 将该层存放所有节点的集合入栈
//    }
//
//    while (stack.size() != 0) {
//        for (int i : stack.top()) {
//            cout << i << " ";
//        }
//        stack.pop();
//    }
//}
//
//
//int main(void) {
//    TreeNode *root = createTree();
//    leverOrder_1(root); // 自下向上 自右向左
//    printf("\n");
//    levelOrder_2(root); // 自下向上 自左向右
//    return 0;
//}
//

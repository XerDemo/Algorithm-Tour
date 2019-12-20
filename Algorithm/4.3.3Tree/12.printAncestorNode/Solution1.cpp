//#include <iostream>
//#include <stdlib.h>
//#include <stack>
//#include <vector>
//
//#define E int
//using namespace std;
//
//typedef struct Node {
//    E data;
//    int flag; // 0:访问  1:打印
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
//vector<int> printAncestor(TreeNode *root, E key) {
//    vector<int> res;  // 存放路径
//    if (root == NULL || root->data == key) { // 如果根节点为空 或者 key就是根节点 则没有祖先节点
//        return res;
//    }
//    stack<TreeNode *> s;
//    root->flag = 0;
//    s.push(root); // 根节点入栈 并置为访问
//    while (s.size() != 0) { // 栈不空
//        TreeNode *top = s.top(); // 栈顶元素
//        s.pop(); // 出栈
//
//        // 如果栈顶元素就是key  则将站内所有打印状态的节点  加入到res
//        if (key == top->data) {
//            cout << " res : " << endl;
//            while (s.size() != 0) {
//
//                if (s.top()->flag == 1) {
////                    res.push_back(s.top()->data);
//                    cout << s.top()->data << endl;
//                }
//                s.pop();
//            }
//        } else { // 栈顶元素不是key
//            // 递归后序 ：左 右 根  栈模拟递归： 入栈顺序 根 右 左  访问顺序 左右根
//            if (top->flag != 1) { // 必须加这个 很重要
//                top->flag = 1;
//                s.push(top);
//            }
//
//            if (top->right != NULL) { // 右子树 入栈
//                top->right->flag = 0;
//                s.push(top->right);
//            }
//            if (top->left != NULL) { // 左子树 入栈
//                top->left->flag = 0;
//                s.push(top->left);
//            }
//        }
//    }
//    return res;
//}
//
//
//int main(void) {
//    TreeNode *root = createTree();
////    preOrder(root);
//
//    vector<int> res = printAncestor(root, 10);
//
////    for (int i : res) {
////        cout << i << "  " << endl;
////    }
//    return 0;
//}

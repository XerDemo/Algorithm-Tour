//#include <iostream>
//#include "queue"
//#include "stack"
//#include "string.h"
//
//#define E int
//using namespace std;
//
//typedef struct Node{
//    E data;
//    char s;  // 'g' 访问  'p' 打印
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
//    cout << root->data << "left:" << endl;
//    root->left = createTree();
//    cout << root->data << "right:" << endl;
//    root->right = createTree();
//    return root;
//}
//
//// 模拟系统栈  时间复杂度O(N)  空间复杂度O(N) 栈的大小
//void postOrder(TreeNode *root) {
//    if (root == NULL) {
//        return;
//    }
//    stack<TreeNode *> stack;
//    root->s = 'g'; // 根节点 状态置为访问
//    stack.push(root);
//    while (stack.size() != 0) {
//        TreeNode *top = stack.top();
//        stack.pop(); // 栈顶元素出栈
//        // 在递归遍历的顺序是 左 右 根   这里入栈顺序根 右 左  出栈时的顺序自然就是左右根了
//        if (top->s == 'p') { // 标志位 print 打印该节点
//            cout << top->data << " ";
//        } else{ // s为go 访问
//            top->s = 'p'; // 标志位 设为打印
//            stack.push(top); // 根入栈
//            if (top->right != NULL) {
//                top->right->s = 'g'; // 右子树标志设为访问
//                stack.push(top->right); // 右入栈
//            }
//            if (top->left != NULL) {
//                top->left->s = 'g'; // 左子树设为访问
//                stack.push(top->left);  // 左入栈
//            }
//        }
//    }
//}
//
//
//int main(void) {
//    TreeNode *root = createTree();
//    postOrder(root);
//    return 0;
//}
//

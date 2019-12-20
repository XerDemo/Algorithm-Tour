//#include <iostream>
//#include <stdio.h>
//
//#include <queue>
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
//    cout << root->data << "left:" << endl;
//    root->left = createTree();
//    cout << root->data << "right:" << endl;
//    root->right = createTree();
//    return root;
//}
//
//// BFS 如果遇到NULL节点 后面还有非NULL节点 说明不是完全二叉树
//bool isCompleteTree(TreeNode * root){
//    if (root == NULL) {
//        return true;
//    }
//    queue<TreeNode * > queue ;
//    queue.push(root);
//    while (queue.size()!= 0) {
//        TreeNode *front = queue.front();
//        queue.pop();
//        if (front != NULL) {
//            queue.push(front->left);
//            queue.push(front->right);
//        }else{
//            while (queue.size()!= 0) {
//                TreeNode *f = queue.front();
//                queue.pop();
//                if (f != NULL){
//                    return false;
//                }
//            }
//        }
//    }
//    return true;
//}
//
//
//int main(void) {
//    TreeNode *root = createTree();
//    cout << "isCompleteTree: " << isCompleteTree(root) << endl;
//    return 0;
//}
//

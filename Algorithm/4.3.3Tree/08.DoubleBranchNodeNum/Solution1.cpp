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
//// BFS  对出队的节点判断其左右孩子是否都存在 存在 res++
//int DoubleNum(TreeNode * root){
//    int res = 0;
//    if (root == NULL) {
//        return res;
//    }
//    queue<TreeNode *> queue;
//    queue.push(root);
//    while (queue.size() != 0) {
//        TreeNode *front = queue.front();
//        queue.pop();
//        if (front->left != NULL && front->right != NULL) {
//            res++; // 遇到左右孩子都存在 ++
//        }
//        if (front->left != NULL) {
//            queue.push(front->left);
//        }
//        if (front->right != NULL) {
//            queue.push(front->right);
//        }
//    }
//    return res;
//}
//
//int main(void) {
//    TreeNode *root = createTree();
//    cout << "Double: " << DoubleNum(root) << endl;
//    return 0;
//}
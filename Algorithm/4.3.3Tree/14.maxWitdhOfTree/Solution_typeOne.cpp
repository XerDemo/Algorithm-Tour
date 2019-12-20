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
//// 最大宽度：节点数最多的那一层节点的个数 不算NULL
//// 广度优先遍历
//int maxWitdhOfTree(TreeNode * root) {
//    int res = 0;
//    if (root == NULL) {
//        return res;
//    }
//    int depth = 0, depthWitdh = 0;
//    queue<TreeNode *> queue;
//    queue.push(root);
//    while (queue.size() != 0) {
//        depth++;
//        depthWitdh = queue.size(); // 当前层次的所有节点数
//        res = res < depthWitdh ? depthWitdh : res; // 更新最大宽度
//
//        for (int i=0; i<depthWitdh; ++i){
//            TreeNode * front = queue.front();
//            queue.pop();
//            if (front->left != NULL) {
//                queue.push(front->left);
//            }
//            if (front->right != NULL) {
//                queue.push(front->right);
//            }
//        }
//    }
//    return res;
//}
//
//int main(void) {
//    TreeNode *root = createTree();
//    cout << "maxWitdh " << maxWitdhOfTree(root) << endl;
//    return 0;
//}
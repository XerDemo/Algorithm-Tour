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
//    int idx;   // 节点的编号
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
//// 最大宽度：最右结点的位置-最左结点的位置 + 1  算上NULL
//// 广度优先遍历
//int maxWitdhOfTree(TreeNode * root) {
//    int res = 0;
//    if (root == NULL) {
//        return res;
//    }
//    queue<TreeNode *> queue ;
//    root->idx = 0;
//    queue.push(root);
//    int depth = 0, size = 0;
//    while (queue.size() != 0) {
//        depth++;  // 当前深度
//        int left = queue.front()->idx; // 当前深度的第一个节点的idx
//        size = queue.size(); // 第depth层所有节点个数(不含NULL)
//
//        for (int i = 0; i< size ; ++i) {  // 遍历该depth层的节点
//            TreeNode* front = queue.front();
//            queue.pop();
//            if (front->left != NULL) {
//                front->left->idx = front->idx * 2;
//                queue.push(front->left);
//            }
//            if (front->right != NULL) {
//                front->right->idx = front->idx * 2 + 1;
//                queue.push(front->right);
//            }
//            if (i == size -1) { // 当遍历到当前depth的最后一个节点  更新res
////                cout << "left :" << left << "  right:" << front->idx << endl;
//                res = res < (front->idx - left + 1) ? (front->idx - left + 1) : res;
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
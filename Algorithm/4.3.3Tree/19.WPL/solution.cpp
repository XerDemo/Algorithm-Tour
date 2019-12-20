//#include <iostream>
//#include "queue"
//
//#define E int
//using namespace std;
//
//typedef struct Node {
//    E weight;
//    struct Node *left;
//    struct Node *right;
//} TreeNode;
//
//TreeNode *createTree() {
//    TreeNode *root = (TreeNode *) malloc(sizeof(TreeNode));
//    E val;
//    cin >> val;
//    if (val == 0) {
//        return NULL;
//    }
//    root->weight = val;
//    cout << root->weight << "->left:" << endl;
//    root->left = createTree();
//    cout << root->weight << "->right:" << endl;
//    root->right = createTree();
//    return root;
//}
//
//// BFS 层次遍历 sum += 叶子节点的权重 * （depth - 1）
//int WPL(TreeNode * root){
//    if(root == NULL) {
//        return 0;
//    }
//    queue<TreeNode * > queue ;
//    queue.push(root);
//    int depth = 0;
//    int WPL = 0;
//    while (queue.size() != 0) {
//        depth++;
//        int levelSize = queue.size();
//        for (int i = 0; i < levelSize; ++i) {
//            TreeNode * front = queue.front();
//            queue.pop();
//            if (front->left == NULL && front->right == NULL) {
//                WPL += front->weight * (depth - 1);
//            }
//            if (front->left != NULL) {
//                queue.push(front->left);
//            }
//            if (front->right != NULL) {
//                queue.push(front->right);
//            }
//        }
//    }
//    return WPL;
//}
//
//
//int main(void) {
//    TreeNode *root = createTree();
//    cout << "WPL: " << WPL(root) << endl;
//    return 0;
//}

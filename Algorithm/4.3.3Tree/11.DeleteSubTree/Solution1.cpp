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
//    cout << root->data << "  ";
//    preOrder(root->left);
//    preOrder(root->right);
//}
//
//// 递归宏观语义：删除以root为根的树
//void deleteTree(TreeNode * root){
//    if (root == NULL) {
//        return;
//    }
//    deleteTree(root->left);
//    deleteTree(root->right);
//    free(root);
//    root = NULL;
//}
//
//// 基本思想：在层次遍历的基础上 如果发现与key相等的结点 递归删除
//// 注意：在递归函数中 并没有将front->left置为NULL || front->right置为NULL
//// 要删除节点找到其前驱节点 并且相应指针域置为NULL  具体原因见 free-顾.mp4
//void BFS(TreeNode * root, E key) {
//    if (root == NULL) {
//        return;
//    }
//    if (root->data == key) { // 如果根节点就是key 删除整颗子树
//        deleteTree(root);
//        exit(0); //
//    }
//    queue<TreeNode *> queue;
//    queue.push(root);
//    while (queue.size() != 0) {
//        TreeNode *front = queue.front();
//        queue.pop();
//        if (front->left != NULL) {
//            if (front->left->data == key) {  // 删除结点值与key相等的结点与其子树
//                deleteTree(front->left);
//                front->left = NULL;  // 将左孩子置为NULL 不能忘了这一步 front->left并没有指向NULL而是原来的空间
//            } else{ // 记得加上else 如果在if中front->left置为NULL NULL不能入队
//                queue.push(front->left);
//            }
//        }
//        if (front->right != NULL) {
//            if (front->right->data == key){
//                deleteTree(front->right);
//                front->right = NULL;
//            }else{
//                queue.push(front->right);
//            }
//        }
//    }
//}
//
//
//int main(void) {
//    TreeNode *root = createTree();
//    BFS(root, 1);
//    preOrder(root);
//    return 0;
//}
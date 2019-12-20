//#include <iostream>
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
//
//TreeNode *head = NULL;
//TreeNode *tail = head;
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
//// 基于先序遍历 中序 后序都可以 都是先左后右
//// 时间复杂度O(N)  空间复杂度O(N)
//void preOrder(TreeNode *root) {
//    if (root == NULL) {
//        return;
//    }
//    if (root->left == NULL && root->right == NULL) { // 叶子节点
//        if (head == NULL) { // 第一个节点
//            head = root;
//            tail = root;
//        }else{
//            tail->right = root;
//            tail = root;
//        }
//    }
//    preOrder(root->left);
//    preOrder(root->right);
//}
//
//void printList(TreeNode * head){
//    if (NULL == head) {
//        cout << "list is NULL." << endl;
//        return;
//    }
//    TreeNode *cur = head;
//    while (cur != NULL){
//        if (cur->right != NULL){
//            cout << cur->data << "->" ;
//        } else{
//            cout << cur->data << endl;
//        }
//        cur = cur->right;
//    }
//}
//
//
//int main(void) {
//    TreeNode *root = createTree();
//    preOrder(root);
//    printList(head);
//    return 0;
//}

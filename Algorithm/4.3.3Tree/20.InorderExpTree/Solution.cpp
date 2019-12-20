//#include <iostream>
//
//#define E char
//#define size 33
//using namespace std;
//
//typedef struct Node {
//    E data;
//    struct Node *left;
//    struct Node *right;
//} TreeNode;
//
////// 层次创建队列时 可以用数组来记住父亲节点的地址
////TreeNode *createTree(E *arr) {
////    TreeNode *root = NULL;
////    int idx = 1;
////    TreeNode *adress[100];
////    while (arr[idx] != '\0' ){
////        TreeNode * curNode = (TreeNode *) malloc(sizeof(TreeNode));
////        if (arr[idx] == '#'){
////            curNode = NULL;
////        }else{
////            curNode->data = arr[idx];
////            curNode->left = curNode->right = NULL;
////        }
////        adress[idx] = curNode;
////        if (idx == 1) {
////            root = curNode;
////        }else{
////            int faIdx = idx / 2;
////            if (idx % 2 == 0) { // 左孩子
////                adress[faIdx]->left = curNode;
////            }else {
////                adress[faIdx]->right = curNode;
////            }
////        }
////        idx++;
////    }
////    return root;
////}
//
//TreeNode *createTree() {
//    TreeNode *root = (TreeNode *) malloc(sizeof(TreeNode));
//    E val;
//    cin >> val;
//    if (val == '#') {
//        return NULL;
//    }
//    root->data = val;
//    cout << root->data << "->left:" << endl;
//    root->left = createTree();
//    cout << root->data << "->right:" << endl;
//    root->right = createTree();
//    return root;
//}
//void preOrder(TreeNode *root) {
//    if (root == NULL) {
//        return;
//    }
//    cout << root->data << "  ";
//    preOrder(root->left);
//    preOrder(root->right);
//}
//
//void inorderExp(TreeNode *root, int depth) {
//    if (root == NULL) {
//        return;
//    }
//    if (root->left == NULL && root->right == NULL) {
//        cout << root->data;
//        return;
//    }
//    if (depth > 1) {
//        cout << "(";
//    }
//    inorderExp(root->left, depth + 1);
//    cout << root->data;
//    inorderExp(root->right, depth + 1);
//    if (depth > 1) {
//        cout << ")";
//    }
//}
//
//int main(void) {
////    E arr[size] = " *+*abc-#######d################";
//    TreeNode *root = createTree();
//    preOrder(root);
//    cout << "   " << endl;
//    inorderExp(root, 1);
//    return 0;
//}

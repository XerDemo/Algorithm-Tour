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
//bool isSimilarTree(TreeNode * t1, TreeNode * t2){
//    if (t1==NULL && t2==NULL) {
//        return true;
//    }
//    if ((t1 == NULL && t2!= NULL) || (t1!= NULL && t2 == NULL) ){
//        return false;
//    }
//    return isSimilarTree(t1->left, t2->left) && isSimilarTree(t1->right, t2->right);
//}
//
//
//int main(void) {
//    TreeNode *root = createTree();
//    return 0;
//}

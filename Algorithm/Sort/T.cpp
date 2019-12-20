//#include <iostream>
//#include <stdlib.h>
//#include <algorithm>
//using namespace std;
//
////typedef struct node{
////    char left;
////    char right;
////}Tree[256];
//
//
//typedef struct node{
//    char data;
//    struct node * left;
//    struct node * right;
//}TreeNode;
//
//TreeNode *buildNode(char key) {
//    if (key == '*'){
//        return NULL;
//    }
//    TreeNode *newNode = (TreeNode *) malloc(sizeof(TreeNode));
//    newNode->data = key;
//    newNode->left = newNode->right = NULL;
//    return newNode;
//}
//
//TreeNode *find(TreeNode * root, char f){
//    if (root == NULL) {
//        return NULL;
//    }
//    if (root->data == f){
//        return root;
//    }
//    if (root->left != NULL){
//        return find(root->left, f);
//    }
//    if (root->right != NULL){
//        return find(root->right, f);
//    }
//    return NULL;
//}
//
//void preorder(TreeNode * root){
//    if (root == NULL) {
//        return;
//    }
//    cout << root->data;
//    preorder(root->left);
//    preorder(root->right);
//}
//
//int main(){
//
//    int n ;
//    cin >> n;
//    char f, l, r;
//    cin >> f >> l >> r;
//    TreeNode *root = (TreeNode *) malloc(sizeof(TreeNode));
//    root->data = f;
//    root->left = buildNode(l);
//    root->right = buildNode(r);
//
//
//    for (int i = 1; i < n; ++i) {
//        cin >> f >> l >> r;
//        TreeNode *node = find(root, f);
//        node->left = buildNode(l);
//        node->right = buildNode(r);
//    }
//
//    preorder(root);
//
//    return 0;
//}
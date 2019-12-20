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
//void preOrderTraverse(TreeNode *root) {
//    if (root == NULL) {
//        return;
//    }
//    cout << root->data << "  ";
//    preOrderTraverse(root->left);
//    preOrderTraverse(root->right);
//}
//
//TreeNode *buildTree(int *postOrder, int postStart, int postEnd, int *inOrder, int inStart, int inEnd) {
//    if (postOrder == NULL || inOrder == NULL) {
//        return NULL;
//    }
//    if (postStart > postEnd || inStart > inEnd) {
//        return NULL;
//    }
//    int index = inStart;
//    TreeNode *root = (TreeNode *) malloc(sizeof(TreeNode));
//    root->data = postOrder[postEnd];
//    root->left = root->right = NULL;
//    for (int i = inStart; i <= inEnd; ++i) {
//        if (inOrder[i] == root->data) {
//            index = i;
//            break;
//        }
//    }
//    root->left = buildTree(postOrder, postStart, postEnd - (inEnd - index) - 1, inOrder, inStart, index - 1);
//    root->right = buildTree(postOrder, postStart, postEnd - 1, inOrder, index + 1, inEnd); // 不能写成postStart + 1
//    return root;
//}
//
//
//int main(void) {
//    E postOrder[5] = {9, 15, 7, 20, 3};
//    E inOrder[5] = {9, 3, 15, 20, 7};
//    TreeNode *root = buildTree(postOrder, 0, 4, inOrder, 0, 4);
//    preOrderTraverse(root);
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//
//#define Element TreeNode *
//typedef struct Node{
//    char data[10];
//    struct Node * left;
//    struct Node * right;
//}TreeNode;
//
//
//// �ݹ������壺���򴴽�������
//TreeNode * createTree(){
//    TreeNode * root = (TreeNode *)malloc(sizeof(TreeNode));
//    char val[10];
//    gets(val);
//    if (strcmp(val,"^") == 0) { // �ж��ַ����Ƿ���� strcmp
//        return NULL;
//    }
//    strcpy(root->data, val);
//    printf("%s�����ӣ�\n", root->data);
//    root->left = createTree();
//    printf("%s���Һ��ӣ�\n", root->data);
//    root->right = createTree();
//    return root;
//}
//
//// һ��ʼ������뷨�� �����Ⱥ�������� �õ�������ʽ ���ɺ���������
//// ̫����  ֻҪ��������������� ��������
//void inOrder(TreeNode * root, int depth){
//
//    if (root == NULL) {
//        return;
//    }
//    if (root->left == NULL && root->right == NULL) {
//        printf("%s", root->data);
//        return;
//    }
//    if (depth > 1) {
//        printf("(");
//    }
//    inOrder(root->left, depth + 1);
//    printf("%s", root->data);
//    inOrder(root->right, depth + 1);
//    if (depth > 1) {
//        printf(")");
//    }
//}
//
//int main (void) {
//    TreeNode * root = createTree();
//    inOrder(root, 1);
//    return 0;
//}
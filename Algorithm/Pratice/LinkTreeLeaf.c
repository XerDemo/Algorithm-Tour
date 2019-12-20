//#include <stdio.h>
//#include <stdlib.h>
//
//#define E int
//typedef struct Node{
//    E data;
//    struct Node * left;
//    struct Node * right;
//}TreeNode;
//
//TreeNode *tail = NULL;   // ����ȫ�ֵ�βָ��  ����βָ���  ��ӵ�����βO(1)
//                         // ��������ͷ���������ݵ�����(ջ)  ֻ��ͷָ�����Ԫ��O(1)
//
//// �ݹ������壺���򴴽�������
//TreeNode * createTree(){
//    TreeNode * root = (TreeNode *)malloc(sizeof(TreeNode));
//    E val;
//    scanf("%d", &val);
//    getchar();
//    if (val == 0) {
//        return NULL;
//    }
//    root->data = val;   // ���ʸ�
//    printf("%d�����ӣ�\n", root->data);
//    root->left = createTree();
//    printf("%d���Һ��ӣ�\n", root->data);
//    root->right = createTree();
//    return root;
//}
//
//void preOrder(TreeNode * root){
//    if (root == NULL) {
//        return;
//    }
//
//    if (root->left == NULL && root->right == NULL) {
//        printf("left: %d \n", root->data);
//        tail->right = root;
//        tail = root;
//    }
//    preOrder(root->left);
//    preOrder(root->right);
//}
//
//void printLink(TreeNode * head) {
//    TreeNode *curNode = head->right;
//    while (curNode != NULL) {
//        printf("%d", curNode->data);
//        if (curNode->right != NULL){
//            printf("-> ");
//        }
//        curNode = curNode->right;
//    }
//}
//
//int main (void) {
//    TreeNode * root = createTree();
//    TreeNode *head = (TreeNode *) malloc(sizeof(TreeNode));
//    tail = head;
//    tail->right = NULL;
//
//    preOrder(root);
//    printLink(head);
//    return 0;
//}
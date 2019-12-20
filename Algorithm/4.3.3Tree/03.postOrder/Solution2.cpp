//#include <iostream>
//#include "queue"
//#include "stack"
//#include "string.h"
//
//#define E int
//using namespace std;
//
//typedef struct Node{
//    E data;
//    char s;  // 'g' ����  'p' ��ӡ
//    struct Node * left;
//    struct Node * right;
//}TreeNode;
//
//// �ݹ������壺���򴴽�������
//TreeNode * createTree(){
//    TreeNode * root = (TreeNode *)malloc(sizeof(TreeNode));
//    E val;
//    cin >> val;
//    if (val == 0) {
//        return NULL;
//    }
//    root->data = val;   // ���ʸ�
//    cout << root->data << "left:" << endl;
//    root->left = createTree();
//    cout << root->data << "right:" << endl;
//    root->right = createTree();
//    return root;
//}
//
//// ģ��ϵͳջ  ʱ�临�Ӷ�O(N)  �ռ临�Ӷ�O(N) ջ�Ĵ�С
//void postOrder(TreeNode *root) {
//    if (root == NULL) {
//        return;
//    }
//    stack<TreeNode *> stack;
//    root->s = 'g'; // ���ڵ� ״̬��Ϊ����
//    stack.push(root);
//    while (stack.size() != 0) {
//        TreeNode *top = stack.top();
//        stack.pop(); // ջ��Ԫ�س�ջ
//        // �ڵݹ������˳���� �� �� ��   ������ջ˳��� �� ��  ��ջʱ��˳����Ȼ�������Ҹ���
//        if (top->s == 'p') { // ��־λ print ��ӡ�ýڵ�
//            cout << top->data << " ";
//        } else{ // sΪgo ����
//            top->s = 'p'; // ��־λ ��Ϊ��ӡ
//            stack.push(top); // ����ջ
//            if (top->right != NULL) {
//                top->right->s = 'g'; // ��������־��Ϊ����
//                stack.push(top->right); // ����ջ
//            }
//            if (top->left != NULL) {
//                top->left->s = 'g'; // ��������Ϊ����
//                stack.push(top->left);  // ����ջ
//            }
//        }
//    }
//}
//
//
//int main(void) {
//    TreeNode *root = createTree();
//    postOrder(root);
//    return 0;
//}
//

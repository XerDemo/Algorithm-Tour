//#include <stdio.h>
//#include <stdlib.h>
//
//#define E int
//#define Element TreeNode *
//typedef struct Node{
//    E data;
//    struct Node * left;
//    struct Node * right;
//}TreeNode;
//
//
//
//
//typedef struct node {       // ��ʽ���нڵ�
//    Element  data;
//    struct node *next;
//} LinkNode;
//
//typedef struct {
//    LinkNode *front;        // ��ͷָ��
//    LinkNode *rear;         // ��βָ��
//    int size;               // ������Ԫ�ظ���  ����size��������ʹ�󳤶Ȳ����ĸ��Ӷȴ�O(N)��ΪO(1)
//    // ����Ҫ��������г��� ֻ��Ҫ����һ��ʱ��ά��size
//} LinkedQueue;
//
//// ��������
//LinkedQueue *createQueue() {
//    LinkedQueue *pQ = (LinkedQueue *) malloc(sizeof(LinkedQueue));
//    pQ->front = pQ->rear = (LinkNode *) malloc(sizeof(LinkNode));
//    pQ->rear->next = NULL;
//    pQ->size = 0;
//    return pQ;
//}
//
//// ��ȡ���д�С O(1) ���������size ����Ҫ������ʽ��������������С��ҪO(N)
//int getSize(LinkedQueue *pQ) {
//    return pQ->size;
//}
//
//// �����Ƿ�Ϊ��
//int isEmpty(LinkedQueue *pQ) {
//    // return pQ->front == pQ->rear  // ������size�ж��Ƿ�Ϊ��
//    return 0 == pQ->size;
//}
//
//
//// ���  ʱ�临�Ӷ�O(1)
//void enQueue(LinkedQueue *pQ, Element  e) {
//    LinkNode *newNode = (LinkNode *) malloc(sizeof(LinkNode)); // ���½ڵ�newNode
//    newNode->data = e;
//    newNode->next = NULL;
//    pQ->rear->next = newNode; // ��newNode�ҵ�rear����
//    pQ->rear = newNode;
//    pQ->size++;
//}
//
//// ����  O(1)
//Element deQueue(LinkedQueue *pQ) {
//    if (isEmpty(pQ)) {
//        printf("deQueue failed. LinkedQueue is empty.\n");
//        return NULL;
//    }
//    LinkNode *delNode = pQ->front->next;
//    Element  res = delNode->data;
//    pQ->front->next = delNode->next;
//    if (pQ->rear == delNode) {                // ������д�ʱֻ��һ���ڵ� ���Ӻ�
//        pQ->rear = pQ->front; // front �� rear��ָ�� NULL
//    }
//    free(delNode);
//    pQ->size--;
//    return res;
//}
//
//// �õ���ͷԪ�� O(1)
//Element getFront(LinkedQueue *pQ) {
//    if(isEmpty(pQ)){
//        printf("getFront failed. LinkedQueue is empty.\n");
//        return NULL;
//    }
//    return pQ->front->next->data;
//}
//
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
////int WPL(TreeNode * root) {
////    if (root == NULL) {
////        return 0;
////    }
////    LinkedQueue *queue = createQueue();
////    enQueue(queue, root);
////    int depth = 0;
////    int res = 0;
////    while (!isEmpty(queue)) {
////        depth++;
////        int size = getSize(queue);
////        int i;
////        for (i = 0; i < size; ++i) {
////            TreeNode *front = deQueue(queue);
////            if (front->left == NULL && front->right == NULL) {
////                res += front->data * (depth - 1);
////            }
////            if (front->left != NULL) {
////                enQueue(queue, front->left);
////            }
////            if (front->right != NULL) {
////                enQueue(queue, front->right);
////            }
////        }
////    }
////    return res;
////}
//
//
//// �ݹ������壻������rootΪ���ڵ�Ķ����� ��wpl
//// ���⣺res��ô���� ���ȫ�� ���Ǿֲ���
////      ��������ô���� res + ������ res + ������ ����ɶ
//int wpl(TreeNode * root, int depth) {
//    int res = 0;
//    if (root == NULL) {
//        return res;
//    }
//    if (root->left == NULL && root->right == NULL) {
//        printf("leaf : %d * %d\n", root->data, depth-1);
//        return root->data * (depth - 1);
//    }
//    if (root->left != NULL) {
//        int leftRes = wpl(root->left, depth + 1);
//        printf("left: %d + %d\n", res, leftRes);
//        res += leftRes;
////        return res + leftRes;
//    }
//    if (root->right != NULL) {
//        int rightRes = wpl(root->right, depth + 1);
//        printf("right: %d + %d\n", res, rightRes);
//        res += rightRes;
////        return res + rightRes;
//    }
//    return res;
//}
//
//
//int main (void) {
//    TreeNode * root = createTree();
//    printf("wpl : %d\n", wpl(root, 1));
//    return 0;
//}
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
//
//
//typedef struct node {       // ��ʽ���нڵ�
//    TreeNode* data;
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
//void enQueue(LinkedQueue *pQ, TreeNode* e) {
//    LinkNode *newNode = (LinkNode *) malloc(sizeof(LinkNode)); // ���½ڵ�newNode
//    newNode->data = e;
//    newNode->next = NULL;
//    pQ->rear->next = newNode; // ��newNode�ҵ�rear����
//    pQ->rear = newNode;
//    pQ->size++;
//}
//
//// ����  O(1)
//TreeNode* deQueue(LinkedQueue *pQ) {
//    if (isEmpty(pQ)) {
//        printf("deQueue failed. LinkedQueue is empty.\n");
//        return NULL;
//    }
//    LinkNode *delNode = pQ->front->next;
//    TreeNode* res = delNode->data;
//    pQ->front->next = delNode->next;
//    if (pQ->rear == delNode) {                // ������д�ʱֻ��һ���ڵ� ���Ӻ�
//        pQ->rear = pQ->front; // front �� rear��ָ�� NULL
//    }
//    free(delNode);
//    pQ->size--;
//    return res;
//}
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
//
//void preOrder(TreeNode * root){
//    if (root == NULL) {
//        return;
//    }
//    printf("%d ", root->data);
//    preOrder(root->left);
//    preOrder(root->right);
//}
//
//int maxWidth(TreeNode * root){
//    if (root == NULL) {
//        return 0;
//    }
//    LinkedQueue *queue = createQueue();
//    int res = 0;
//    int depth = 0;
//    enQueue(queue, root);
//    while (!isEmpty(queue)) {
//        depth++;
//        int witdh = getSize(queue);
//        int i;
//        printf("depth: %d, witdh: %d\n", depth, witdh);
//        res = res < witdh ? witdh : res;
//        for (i = 0; i < witdh; ++i) {
//            TreeNode *front = deQueue(queue);
//            if (front->left != NULL) {
//                enQueue(queue, front->left);
//            }
//            if (front->right != NULL) {
//                enQueue(queue, front->right);
//            }
//        }
//    }
//    return res;
//}
//
//int main (void) {
//    TreeNode * root = createTree();
//    preOrder(root);
//    printf("maxWith: %d\n", maxWidth(root));
//    return 0;
//}
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
//typedef struct node {       // 链式队列节点
//    TreeNode* data;
//    struct node *next;
//} LinkNode;
//
//typedef struct {
//    LinkNode *front;        // 队头指针
//    LinkNode *rear;         // 队尾指针
//    int size;               // 队列中元素个数  加入size变量可以使求长度操作的复杂度从O(N)降为O(1)
//    // 不需要遍历求队列长度 只需要花费一点时间维护size
//} LinkedQueue;
//
//// 创建队列
//LinkedQueue *createQueue() {
//    LinkedQueue *pQ = (LinkedQueue *) malloc(sizeof(LinkedQueue));
//    pQ->front = pQ->rear = (LinkNode *) malloc(sizeof(LinkNode));
//    pQ->rear->next = NULL;
//    pQ->size = 0;
//    return pQ;
//}
//
//// 获取队列大小 O(1) 如果不加入size 则需要遍历链式队列求其容量大小需要O(N)
//int getSize(LinkedQueue *pQ) {
//    return pQ->size;
//}
//
//// 返回是否为空
//int isEmpty(LinkedQueue *pQ) {
//    // return pQ->front == pQ->rear  // 不加入size判断是否为空
//    return 0 == pQ->size;
//}
//
//
//// 入队  时间复杂度O(1)
//void enQueue(LinkedQueue *pQ, TreeNode* e) {
//    LinkNode *newNode = (LinkNode *) malloc(sizeof(LinkNode)); // 建新节点newNode
//    newNode->data = e;
//    newNode->next = NULL;
//    pQ->rear->next = newNode; // 将newNode挂到rear后面
//    pQ->rear = newNode;
//    pQ->size++;
//}
//
//// 出队  O(1)
//TreeNode* deQueue(LinkedQueue *pQ) {
//    if (isEmpty(pQ)) {
//        printf("deQueue failed. LinkedQueue is empty.\n");
//        return NULL;
//    }
//    LinkNode *delNode = pQ->front->next;
//    TreeNode* res = delNode->data;
//    pQ->front->next = delNode->next;
//    if (pQ->rear == delNode) {                // 如果队列此时只有一个节点 出队后
//        pQ->rear = pQ->front; // front 和 rear都指向 NULL
//    }
//    free(delNode);
//    pQ->size--;
//    return res;
//}
//
//// 递归宏观语义：先序创建二叉树
//TreeNode * createTree(){
//    TreeNode * root = (TreeNode *)malloc(sizeof(TreeNode));
//    E val;
//    scanf("%d", &val);
//    getchar();
//    if (val == 0) {
//        return NULL;
//    }
//    root->data = val;   // 访问根
//    printf("%d的左孩子：\n", root->data);
//    root->left = createTree();
//    printf("%d的右孩子：\n", root->data);
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
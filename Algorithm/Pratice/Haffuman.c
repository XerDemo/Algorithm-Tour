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
//typedef struct node {       // 链式队列节点
//    Element  data;
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
//void enQueue(LinkedQueue *pQ, Element  e) {
//    LinkNode *newNode = (LinkNode *) malloc(sizeof(LinkNode)); // 建新节点newNode
//    newNode->data = e;
//    newNode->next = NULL;
//    pQ->rear->next = newNode; // 将newNode挂到rear后面
//    pQ->rear = newNode;
//    pQ->size++;
//}
//
//// 出队  O(1)
//Element deQueue(LinkedQueue *pQ) {
//    if (isEmpty(pQ)) {
//        printf("deQueue failed. LinkedQueue is empty.\n");
//        return NULL;
//    }
//    LinkNode *delNode = pQ->front->next;
//    Element  res = delNode->data;
//    pQ->front->next = delNode->next;
//    if (pQ->rear == delNode) {                // 如果队列此时只有一个节点 出队后
//        pQ->rear = pQ->front; // front 和 rear都指向 NULL
//    }
//    free(delNode);
//    pQ->size--;
//    return res;
//}
//
//// 得到队头元素 O(1)
//Element getFront(LinkedQueue *pQ) {
//    if(isEmpty(pQ)){
//        printf("getFront failed. LinkedQueue is empty.\n");
//        return NULL;
//    }
//    return pQ->front->next->data;
//}
//
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
//// 递归宏观语义；返回以root为根节点的二叉树 的wpl
//// 问题：res怎么设置 设成全局 还是局部？
////      返回是怎么返回 res + 左子树 res + 右子树 还是啥
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
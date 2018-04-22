#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50

/**
 *  用递归来创建二叉树树 递归遍历二叉树树
 */

typedef int elemType;                        // 给int类型取个别名 方便更改数据域的类型

typedef struct Node{
    elemType data;                           // 定义节点的数据域
    struct Node * pLChild;                   // 定义节点的左指针
    struct Node * pRChild;                   // 定义节点的右指针
}BiTNode;

typedef struct {
    BiTNode * Data[MAXSIZE];                 // 里面储存的是树节点的地址  -- 循环顺序队列
    int front;                               // 队首指针 指向的是第一个有效元素的前面一个位置
    int rear;                                // 队尾指针 指向的是最后一个有效元素的位置
}Queue;

BiTNode * createTree();                      // 采用递归的方式创建二叉树
void preOrderTraverse(BiTNode * pT);         // 先序遍历
void inOrderTraverse(BiTNode * pT);          // 中序遍历
void postOrderTraverse(BiTNode * pT);        // 后序遍历
void levelOrderTraverse(BiTNode * pT);       // 层次遍历  借助于 队列来实现

Queue * createQueue();                       // 创建队列
BiTNode *out_Queue(Queue *pQ);
int is_empty(Queue * pQ);
void in_Queue(Queue * pQ, BiTNode * pT);
int is_full(Queue * pQ);

int main(void)
{

    BiTNode * pT = createTree();
    printf("先序遍历: ");
    preOrderTraverse(pT);

    printf("\n中序遍历: ");
    inOrderTraverse(pT);

    printf("\n后序遍历: ");
    postOrderTraverse(pT);

    printf("\n层次遍历: ");
    levelOrderTraverse(pT);

}

// 按照先序遍历的顺序 递归来创建二叉树
BiTNode * createTree()
{
    BiTNode * pT;
    elemType val;
    scanf("%d", &val);

    // 如果遇到0 说明该节点为空
    if (val == 0)
    {
        pT = NULL;
    }
    else
    {
        pT = (BiTNode *) malloc(sizeof(BiTNode));
        if (!pT)
        {
            printf("malloc is failed!\n");
            exit(-1);
        }
        // 按 先序 DLR  根左右的顺序递归生成
        pT->data = val;                              // 生成根节点
        printf("请输入%d节点的左孩子：\n", pT->data);
        pT->pLChild = createTree();                // 生成该节点的左孩子
        printf("请输入%d节点的右孩子：\n", pT->data);
        pT->pRChild = createTree();                // 生成该节点的右孩子

    }
    return pT;
}


void preOrderTraverse(BiTNode * pT)
{
    // 如果pT ！= NULL
    if (pT)
    {
        printf(" %d ", pT->data);           // 先遍历根节点
        preOrderTraverse(pT->pLChild);      // 再遍历左子树
        preOrderTraverse(pT->pRChild);      // 再遍历右子树
    }
}

void inOrderTraverse(BiTNode * pT)
{
    // 如果pT ！= NULL
    if (pT)
    {
        inOrderTraverse(pT->pLChild);       // 遍历左子树
        printf(" %d ", pT->data);           // 遍历根节点
        inOrderTraverse(pT->pRChild);       // 遍历右子树
    }
}

void postOrderTraverse(BiTNode * pT)
{

    // 如果pT ！= NULL
    if (pT)
    {
        postOrderTraverse(pT->pLChild);       // 遍历左子树
        postOrderTraverse(pT->pRChild);       // 遍历右子树
        printf(" %d ", pT->data);           // 遍历根节点
    }
}

void levelOrderTraverse(BiTNode * pT)
{
    // 如果是空树  直接返回
    if (!pT)
    {
        return;
    }
    Queue *pQ = createQueue();                  // 创建队列
    in_Queue(pQ, pT);                           // 树的根节点入队
    // 只要队列不为空
    while (!is_empty(pQ))
    {
        BiTNode * p = out_Queue(pQ);            // 根节点出队
        printf(" %d ", p->data);                // 打印根节点的值
        if (p->pLChild)
        {
            in_Queue(pQ, p->pLChild);           // 将根节点的左孩子入队
        }
        if (p->pRChild)
        {
            in_Queue(pQ, p->pRChild);           // 将根节点的右孩子入队
        }

    }

}
/******************创建队列根层次遍历有关********************/
Queue * createQueue()
{
    Queue * pQ = (Queue *) malloc (sizeof(Queue));
    if (!pQ)
    {
        printf("malloc is failed!\n");
        exit(-1);
    }
    pQ->front = pQ->rear = 0;
}

int is_full(Queue * pQ)
{
    return pQ->front == (pQ->rear + 1) % MAXSIZE;
}

// 进队 只跟rear有关
void in_Queue(Queue * pQ, BiTNode * pT)
{
    if (is_full(pQ))
    {
        printf("Queue is full!\n");
        return;
    }
    pQ->rear = (pQ->rear + 1) % MAXSIZE;
    pQ->Data[pQ->rear] = pT;
}

int is_empty(Queue * pQ)
{
    return pQ->front == pQ->rear;
}

// 出对只跟 front有关
BiTNode *out_Queue(Queue *pQ)
{
    if (is_empty(pQ))
    {
        printf("Queue is empty!\n");
    }
    else
    {
        pQ->front = (pQ->front +1) % MAXSIZE;
        return pQ->Data[pQ->front];
    }
}



#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50

/**
 *  用递先序遍历的顺序 递归来创建二叉树树 递归遍历二叉树树
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

void levelOrderTraverse_1(BiTNode * pT);     // 层次遍历  用数组模拟 顺序队列   

int leafNum(BiTNode * pT);                   // 求叶节点个数   递归
int nodeNum(BiTNode * pT);                   // 统计节点总数
int treeDepth(BiTNode * pT);                 // 求二叉树的深度
BiTNode * searchTree(BiTNode * pT, elemType val);   // 查找数据元素val 返回其地址


Queue * createQueue();                       // 创建队列
BiTNode *out_Queue(Queue *pQ);               // 出队
int is_empty(Queue * pQ);                    // 队列是否为空
void in_Queue(Queue * pQ, BiTNode * pT);     // 入队
int is_full(Queue * pQ);                     // 队列是否满

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
    
    printf("\n数组模拟层次：");
	levelOrderTraverse_1(pT);
    printf("\n");

    printf("叶节点个数:%d\n", leafNum(pT));

    printf("共有节点数：%d\n", nodeNum(pT));

    printf("深度:%d\n", treeDepth(pT));

    printf("数据元素为13的地址：%p\n", searchTree(pT, 13));

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
            exit(0);
        }
        // 按 先序 DLR  根左右的顺序递归生成
        pT->data = val;                            // 生成根节点
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
        printf(" %d ", pT->data);             // 遍历根节点
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

// 数组模拟顺序队列 实现 层次遍历
void levelOrderTraverse_1(BiTNode * pT)
{
	int front, rear;                // 队头  队尾
    BiTNode *arr[100];              // 数组模拟队列
    BiTNode *p = pT;
    // 只要树不空
    if (p)
    {
        front = 0;
        arr[front] = p;            // 根节点入队
        rear = 1;
    }
    // 只要队列不空
    while (front != rear)
    {
        p = arr[front];

        front++;                   // 跟结点出队
        printf("%d  ", p->data);    // 打印根节点

        if (p->pLChild)            // 如果左孩子不空 入队 rear后移
        {
            arr[rear++] = p->pLChild;
        }
        if (p->pRChild)            // 如果左孩子不空 入队 rear后移
        {
            arr[rear++] = p->pRChild;
        }
    }
} 

// 就是在递归先序遍历的基础上 加了一个判断条件而已
int leafNum(BiTNode * pT)
{
    static int num = 0;
    if (pT)
    {
        if (pT->pLChild == NULL && pT->pRChild == NULL)     // 如果 是叶子节点
        {
            num++;                              // 统计叶节点个数
            printf("叶子节点：%d\n", pT->data);
        }
        leafNum(pT->pLChild);                   // 统计pT的左子树叶节点个数
        leafNum(pT->pRChild);                   // 统计pT的右子树叶节点个数
    }
    return num;
}

// 节点总数
int nodeNum(BiTNode * pT)
{
    static int num = 0;                         // 记录节点总数
    if (pT)
    {
        num++;
        nodeNum(pT->pLChild);
        nodeNum(pT->pRChild);
    }
    return num;
}

// 求二叉树的深度
int treeDepth(BiTNode * pT)
{
    int leftDepth, rightDepth;                  // leftDept：pT的左子数深度   rightDepth：pT的右子数深度
    if (NULL == pT)                             // 如果数空则返回 0
    {
        return 0;
    }
    leftDepth = treeDepth(pT->pLChild);
    rightDepth = treeDepth(pT->pRChild);
    if (leftDepth > rightDepth){
        return leftDepth + 1;                   // 返回左子树的深度  +  根节点：1
    } else{
        return rightDepth + 1;                  // 返回右子树深度 + 根节点
    }
}

// 在二叉树中 查找某个元素 返回其地址

BiTNode * searchTree(BiTNode * pT, int val)
{
    BiTNode * p = pT;
    if (p!=NULL)                                     // 如果树不为空
    {
        if (val= p->data)                       // 如果根节点 就是要查找的节点 直接返回根  否则，分别在左右子树查找
        {
            return p;
        }
        p = searchTree(p->pLChild,val);         // 在以p->pLChild的根节点的二叉树中递归查找数据元素val
        if (NULL != p)
        {
            return p;                           // 如果找到  返回p
        } else{
           return  p = searchTree(p->pRChild, val);
        }
    } else{
        return NULL;                            // 查找失败 返回空
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



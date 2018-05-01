#include <stdio.h>
#include <stdlib.h>

#define MAX_NODE 100                                        // 最大节点个数

typedef int elemType;                                       // 数据域元素类型

// 定义树节点
typedef struct Node{
    elemType data;                                          // 节点的数据域
    struct Node * pLChild;                                  // 节点的左指针域
    struct Node * pRChild;                                  // 节点的右指针域
}BTNode;

// 定义栈
typedef struct stack{
    BTNode* data[MAX_NODE];                                  // 存放的是节点 所以是BTNode 类型
    int top;                                                // 栈顶指针
}Stack;

// 定义队列
typedef struct {
    BTNode * Data[MAX_NODE];                 // 里面储存的是树节点的地址  -- 循环顺序队列
    int front;                               // 队首指针 指向的是第一个有效元素的前面一个位置
    int rear;                                // 队尾指针 指向的是最后一个有效元素的位置
}Queue;



BTNode * createTree();                                      // 创建二叉树
Stack * createStack();                                      // 创建顺序栈
int fullStack(Stack * pS);                                  // 判断堆栈是否满
int emptyStack(Stack *pS);                                  // 判断堆栈是否空
void push(Stack *pS, BTNode * pT);                          // 入栈
BTNode * pop(Stack *pS);                                    // 出栈

Queue * createQueue();                                      // 创建队列
BTNode *out_Queue(Queue *pQ);
int is_empty(Queue * pQ);
void in_Queue(Queue * pQ, BTNode * pT);
int is_full(Queue * pQ);

void preOrderTraverse_1(BTNode * pT);                       // 递归先序遍历    不用堆栈
void inOrderTraverse_1(BTNode * pT);                        // 递归中序遍历    不用堆栈
void postOrderTraverse_1(BTNode * pT);                      // 递归后序遍历    不用堆栈
int leafNum_1(BTNode * pT);                                 // 递归 求叶节点个数

void preOrderTraverse_2(BTNode * pT);                       // 非递归 先序遍历 使用堆栈
void inOrderTraverse_2(BTNode * pT);                        // 非递归 中序遍历 使用堆栈
//void postOrderTraverse_2(BTNode * pT);                    // 非递归 后序遍历 使用堆栈     未实现
void levelOrderTraverse(BTNode * pT);                       // 非递归层次遍历
int leafNum_2(BTNode * pT);                                 // 非递归 求叶子节点个数   对先序遍历进行修改


int main(void)
{
    BTNode * pT = createTree();
    printf("递归先序遍历:");
    preOrderTraverse_1(pT);

    printf("\n递归中序遍历:");
    inOrderTraverse_1(pT);

    printf("\n递归后序遍历:");
    postOrderTraverse_1(pT);

    printf("\n递归层次遍历:(暂无)");

    printf("\n递归叶节点的个数：%d\n", leafNum_1(pT));

    printf("\n非递归先序遍历:");
    preOrderTraverse_2(pT);

    printf("\n非递归中序遍历:");
    inOrderTraverse_2(pT);

    printf("\n非递归后序遍历:（暂无）");

    printf("\n非递归层次遍历:");
    inOrderTraverse_2(pT);

    printf("\n非递归叶节点的个数：%d\n", leafNum_2(pT));

    return 0;
}

// 按层次遍历来创建树  输入编号和节点的值
BTNode * createTree()
{
    int idx;                                                // 输入节点的编号  从1开始 (0结束)
    elemType val;                                           // 节点的数据域
    BTNode * arr[MAX_NODE];                                 // 此数组用来存  每个节点的地址
    BTNode * pT;                                            // 整个树的根节点

    while (1)
    {
        scanf("%d %d", &idx, &val);
        if (idx == 0)
        {
            break;
        }
        else
        {
            // 创建新的节点
            BTNode *pNew = (BTNode *) malloc(sizeof(BTNode));
            pNew->data = val;
            pNew->pRChild = pNew->pLChild = NULL;
            arr[idx] = pNew;                                // 将该编号为idx的节点的地址保存到   arr[idx]

            // 如果是idx==1 即整个树的根节点
            if (idx == 1)
            {
                pT= pNew;
            }
            else
            {
                int father_idx = idx / 2;                  // 编号为idx节点父亲节点的编号

                if (idx % 2 == 0)                          // 如果是左孩子
                {
                    arr[father_idx]->pLChild = pNew;
                }
                else                                       // 如果是右孩子
                {
                    arr[father_idx]->pRChild = pNew;
                }
            }
        }
    }
    return pT;
}


// 递归先序遍历
void preOrderTraverse_1(BTNode * pT)
{
    // 树非空
    if (pT)
    {
        printf("%d ", pT->data);                         // 先遍历根节点
        preOrderTraverse_1(pT->pLChild);                 // 再遍历左子树
        preOrderTraverse_1(pT->pRChild);                 // 最后遍历右子树
    }
}

// 递归中序遍历
void inOrderTraverse_1(BTNode * pT)
{
    if (pT)
    {
        inOrderTraverse_1(pT->pLChild);
        printf("%d ", pT->data);
        inOrderTraverse_1(pT->pRChild);
    }
}

// 递归后序遍历
void postOrderTraverse_1(BTNode * pT)
{
    if (pT)
    {
        postOrderTraverse_1(pT->pLChild);
        postOrderTraverse_1(pT->pRChild);
        printf("%d ", pT->data);
    }
}

// 非递归  先序遍历
void preOrderTraverse_2(BTNode * pT)
{
    BTNode *p = pT;                 // 定义一个节点接受 pT ,这样在遍历的时候 不会改变 pT的值
    Stack * pS = createStack();     // 创建一个堆栈
    while (p || !emptyStack(pS))    // 树不空 或者 堆栈不空就可以一直执行 while
    {
        while (p)                   // 树节点不空
        {
            push(pS, p);            // 只要树不空就一直 访问左子树 并将沿途的节点 入栈
            printf("%d ", p->data); // 打印根节点的值
            p = p->pLChild;
        }
        if (!emptyStack(pS))        // 此节点为空 出栈 访问右子树
        {
            p = pop(pS);
            p = p->pRChild;
        }
    }
}
// 非递归  中序遍历
void inOrderTraverse_2(BTNode * pT)
{
    BTNode * p = pT;
    Stack * pS = createStack();                         // 创建堆栈
    // 只要树不空  或者 堆栈不空 就一直执行while
    while (p || !emptyStack(pS))
    {
        // 只要树不空就一直 访问左子树 并将沿途的节点 入栈
        while (p)
        {
            push(pS, p);
            p = p->pLChild;
        }
        // 如果 堆栈不空  此时左子树空  节点出栈 打印节点 转向右子树
        if (!emptyStack(pS))
        {
            p= pop(pS);             // 注意这里是T 不能新弄一个临时节点
            printf("%d ", p->data);
            p = p->pRChild;
        }
    }
}

// 非递归层序遍历
void levelOrderTraverse(BTNode * pT)
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
        BTNode * p = out_Queue(pQ);            // 根节点出队
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

// 递归 求叶子个数   按照递归先序遍历改
int leafNum_1(BTNode * pT)
{
    static int num = 0;
    // 如果树不空
    if (pT)
    {
        if (pT->pLChild == NULL && pT->pRChild == NULL)
        {
            num++;
        }
        leafNum_1(pT->pLChild);
        leafNum_1(pT->pRChild);
    }
    return num;
}

//// 求叶子节点个数（非递归）      写法错误
//int leafNum_2(BTNode * pT)
//{
//    BTNode * p = pT;
//    int num = 0;
//    Stack *pS = createStack();
//    while (p || !emptyStack(pS))
//    {
//        while (p)
//        {
//            push(pS, p);
//            p = p->pLChild;
//        }
//        if (!emptyStack(pS))
//        {
//            p = pop(pS);
//            p = p->pRChild;
//            if (p == NULL)      // 跟非递归前序不同的是这里加了个判断条件   这一个如果执行相当于 左孩子右孩子都为NULL
//            {
//                num++;
//            }
//        }
//    }
//}

/******************创建栈**************************/
Stack * createStack()
{
    Stack *pS = (Stack *) malloc(sizeof(Stack));
    // 省略判断是否为 空
    pS->top = -1;
}

int fullStack(Stack * pS)
{
    return MAX_NODE - 1 == pS->top;
}

int emptyStack(Stack * pS)
{
    return -1 == pS->top;
}

void push(Stack * pS, BTNode * pT)
{
    if (fullStack(pS))
    {
        printf("Stack is full! push is failed\n");
        return;
    }
    pS->data[++pS->top] = pT;
}

BTNode * pop(Stack *pS)
{
    if (emptyStack(pS))
    {
        printf("Stack is empty! pop is failed!\n");
    }
    else
    {
        return pS->data[pS->top--];
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
    return pQ->front == (pQ->rear + 1) % MAX_NODE;
}

// 进队 只跟rear有关
void in_Queue(Queue * pQ, BTNode * pT)
{
    if (is_full(pQ))
    {
        printf("Queue is full!\n");
        return;
    }
    pQ->rear = (pQ->rear + 1) % MAX_NODE;
    pQ->Data[pQ->rear] = pT;
}

int is_empty(Queue * pQ)
{
    return pQ->front == pQ->rear;
}

// 出对只跟 front有关
BTNode *out_Queue(Queue *pQ)
{
    if (is_empty(pQ))
    {
        printf("Queue is empty!\n");
    }
    else
    {
        pQ->front = (pQ->front +1) % MAX_NODE;
        return pQ->Data[pQ->front];
    }
}




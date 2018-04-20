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




BTNode * createTree();                                      // 创建二叉树
Stack * createStack();                                      // 创建顺序栈
int fullStack(Stack * pS);                                  // 判断堆栈是否满
int emptyStack(Stack *pS);                                  // 判断堆栈是否空
void push(Stack *pS, BTNode * pT);                          // 入栈
BTNode * pop(Stack *pS);                                    // 出栈

void preOrderTraverse_1(BTNode * pT);                       // 递归先序遍历    不用堆栈
void inOrderTraverse_1(BTNode * pT);                        // 递归中序遍历    不用堆栈
void postOrderTraverse_1(BTNode * pT);                      // 递归后序遍历    不用堆栈

void preOrderTraverse_2(BTNode * pT);                       // 非递归 先序遍历 使用堆栈
void inOrderTraverse_2(BTNode * pT);                        // 非递归 中序遍历 使用堆栈
//void postOrderTraverse_2(BTNode * pT);                      // 非递归 后序遍历 使用堆栈



int main(void)
{
    BTNode * pT = createTree();
    printf("递归先序遍历:");
    preOrderTraverse_1(pT);

    printf("\n递归中序遍历:");
    inOrderTraverse_1(pT);

    printf("\n递归后序遍历:");
    postOrderTraverse_1(pT);

    printf("\n非递归先序遍历:");
    preOrderTraverse_2(pT);

    printf("\n非递归中序遍历:");
    inOrderTraverse_2(pT);

    return 0;
}

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



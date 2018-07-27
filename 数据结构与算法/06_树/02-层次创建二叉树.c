#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100                                // 存储二叉树地址数组的最大容量 也是二叉树的最大容量
/*
   使用 层次遍历的方式 创建二叉树
     对于一颗有n个结点的二叉树，若按如果按从上到下、从左到右的顺序给结点编号
     对于任意序号为i的结点有：
       (1)若i = 1，则序号为i的结点是根节点
          若i > 1，则序号为i的结点的父节点的序号为 [ i/2 ] (取整)
       (2)若2i ≤ n，则序号为i的结点的左孩子结点的序号为 2i
          若2i > n， 则i结点无左孩子
       (3)若2i + 1≤ n，则序号为i的结点的右孩子结点的序号为 2i+1
          若2i +1 > n，则i结点无右孩子
*/


typedef int elemType;                               // 将int类型娶个别名 叫 elemType

// 树结点
typedef struct Node{
    elemType data;
    struct Node * pLChild;
    struct Node * pRChild;
}BTNode;

// 定义循环队列
typedef struct {
    BTNode * data[MAXSIZE];                         // 存放树结点的地址
    int front;                                      // 队头指针  指向队首元素的前面一个位置
    int rear;                                       // 队尾指针  指向队列元素的最后一个位置
}cycleQueue;


BTNode * createTree();                              // 层次遍历 创建 二叉树
void preOrderTraverse(BTNode * pT);                 // 递归先序遍历二叉树
void inOrderTraverse(BTNode * pT);                  // 递归中序遍历二叉树
void postOrderTraverse(BTNode * pT);                // 递归后序遍历二叉树
void leverOrderTraverse(BTNode * pT);               // 层次遍历  需借用 队列
void leafNum(BTNode * pT);                          // 递归统计叶节点的个数 打印叶节点
int nodeNum(BTNode * pT);                           // 递归统计 二叉树的总结点数
int treeDepth(BTNode * pT);                         // 递归统计 二叉树的深度

// 循环队列
cycleQueue * createQueue();                         // 创建循环队列
void inQueue(cycleQueue * pQ, BTNode * val);        // 入队
BTNode * outQueue(cycleQueue * pQ);                 // 出队
int isFull(cycleQueue * pQ);                        // 判断循环队列是否满
int isEmpty(cycleQueue * pQ);                       // 判断队列是否空

int main(void)
{
    BTNode * pT = createTree();

    printf("递归先序遍历: ");
    preOrderTraverse(pT);

    printf("\n递归中序遍历: ");
    inOrderTraverse(pT);

    printf("\n递归后序遍历: ");
    postOrderTraverse(pT);

    printf("\n层次遍历: ");
    leverOrderTraverse(pT);

    printf("叶子结点：");
    leafNum(pT);

    printf("\n二叉树的总结点数:%d\n", nodeNum(pT));

    printf("二叉树的深度：%d\n", treeDepth(pT));
    return 0;
}

/*
 * 层次 创建二叉树
 * 基本思想： 通过输入 编号 和 值的形式来创建结点 如果编号为0 说明输入结束
 *          编号为1说明是根节点
 *          编号大于1的 如果是偶数说明是左孩子 将其挂到父亲结点的左子域  奇数说明是右孩子 挂到父亲结点的右子域
 *          此时需要一个数组 来记住父结点的地址
 */

BTNode * createTree()
{
    BTNode * pT;
    elemType val;                                   // 输入的数据
    int idx;                                        // 输入的编号
    BTNode * arr[100];                              // 辅助数组 记住 结点的地址

    scanf("%d %d", &idx, &val);
    while (idx != 0)                                // 编号是从1开始的 不可能为0  如果为0 结束
    {
        BTNode * pNew = (BTNode *) malloc(sizeof(BTNode));
        // 省略判断pNew是否为空
        pNew->data = val;
        pNew->pLChild = pNew->pRChild = NULL;
        arr[idx] = pNew;                            // 记住 结点的地址

        if (idx == 1)                               // idx == 1 说明是整个树的根节点
        {
            pT = pNew;
        }
        else
        {
            int parent_idx = idx / 2;               // 父亲结点的编号
            if (idx % 2 == 0)                       // 偶数说明是 左孩子
            {
                arr[parent_idx]->pLChild = pNew;
            }
            else                                    // 奇数说明是右孩子
            {
                arr[parent_idx]->pRChild = pNew;
            }
        }
        scanf("%d %d", &idx, &val);                 // 输入 0 0 结束
    }
    return pT;
}

// 先序递归遍历二叉树
// 图解：https://github.com/XerDemo/Algorithm-Tour/blob/master/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E4%B8%8E%E7%AE%97%E6%B3%95/Demo6_%E6%A0%91/image/Demo1_%E7%94%A8%E9%80%92%E5%BD%92%E5%85%88%E5%BA%8F%E9%81%8D%E5%8E%86%E4%BA%8C%E5%8F%89%E6%A0%91.png
void preOrderTraverse(BTNode * pT)
{
    // 递归结束条件 pT == NULL
    if (pT)                                        // 树不空
    {
        // 遍历顺序 根 左 右  (D L R)
        printf("%d ", pT->data);                    // 根
        preOrderTraverse(pT->pLChild);              // 遍历左子树
        preOrderTraverse(pT->pRChild);              // 遍历右子树
    }
}

// 中序递归遍历二叉树  这里递归的形式我换一下  过程是一样的 只是写法不一样了
void inOrderTraverse(BTNode * pT)
{
    // 递归结束 条件 pT == NULL
    if (pT == NULL)
    {
        return;
    }
    // 左 根 右 (L D R)
    inOrderTraverse(pT->pLChild);
    printf("%d ", pT->data);
    inOrderTraverse(pT->pRChild);
}


// 递归后序遍历
void postOrderTraverse(BTNode * pT)
{
    if (pT)
    {
        postOrderTraverse(pT->pLChild);
        postOrderTraverse(pT->pRChild);
        printf("%d ", pT->data);
    }
}

/*
 * 层次遍历  队列
 *   基本思想： 从整个树的根节点开始 如果树不为空 将根节点入队
 *             如果队列不为空 出队  打印出队元素的值
 *             如果出队元素左孩子不为空 入队  右孩子不为空 入队  直到队列为空为止
 */
void leverOrderTraverse(BTNode * pT)
{
    if (!pT)                                          // 如果 树为空 直接return
    {
        return;
    }
    cycleQueue *pQ = createQueue();
    inQueue(pQ, pT);                                  // 根结点入队
    // 只要队列不为空
    while (!isEmpty(pQ))
    {
        BTNode *p = outQueue(pQ);
        printf("%d ", p->data);
        if (p->pLChild)                               // 根节点的左孩子不为空 入队
        {
            inQueue(pQ, p->pLChild);
        }
        if (p->pRChild)                               // 根节点的右孩子不为空 入队
        {
            inQueue(pQ, p->pRChild);
        }
    }
    printf("\n");
}

/*
 *  递归求叶子结点数 和 叶子节点是谁
 *     基本思想：在递归遍历算法中(先序、中序、后序‘层次都行，以先序为例) 加个检测条件  如果左右孩子都为空
 *
 */
void leafNum(BTNode * pT)
{
    // 将注释去掉的话 可以统计叶子结点个数
    // static int count = 0;                              // 统计叶子结点个数 需要定义为static
    if (pT)
    {
        // 如果左右孩子都为空
        if (!pT->pLChild && !pT->pRChild)
        {
            // count++;                                   // 叶子结点数 + 1
            printf("%d ", pT->data);                      // 输出叶子结点
        }
        leafNum(pT->pLChild);
        leafNum(pT->pRChild);
    }
    // return count;
}

/*
 *  统计二叉树 总结点数
 *      基本思想： 若二叉树根不为空 计算器count++  基于递归遍历算法改造
 *                递归统计左子树结点数 递归统计右子树结点数
 */
int nodeNum(BTNode * pT)
{
    static int count = 0;                               // count 统计结点数
    if (pT)
    {
        count++;
        nodeNum(pT->pLChild);
        nodeNum(pT->pRChild);
    }

    return count;
}
/*
 * 递归求二叉树的深度
 *    基本思想： 若二叉树为空 则返回0
 *              不为空 递归统计左子树的深度   递归统计右子树的深度
 *              递归结束返回 其中深度最大的值 + 1 （+1 是算上 根节点所在的那一层）
 */
int treeDepth(BTNode * pT)
{
    int leftDepth, rightDepth, maxDepth;
    if (pT == NULL)                                    // 树为空 return 0
    {
        return 0;
    }
    leftDepth = treeDepth(pT->pLChild);                // 递归求解左子树深度
    rightDepth = treeDepth(pT->pRChild);               // 递归求解右子树深度
    maxDepth = leftDepth > rightDepth ? leftDepth : rightDepth; // 返回左右子树深度 最大的一个
    return maxDepth + 1;                               // 最大深度 + 1
}


/*******************************循环队列******************************/
cycleQueue * createQueue()
{
    cycleQueue *pQ = (cycleQueue *) malloc(sizeof(cycleQueue));
    // 省略判断pQ是否为空
    pQ->front = pQ->rear = 0;
    return pQ;
}

int isFull(cycleQueue * pQ)
{
    return (pQ->rear + 1) % MAXSIZE == pQ->front;
}

int isEmpty(cycleQueue * pQ)
{
    return pQ->rear == pQ->front;
}

void inQueue(cycleQueue * pQ, BTNode * val)
{
    if (isFull(pQ))
    {
        printf("循环队列满！入队失败！\n");
        return;
    }
    pQ->rear = (pQ->rear + 1) % MAXSIZE;
    pQ->data[pQ->rear] = val;
}

BTNode * outQueue(cycleQueue * pQ)
{
    if (isEmpty(pQ))
    {
        printf("循环队列空！出队失败！\n");
        return NULL;
    }
    pQ->front = (pQ->front + 1) % MAXSIZE;
    return pQ->data[pQ->front];
}

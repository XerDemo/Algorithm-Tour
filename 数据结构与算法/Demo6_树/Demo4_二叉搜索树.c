#include <stdio.h>
#include <stdlib.h>
/*
 * 二叉搜索树：
 *  1. 若左子树不为空，则左子树上所有结点的值小于根节点的值
 *  2. 若右子树不为空， 则右子树上所有的结点的值大于根节点的值
 *  3. 左、右子树也都是二叉排序树
 *  4. 一定是二叉树
 *  5. 一定不会有相同的结点
 *  6. 特点 其中序遍历 从小到大
 */
typedef struct node{
    int data;
    struct node * leftChild;
    struct node * rightChild;
}BSTNode;

BSTNode * createTree();                                     // 用插入结点的方式创建二叉搜索树
BSTNode * insert(BSTNode * pT, int key);                    // 插入结点
BSTNode * insert_recursion(BSTNode * pT, int key);          // 递归 插入结点
void deleteNode(BSTNode *pT, int key);                      // 删除结点   3种情况
BSTNode * search(BSTNode * pT, int key);                    // 查找关键字key
BSTNode * search_recursion(BSTNode *pT, int key);           // 递归 查找关键字 key的位置
BSTNode * findMax(BSTNode * pT);                            // 查找二叉搜索树的最大值   最右端
BSTNode * findMax_recursion(BSTNode * pT);                  // 递归 查找二叉搜索树的最大值   最右端
BSTNode * findMin(BSTNode * pT);                            // 查找二叉搜索树的最小值   最左端
BSTNode * findMin_recursion(BSTNode * pT);                  // 递归 查找二叉搜索树的最小值   最左端
void inorderTraverse(BSTNode * pT);                         // 中序遍历二叉搜索树  有序

int main(void)
{
    BSTNode * pT = createTree();
    printf("中序遍历：");
    inorderTraverse(pT);

    printf("\n最大值：%d\n", findMax(pT)->data);
    printf("递归最大值：%d\n", findMax_recursion(pT)->data);

    printf("最小值：%d\n", findMin(pT)->data);
    printf("递归最小值：%d\n", findMin_recursion(pT)->data);

//    if (search(pT, 33))
//    {
//        printf("查找成功！%d的位置：%p\n", search(pT,33)->data, search(pT,33));
//    }
//    else
//    {
//        printf("查找失败！不存在33这个结点！\n");
//    }
//
//    if (search_recursion(pT, 33))
//    {
//        printf("递归查找成功！%d的位置：%p\n", search_recursion(pT,33)->data, search_recursion(pT,33));
//    }
//    else
//    {
//        printf("递归查找失败！不存在33这个结点！\n");
//    }

    deleteNode(pT, 9);
    inorderTraverse(pT);

    return 0;
}

// 创建
BSTNode * createTree()
{
    BSTNode * pT = NULL;
    int key;

    printf("请输入关键字(结束0):");
    scanf("%d", &key);

    while (0 != key)
    {
        // pT = insert(pT, key);                            // 非递归
        pT = insert_recursion(pT, key);                     // 递归
        scanf("%d", &key);
    }
    return pT;
}

/*
 * 插入结点  插入（找前驱）
 *   基本思想：
 *      1.如果二叉搜索树此时为空 则将插入结点当成新的根节点
 *      2.若二叉搜索树非空 从树根开始找 插入的值大于根结点 往根节点右边找
 *                                  插入的值小于根节点 往根节点左边找
 *                                  插入的值等于根节点 说明之前就有这个 值 结束插入
 *                                  直到为空NULL 此时找到了要插入结点的前驱结点
 *      3.若插入结点的值大于前驱结点 接到 前驱节点的右孩子域   小于前驱结点 接到左孩子域
 */

BSTNode * insert(BSTNode * pT, int key)
{
    // pre是p的前驱
    BSTNode * p = NULL, *pre = NULL;
    BSTNode * pNew = (BSTNode * )malloc(sizeof(BSTNode));
    // 省略判断pNew是否为空
    pNew->data = key;
    pNew->leftChild = pNew->rightChild = NULL;

    // 如果是空树 建立根节点
    if (NULL == pT)
    {
        pT = pNew;
    }
    else
    {   // 不是空树
        p = pT;
        // 从树根开始找 key应该放在哪
        while (p != NULL)
        {
            if (key > p->data)
            {
                pre = p;
                p = p->rightChild;
            } else if (key < p->data)
            {
                pre = p;
                p = p->leftChild;
            } else
            {
                printf("此二叉搜索树已经有%d\n", p->data);
                return pT;
            }
        }
        // 执行到这里 已经找到了要插入结点的前驱结点
        // 如果key大于其前驱节点 挂到前驱结点的右边  反之
        if (key > pre->data)
        {
            pre->rightChild = pNew;
        } else
        {
            pre->leftChild = pNew;
        }
    }
    return pT;
}

/*
 * 递归 插入结点
 *    图解：https://github.com/XerDemo/Algorithm-Tour/blob/master/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E4%B8%8E%E7%AE%97%E6%B3%95/Demo6_%E6%A0%91/image/Demo3%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91-%E9%80%92%E5%BD%92%E6%8F%92%E5%85%A5%E5%9B%BE%E8%A7%A3.png
 */
BSTNode * insert_recursion(BSTNode * pT, int key)
{
    if (!pT)                                                             // 如果是空树 建立根节点
    {
        pT = (BSTNode *) malloc(sizeof(BSTNode));
        pT->data = key;
        pT->rightChild = pT->leftChild = NULL;
    }
    else
    {         // 找要插入元素的位置
        if (key > pT->data)
        {
            pT->rightChild = insert_recursion(pT->rightChild, key);      // 递归插入右子树
        }
        else if (key < pT->data)
        {
            pT->leftChild = insert_recursion(pT->leftChild, key);        // 递归插入右子树
        }
        else
        {
            printf("key = %d 的结点已经存在！\n", key);
        }
    }
    return pT;
}




/*
 * 查找关键字 key的位置(地址)
 *    基本思想：从树根开始找 如果key比根节点的data大 往根节点右边找
 *                        如果key比根节点的data小 往根节点左边找
 *                        如果key == 根结点的data  找到了
 *                        如果上述情况都不是 则不存在key这个结点
 */
BSTNode * search(BSTNode * pT, int key)
{
    BSTNode *p = pT;
    while (p)
    {
        if (key > p->data)
        {
            p = p->rightChild;
        }
        else if (key < p->data)
        {
            p = p->leftChild;
        }
        else     // key == p->data
        {
            return p;
        }
        /********************另外一种写法***************/
//        if (key == p->data)
//        {
//            return p;
//        }
//        p = key > p->data ? p->rightChild : p->leftChild;
    }
    // printf("没有找到！\n");
    return NULL;
}


BSTNode * search_recursion(BSTNode * pT, int key)
{
    // 递归结束条件  查找失败
    if (pT == NULL)
    {
        return NULL;
    }

    if (key > pT->data)
    {
        return search_recursion(pT->rightChild, key);          // 在右子树中递归查找
    }
    else if (key < pT->data)
    {
        return search_recursion(pT->leftChild, key);           // 在左子树中递归查找
    }
    else
    {
        return pT;                                              // 找到了
    }
}


/*
 * 查找最大值：
 *     基本思想：一路从根节点往右边查 直到 为空  最右边那个结点最是最大值
 */
BSTNode * findMax(BSTNode * pT)
{
    if (pT)
    {
        while (pT->rightChild)
        {
            pT = pT->rightChild;   // 沿右分支一直向下，直到最右端点
        }
    }
    return pT;
}
// 查找最大值 递归解法
BSTNode * findMax_recursion(BSTNode * pT)
{
    if (pT == NULL)
    {
        return NULL;             // 如果数空 返回 null
    }
    else if (!pT->rightChild)
    {
        return pT;               // 如果右子树为空 返回 pT(最右端点)
    }
    else
    {
        return findMax_recursion(pT->rightChild);  // 沿右分支继续找
    }


}


/*
 * 查找最小值：
 *     基本思想：一路从根节点往左边查 直到 为空  最左边那个结点是最小值
 */
BSTNode * findMin(BSTNode * pT)
{
    if (pT)
    {
        while (pT->leftChild)
        {
            pT = pT->leftChild;     // 沿左分支一直向下，直到最左端点
        }
    }
    return pT;
}

BSTNode * findMin_recursion(BSTNode * pT)
{
    if (pT == NULL)
    {
        return NULL;
    }
    else if (pT->leftChild == NULL)
    {
        return pT;
    }
    else
    {
        return findMin_recursion(pT->leftChild);
    }
}
/*
 * 删除结点
 *    基本思想：
 *    * 删除结点 3种情况
 *    1.删除的是叶子节点
 *        将其父节点对应的指针域 设为NULL
 *    2.删除的结点 只有一颗左子树或右子树
 *        用子树的根节点取代被删除结点
 *    3.删除的结点 有左右两颗子树  （2种方法）
 *        1）中序直接前驱法：将被删除结点的中序遍历的直接前驱结点 取代删除结点
 *        2）中序直接后继法：将被删除结点的中序遍历的直接后继结点 取代删除结点
 *        找被删除点的前驱：从被删除点的左子树 一路向右  (被删结点左子树中的最大值)
 *        找被删除点的后继：从被删除点的右子树 一路向左  (被删结点右子树中的最小值)
 *           被删点
 *        L   D    R
 *   L D  R(前驱)   L D R(后继)
 */

void deleteNode(BSTNode * pT, int key)
{
    // 查找到要删除的结点
    BSTNode *p = NULL, *pre = NULL, *child = NULL;
    p = pT;
    while (p)
    {
        if (key == p->data)
        {
            break;
        }
        pre = p;
        p = key > p->data ? p->rightChild : p->leftChild;
    }
    // 此时p指向的是待删除的结点的位置 pre是p的前驱
    if (!p)
    {
        printf("没有这个结点的存在!\n");
        return;
    }
    // 如果是叶节点  将其父节点对应的指针域 设为NULL(此时需要一个前驱结点pre来记住其父亲结点的位置)
    if (p->leftChild == NULL && p->rightChild == NULL)
    {
        // 叶节点在父节点的左边
        if (pre->leftChild == p)
        {
            pre->leftChild = NULL;
        }
        else   // 叶节点在父节点的右边
        {
            pre->rightChild = NULL;
        }
        free(p);
        p = NULL;
    }
    // 如果左右孩子都不为空
    else if (p->leftChild!=NULL && p->rightChild!=NULL)
    {
        // pTemp存放的是待删除结点的位置
        BSTNode * pTemp = p;
        // 查找右子树最左端点
        for (pre = pTemp, p = pTemp->rightChild; p->leftChild; pre = p, p = p->leftChild);
        // 此时p是中序遍历直接后续结点（待删除结点右子树中最左端点，也就是待删除结点右子树的最小值） pre是其前驱结点
        pTemp->data = p->data;                   // 中序遍历前驱结点取代被删除结点  只能数据域相等 不要动p的孩子域
        // 在p取代待删除结点时 将p在父亲结点对应的指针域置为NULL
        if (pre->leftChild == p)
        {
            pre->leftChild = NULL;
        }
        else
        {
            pre->rightChild = NULL;
        }
    }
    // 如果只有左子树为空 或 只有右子树为空
    else
    {
        // 此时需要child指向待删除结点的唯一一个子树
        child = p->leftChild ? p->leftChild : p->rightChild;
        // 将待删除结点的左子树或右子树 挂到其父节点对应的指针域
        if (pre->leftChild == p)
        {
            pre->leftChild = child;
        }
        else
        {
            pre->rightChild = child;
        }
        free(p);
        p = NULL;
    }
    // 优化 可以将三种情况对应的其父亲结点的指针域的值统一写在if else if else外面
}


// 中序遍历
void inorderTraverse(BSTNode * pT)
{
    // 如果树不空
    if (pT)
    {
        inorderTraverse(pT->leftChild);             // 递归遍历左子树
        printf("%d   ", pT->data);                  // 遍历根节点
        inorderTraverse(pT->rightChild);            // 递归遍历右子树
    }
}


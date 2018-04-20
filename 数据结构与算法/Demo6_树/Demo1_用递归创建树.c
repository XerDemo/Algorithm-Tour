#include <stdio.h>
#include <stdlib.h>

/**
 *  用递归来创建二叉树树 递归遍历二叉树树
 */

typedef int elemType;                       // 给int类型取个别名 方便更改数据域的类型

typedef struct Node{
    elemType data;                           // 定义节点的数据域
    struct Node * pLChild;                   // 定义节点的左指针
    struct Node * pRChild;                   // 定义节点的右指针
}BiTNode;

BiTNode * createTree();                      // 采用递归的方式创建二叉树
void preOrderTraverse(BiTNode * pT);         // 先序遍历
void inOrderTraverse(BiTNode * pT);          // 中序遍历
void postOrderTraverse(BiTNode * pT);        // 后序遍历

int main(void)
{

    BiTNode * pT = createTree();
    printf("先序遍历: ");
    preOrderTraverse(pT);

    printf("\n中序遍历: ");
    inOrderTraverse(pT);

    printf("\n后序遍历: ");
    postOrderTraverse(pT);

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






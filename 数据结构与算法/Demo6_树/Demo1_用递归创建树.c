#include <stdio.h>
#include <stdlib.h>
/**
 *  用递归来创建树 递归遍历树
 */

typedef struct Node{
    char data;                               // 定义节点的数据域
    struct Node * pLChild;                  // 定义节点的左指针
    struct Node * pRChild;                  // 定义节点的右指针
}BiTNode;

void createBiTree(BiTNode ** ppT);          // 采用递归的方式创建二叉树   双重指针
void preOrderTraverse(BiTNode * pT);        // 先序遍历
void inOrderTraverse(BiTNode * pT);         // 中序遍历
void postOrderTraverse(BiTNode * pT);       // 后序遍历

int main(void)
{
    // 为什么不是 BiTNode * pT = createBiTree();
    BiTNode * pT = NULL;
    createBiTree(&pT);

    printf("先序遍历: ");
    preOrderTraverse(pT);

    printf("\n中序遍历: ");
    inOrderTraverse(pT);

    printf("\n后序遍历: ");
    postOrderTraverse(pT);

}

// 按照先序 来创建
void createBiTree(BiTNode **ppT)
{
    char ch;
    scanf("%c", &ch);

    // 如果遇到'#' 说明该节点为空
    if (ch == '#')
    {
        *ppT = NULL;
    }
    else
    {
        *ppT = (BiTNode *) malloc(sizeof(BiTNode));
        // *ppT->data = ch;  *的运算符优先级跟++ 一样 比->小 此时相当于 *(ppT->data) = ch  自然会报错
        (*ppT)->data = ch;                  // 生成根节点 中 左 右
        createBiTree(&(*ppT)->pLChild);      // 生成左子树
        createBiTree(&(*ppT)->pRChild);      // 生成右子树
    }
}

// 为什么突然又变成了 单重指针
void preOrderTraverse(BiTNode * pT)
{
    // 如果pT ！= NULL
    if (pT)
    {
        printf(" %c ", pT->data);           // 先遍历根节点
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
        printf(" %c ", pT->data);           // 遍历根节点
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
        printf(" %c ", pT->data);           // 遍历根节点
    }
}






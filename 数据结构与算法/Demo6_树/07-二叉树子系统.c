#include <stdio.h>
#include <stdlib.h>
#define MAXSZIE 100

typedef char type;
typedef struct Node {
    type data;
    struct Node *pLChild;
    struct Node *pRChild;
} BiTNode;

BiTNode *createTree();                          // 递归先序创建二叉树
void preOrderTraverse(BiTNode *pT);             // 递归先序遍历
void inOrderTraverse(BiTNode *pT);              // 递归中序遍历
void postOrderTraverse(BiTNode *pT);            // 递归后序遍历
void levelOrderTraverse(BiTNode *pT);           // 数组模拟顺序队列 实现 层次遍历
int leafNum(BiTNode *pT);                       // 求叶子结点数
int NodeNum(BiTNode * pT);                      // 求结点总数
int treeDepth(BiTNode * pT);                    // 求二叉树的深度
void showTree(BiTNode * pT);                    // 凹入法 显示二叉树

int main(void)
{
    BiTNode *pT = NULL;
//    BiTNode *pT = createTree();
    int choice; 
    
    while (1)
    {
    	printf("\n               二叉树子系统                  ");
		printf("\n*********************************************");
		printf("\n*           1---------建 二 叉 树           *");
		printf("\n*           2---------凹 入 显 示           *");
		printf("\n*           3---------先 序 遍 历           *");
		printf("\n*           4---------中 序 遍 历           *");
		printf("\n*           5---------后 序 遍 历           *");
		printf("\n*           6---------层 次 遍 历           *");
		printf("\n*           7---------求 叶 子 数           *");
		printf("\n*           8---------求 结 点 数           *");
		printf("\n*           9---------求 树 深 度           *");
		printf("\n*           0---------退       出           *");
		printf("\n*********************************************");
		
		printf("\n请输入菜单号：(0-9):");
		scanf("%d", &choice);
		getchar();
		
		switch(choice)
		{
			case 1:
				printf("请输入根节点:" );
				pT = createTree();
				break;
			case 2:
				showTree(pT);
				break;
			case 3:
				printf("先序遍历：");
				preOrderTraverse(pT);
				printf("\n");
				break;
			case 4:
				printf("中序遍历：");
				inOrderTraverse(pT);
				printf("\n");
				break;
			case 5:
				printf("后序遍历：");
				postOrderTraverse(pT);
				printf("\n");
				break;
			case 6:
				printf("层次遍历：");
				levelOrderTraverse(pT);
				printf("\n");
				break;
			case 7:
			    printf("\n叶节点总数：%d\n", leafNum(pT)); 
				break;
			case 8:
				printf("总结点数：%d\n", NodeNum(pT));
				break;
			case 9:
				printf("二叉树的深度：%d\n", treeDepth(pT));
				break;
			case 0:
				exit(0);
			default:
				printf("暂无此选项！\n");
		}
	}
    return 0;
}

// 递归创建二叉树
BiTNode *createTree()
{
    BiTNode *pT;
    type ch;
    scanf("%c", &ch);
    getchar();
//	fflush(stdin);
	
    if (ch == '0')
    {
        pT = NULL;
    } else
    {
        pT = (BiTNode *) malloc(sizeof(BiTNode));
        if (!pT)
        {
            printf("malloc is failed!\n");
            exit(0);
        }
        pT->data = ch;
        printf("请输入%c的左子结点:", pT->data);
        pT->pLChild = createTree();
        printf("请输入%c的右子结点:", pT->data);
        pT->pRChild = createTree();
    }
    return pT;
}

// 递归先序遍历
void preOrderTraverse(BiTNode *pT)
{
    if (pT)
    {
        printf("%c  ", pT->data);
        preOrderTraverse(pT->pLChild);
        preOrderTraverse(pT->pRChild);
    }
}

// 递归中序遍历
void inOrderTraverse(BiTNode *pT)
{
    if (pT)
    {
        inOrderTraverse(pT->pLChild);
        printf("%c  ", pT->data);
        inOrderTraverse(pT->pRChild);
    }
}

// 递归后序遍历
void postOrderTraverse(BiTNode *pT)
{
    if (pT)
    {
        postOrderTraverse(pT->pLChild);
        postOrderTraverse(pT->pRChild);
        printf("%c  ", pT->data);
    }
}

// 数组模拟顺序队列 实现 层次遍历
void levelOrderTraverse(BiTNode *pT)
{
    int front, rear;                // 队头  队尾
    BiTNode *arr[MAXSZIE];          // 数组模拟队列
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
        printf("%c  ", p->data);    // 打印根节点

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

// 求叶子结点数
int leafNum(BiTNode *pT)
{
    static int count = 0;         // 定义成全局变量 防止被递归覆盖
    if (pT)
    {
        // 在先序遍历的前提下  加了判断时叶节点的条件
        if (!pT->pLChild && !pT->pRChild)
        {
            count++;
            printf("\n叶子结点：%c", pT->data);
        }
        leafNum(pT->pLChild);
        leafNum(pT->pRChild);
    }
    return count;
}

// 求结点总数
int NodeNum(BiTNode * pT)
{
    static int count = 0;
    if (pT)
    {
        count++;
        NodeNum(pT->pLChild);
        NodeNum(pT->pRChild);
    }
    return count;
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

// 凹入法 显示 二叉树
void showTree(BiTNode *T)
{
    BiTNode *stack[MAXSZIE],*p;
    int level[MAXSZIE][2],top,n,i,width=4;
    if(T!=NULL)
    {
        printf("\n凹入表示法：\n");
        top=1;
        stack[top]=T;
        level[top][0]=width;
        while(top>0)
        {
            p=stack[top];
            n=level[top][0];
            for(i=1;i<=n;i++)
                printf(" ");
            printf("%c",p->data);
            for(i=n+1;i<30;i+=2)
                printf("▃");
            printf("\n");
            top--;
            if(p->pRChild!=NULL)
            {
                top++;
                stack[top]=p->pRChild;
                level[top][0]=n+width;
                level[top][1]=2;
            }
            if(p->pLChild!=NULL)
            {
                top++;
                stack[top]=p->pLChild;
                level[top][0]=n+width;
                level[top][1]=1;
            }
        }
    }
}


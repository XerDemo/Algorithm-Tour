#include <stdio.h>
#include <stdlib.h>

typedef int type;                                   // 定义数据类型 方便更改

typedef struct Node{
    type data;                                      // 数据域
    struct Node * pNext;                            // 指针域
}LinkNode;

LinkNode * createList();                            // 创建链表
void traverseList(LinkNode * pHead);                // 打印链表
int isEmpty(LinkNode * pHead);                      // 判断链表是否为空
LinkNode * search(LinkNode * pHead, int pos);       // 查找第pos个位置地址
LinkNode * find(LinkNode * pHead, type val);        // 查找val的位置
void insert(LinkNode * pHead, int pos, type val);   // 插入
type deleteList(LinkNode * pHead, int pos );        // 删除
int length(LinkNode * pHead);                       // 表长

int main(void)
{
    int choice;
    type val;
    int pos;
    LinkNode * pHead = NULL;
    
    while (1)
    {
    	printf("\n\t			线性表子系统                       ");
		printf("\n\t\t*********************************************");
		printf("\n\t\t*              1----建 表                   *");
		printf("\n\t\t*              2----插 入                   *");
		printf("\n\t\t*              3----删 除                   *");
		printf("\n\t\t*              4----显 示                   *");
		printf("\n\t\t*              5----表 长                   *");
		printf("\n\t\t*              0----退 出                   *");
		printf("\n\t\t*********************************************");   
		printf("\n\t\t请选择菜单号(0-6):");
		scanf("%d", &choice);
	
		switch(choice)
		{
			case 1:
			    pHead = createList();
		    	break;
			case 2:
				printf("\n\t\t请输入插入元素的位置以及数据(空格隔开):");
				scanf("%d %d", &pos, &val);
				insert(pHead, pos, val);
				break;
			case 3:
				printf("\n\t\t请输入删除元素的位置：");
				scanf("%d", &pos);
				deleteList(pHead, pos);
				break;
			case 4:
				traverseList(pHead);
				break;
			case 5:
				printf("\n\t\t表长：%d\n", length(pHead));
				break;
			case 0:
				exit(0);
            default:
            	printf("\n\t\t暂无此选项，请重新输入！\n");
            	break;
		}  
	}
   
    return 0;
}

// 创建链表
LinkNode * createList()
{
    LinkNode * pHead, * pTail;
    pHead = pTail = (LinkNode *) malloc(sizeof(LinkNode));
    pTail->pNext = NULL;
    if (!pHead)
    {
        printf("malloc is failed\n");
        exit(0);
    }

    printf("\n\t\t请输入数据(-1为结束标志):");
    int x;
    scanf("%d", &x);
    while (-1 != x)
    {
        LinkNode *pNew = (LinkNode *) malloc(sizeof(LinkNode));
        pNew->data = x;
        pNew->pNext = NULL;
        pTail->pNext = pNew;
        pTail = pNew;
        scanf("%d", &x);
    }
    return pHead;
}

// 判断链表是否为空
int isEmpty(LinkNode * pHead)
{
    return pHead->pNext == NULL;
}

// 查找第pos个位置地址
LinkNode * search(LinkNode * pHead, int pos)
{
    int idx = 0;
    LinkNode *p = pHead;
    while (idx < pos && p != NULL)
    {
        idx++;
        p = p->pNext;
    }
//    printf("测试前驱: %d\n", p->data);
    return p;           // 返回NULL表示没找到  当不为空 找到返回地址
}

// 根据值查找位置
LinkNode * find(LinkNode * pHead, type val)
{
    LinkNode * p = pHead->pNext;
    while (p != NULL && p->data != val)
    {
        p = p->pNext;
    }
    return p;  // p:null 说明没找到
}

int length(LinkNode * pHead)
{
    int cnt = 0;
    LinkNode * p = pHead->pNext;
    while (p)
    {
        cnt++;
        p = p->pNext;
    }
    return cnt;
}

// 插入
void insert(LinkNode * pHead, int pos, type val)
{
    // 寻找pos位置的前驱结点
    LinkNode *pre = search(pHead, pos - 1);
    if (!pre)
    {
        printf("insert is failed. \n");
        return;
    }
    LinkNode *pNew = (LinkNode *) malloc(sizeof(LinkNode));
    pNew->data = val;
    pNew->pNext = pre->pNext;
    pre->pNext = pNew;
}

// 删除
type  deleteList(LinkNode * pHead, int pos )
{
    // 查找pos的前驱结点
    LinkNode *pre = search(pHead, pos - 1);
    if (!pre)
    {
        printf("remove is failed. \n");
    } else{
        LinkNode *pTemp = pre->pNext;
        type p = pTemp->data;
        pre->pNext = pTemp->pNext;
        free(pTemp);
        pTemp = NULL;
        return p;
    }
}

// 打印链表
void traverseList(LinkNode * pHead)
{
    if (isEmpty(pHead))
    {
        printf("traverseList is failed. because linklist is empty!\n");
        return;
    }

    printf("LinkList is : ");
    LinkNode *p = pHead->pNext;
    while (p)
    {
        printf(" %d  ", p->data);
        p = p->pNext;
    }
    printf("\n");
}
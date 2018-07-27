#include <stdio.h>
#include <stdlib.h>
#define MAXSZIE 100

typedef char type;
typedef struct Node {
    type data;
    struct Node *pLChild;
    struct Node *pRChild;
} BiTNode;

BiTNode *createTree();                          // �ݹ����򴴽�������
void preOrderTraverse(BiTNode *pT);             // �ݹ��������
void inOrderTraverse(BiTNode *pT);              // �ݹ��������
void postOrderTraverse(BiTNode *pT);            // �ݹ�������
void levelOrderTraverse(BiTNode *pT);           // ����ģ��˳����� ʵ�� ��α���
int leafNum(BiTNode *pT);                       // ��Ҷ�ӽ����
int NodeNum(BiTNode * pT);                      // ��������
int treeDepth(BiTNode * pT);                    // ������������
void showTree(BiTNode * pT);                    // ���뷨 ��ʾ������

int main(void)
{
    BiTNode *pT = NULL;
//    BiTNode *pT = createTree();
    int choice; 
    
    while (1)
    {
    	printf("\n               ��������ϵͳ                  ");
		printf("\n*********************************************");
		printf("\n*           1---------�� �� �� ��           *");
		printf("\n*           2---------�� �� �� ʾ           *");
		printf("\n*           3---------�� �� �� ��           *");
		printf("\n*           4---------�� �� �� ��           *");
		printf("\n*           5---------�� �� �� ��           *");
		printf("\n*           6---------�� �� �� ��           *");
		printf("\n*           7---------�� Ҷ �� ��           *");
		printf("\n*           8---------�� �� �� ��           *");
		printf("\n*           9---------�� �� �� ��           *");
		printf("\n*           0---------��       ��           *");
		printf("\n*********************************************");
		
		printf("\n������˵��ţ�(0-9):");
		scanf("%d", &choice);
		getchar();
		
		switch(choice)
		{
			case 1:
				printf("��������ڵ�:" );
				pT = createTree();
				break;
			case 2:
				showTree(pT);
				break;
			case 3:
				printf("���������");
				preOrderTraverse(pT);
				printf("\n");
				break;
			case 4:
				printf("���������");
				inOrderTraverse(pT);
				printf("\n");
				break;
			case 5:
				printf("���������");
				postOrderTraverse(pT);
				printf("\n");
				break;
			case 6:
				printf("��α�����");
				levelOrderTraverse(pT);
				printf("\n");
				break;
			case 7:
			    printf("\nҶ�ڵ�������%d\n", leafNum(pT)); 
				break;
			case 8:
				printf("�ܽ������%d\n", NodeNum(pT));
				break;
			case 9:
				printf("����������ȣ�%d\n", treeDepth(pT));
				break;
			case 0:
				exit(0);
			default:
				printf("���޴�ѡ�\n");
		}
	}
    return 0;
}

// �ݹ鴴��������
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
        printf("������%c�����ӽ��:", pT->data);
        pT->pLChild = createTree();
        printf("������%c�����ӽ��:", pT->data);
        pT->pRChild = createTree();
    }
    return pT;
}

// �ݹ��������
void preOrderTraverse(BiTNode *pT)
{
    if (pT)
    {
        printf("%c  ", pT->data);
        preOrderTraverse(pT->pLChild);
        preOrderTraverse(pT->pRChild);
    }
}

// �ݹ��������
void inOrderTraverse(BiTNode *pT)
{
    if (pT)
    {
        inOrderTraverse(pT->pLChild);
        printf("%c  ", pT->data);
        inOrderTraverse(pT->pRChild);
    }
}

// �ݹ�������
void postOrderTraverse(BiTNode *pT)
{
    if (pT)
    {
        postOrderTraverse(pT->pLChild);
        postOrderTraverse(pT->pRChild);
        printf("%c  ", pT->data);
    }
}

// ����ģ��˳����� ʵ�� ��α���
void levelOrderTraverse(BiTNode *pT)
{
    int front, rear;                // ��ͷ  ��β
    BiTNode *arr[MAXSZIE];          // ����ģ�����
    BiTNode *p = pT;
    // ֻҪ������
    if (p)
    {
        front = 0;
        arr[front] = p;            // ���ڵ����
        rear = 1;
    }
    // ֻҪ���в���
    while (front != rear)
    {
        p = arr[front];

        front++;                   // ��������
        printf("%c  ", p->data);    // ��ӡ���ڵ�

        if (p->pLChild)            // ������Ӳ��� ��� rear����
        {
            arr[rear++] = p->pLChild;
        }
        if (p->pRChild)            // ������Ӳ��� ��� rear����
        {
            arr[rear++] = p->pRChild;
        }
    }
}

// ��Ҷ�ӽ����
int leafNum(BiTNode *pT)
{
    static int count = 0;         // �����ȫ�ֱ��� ��ֹ���ݹ鸲��
    if (pT)
    {
        // �����������ǰ����  �����ж�ʱҶ�ڵ������
        if (!pT->pLChild && !pT->pRChild)
        {
            count++;
            printf("\nҶ�ӽ�㣺%c", pT->data);
        }
        leafNum(pT->pLChild);
        leafNum(pT->pRChild);
    }
    return count;
}

// ��������
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

// ������������
int treeDepth(BiTNode * pT)
{
    int leftDepth, rightDepth;                  // leftDept��pT�����������   rightDepth��pT�����������
    if (NULL == pT)                             // ��������򷵻� 0
    {
        return 0;
    }
    leftDepth = treeDepth(pT->pLChild);
    rightDepth = treeDepth(pT->pRChild);
    if (leftDepth > rightDepth){
        return leftDepth + 1;                   // ���������������  +  ���ڵ㣺1
    } else{
        return rightDepth + 1;                  // ������������� + ���ڵ�
    }
}

// ���뷨 ��ʾ ������
void showTree(BiTNode *T)
{
    BiTNode *stack[MAXSZIE],*p;
    int level[MAXSZIE][2],top,n,i,width=4;
    if(T!=NULL)
    {
        printf("\n�����ʾ����\n");
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
                printf("�z");
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


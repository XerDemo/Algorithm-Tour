#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10                                  // ��󶥵��� 10

typedef struct node{
    int adjVex;                                     // �ڽӵ���
    struct node * pNext;                            // ��һ���ڽӱߵĽ���ַ
}edgesNode;

typedef struct vNode{
    char vertex;                                    // �����־
    edgesNode * firstedges;                         // �����һ���߽ڵ��ַ��ָ��
}vertexNode;

typedef struct {
    vertexNode adjlist[MAXSIZE];                    // ��������
    int n;                                          // ������
    int e;                                          // ����
}ALGraph;


void createGraph(ALGraph * pG);                     // ����ͼ
void showGraph(ALGraph * pG);                       // ��ӡ�ڽӱ�
/********************��������������������ڽӱ�***********************/
void DFSTraverse(ALGraph *pG);                      // �ڽӱ� �����������
void DFS(ALGraph *pG, int i);

int visited[MAXSIZE];                               // �������� ����ֱ���ڴ˴�visited[MAXSIZE] = {0} ��ʼ��
/**************************************************************/
int main(void)
{
    ALGraph G;
    createGraph(&G);
    showGraph(&G);

    DFSTraverse(&G);
    return 0;
}

void createGraph(ALGraph * pG)
{
    int i, j, k, type;
    char ch1, ch2;

    printf("������ͼ�Ķ�������ͱ���(�ո����)��");
    scanf("%d %d", &pG->n, &pG->e);

    printf("������ͼ�Ķ�����Ϣ��");
    for (i = 0; i < pG->n; ++i)
    {
        getchar();    // ��һ��ѭ���������� scanf("%d %d", &pG->n, &pG->e)�Ŀո�ͻس�;  ����ѭ������ scanf("%c", &pG->vertices[i]);�Ŀո�س� 
        scanf("%c", &(pG->adjlist[i].vertex));      // ���붥����Ϣ
        pG->adjlist[i].firstedges = NULL;           // ָ���һ���߽ڵ��ָ����Ϊ null
    }

    printf("������ͼ������(����ͼ:0)��(����ͼ:1):\n");
    scanf("%d", &type);

    for (k = 0; k < pG->e; ++k)
    {
        getchar();
        printf("�������%d���ߵ���������(�ո����)��", k + 1);
        scanf("%c %c", &ch1, &ch2);                     // ch1����β  ch2����ͷ

        // ���������� ��Ӧ�����������λ�� i j
        for (i = 0; ch1 != pG->adjlist[i].vertex; ++i);
        for (j = 0; ch2 != pG->adjlist[j].vertex; ++j);

        // ����һ���µı߽��ҵ���Ӧ�ı���  ����ͷ�����뷨
        edgesNode *pNew = (edgesNode *) malloc(sizeof(edgesNode));
        if (!pNew)
        {
            printf("malloc is failed!\n");
            exit(-1);
        }
        if (type == 1)
        {
            // ����ͼ
            pNew->adjVex = j;
            pNew->pNext = pG->adjlist[i].firstedges;
            pG->adjlist[i].firstedges = pNew;
        }
        else
        {
            pNew->adjVex = j;
            pNew->pNext = pG->adjlist[i].firstedges;
            pG->adjlist[i].firstedges = pNew;
            // �ٴ���һ���ڵ� Ȼ�� i�ĳ�j j�ĳ�i
            edgesNode *p = (edgesNode *) malloc(sizeof(edgesNode));
            p->adjVex = i;
            p->pNext = pG->adjlist[j].firstedges;
            pG->adjlist[j].firstedges = p;
        }

    }
}

void showGraph(ALGraph * pG)
{
    int i;
    printf("��ͼ���ڽӱ�Ϊ��\n");
    for (i = 0; i < pG->n; ++i)
    {
        printf("%d   %c   ", i, pG->adjlist[i].vertex);
        edgesNode * p = pG->adjlist[i].firstedges;
        while (p != NULL)
        {
            printf("%d   ",p->adjVex);
            p = p->pNext;
        }
        printf("\n");
    }
}

/************************�����������--�ڽӱ�***************************/
void DFSTraverse(ALGraph * pG)
{
    int i;

    //  �������� ��ʼ��
    for (i = 0; i < pG->n; ++i)
    {
        visited[i] = 0;         // ��ʼ�����ж���״̬����δ���ʹ�״̬
    }

    // ������ͨͼ ֻ�ᱻ����һ��
    // �������ͨͼ ����ֱ��д�� DFS(pG, 0; ��0�ſ�ʼ������ȱ���  ֮���Դ�0��pG->n��Ϊ�˷�ֹ������ͨͼ�����
    // ��0��pG->n �е�ÿ������Ϊ��� ��������ȱ���һ��    if (!visited[i])  ��Ҫ��c��Ϊ������ʱ ��������AΪ����ʱ���Ѿ�������B�� visited=1 i++��һ������Ϊ���
    for (i = 0; i < pG->n; ++i)
    {
        if (!visited[i])   // ���Viδ�����ʹ�
        {
            DFS(pG, i);    // ��Vi��ʼDFS����һ����ͨ����
        }
    }
}

void DFS(ALGraph * pG, int i)
{
    int j;
    // ��ViΪ��������ڽӱ�洢��ͼ pG����DFS����
    printf("\t������ȱ�����㣺���%c\n", pG->adjlist[i].vertex); // ��ӡ����
    visited[i] = 1;
    
    edgesNode * p = pG->adjlist[i].firstedges;
    while (p)
    {
        if (!visited[p->adjVex])
        {
            DFS(pG, p->adjVex);
        }
        p = p->pNext;
    }
}

//��������  ABCDEF Ϊһ����ͨͼ   MN Ϊһ����ͨͼ
/*
������ͼ�Ķ�������ͱ���(�ո����)��8 7
������ͼ�Ķ�����Ϣ��A B C D E F M N
������ͼ������(����ͼ:0)��(����ͼ:1):
0

�������1���ߵ���������(�ո����)��A B
�������2���ߵ���������(�ո����)��A C
�������3���ߵ���������(�ո����)��B D
�������4���ߵ���������(�ո����)��B E
�������5���ߵ���������(�ո����)��D F
�������6���ߵ���������(�ո����)��E F
�������7���ߵ���������(�ո����)��M N
��ͼ���ڽӱ�Ϊ��
0   A   2   1
1   B   4   3   0
2   C   0
3   D   5   1
4   E   5   1
5   F   4   3
6   M   7
7   N   6
������ȱ�����㣺���A
        ������ȱ�����㣺���C
        ������ȱ�����㣺���B
        ������ȱ�����㣺���E
        ������ȱ�����㣺���F
        ������ȱ�����㣺���D
        ������ȱ�����㣺���M
        ������ȱ�����㣺���N
*/

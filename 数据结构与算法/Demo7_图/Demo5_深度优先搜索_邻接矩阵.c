#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100                                     // ��󶥵�����Ϊ100


// �ڽӾ���---������ȱ���

typedef struct {
    char vertices[MAXSIZE];                             // �洢���� ��Ϣ
    int edges[MAXSIZE][MAXSIZE];                        // �ڽӾ��� �洢��������֮��Ĺ�ϵ
    int n;                                              // ������
    int e;                                              // ����
}MyGraph;

void createGraph(MyGraph * pG);                         // ����ͼ
void showGraph(MyGraph * pG);                           // ����ͼ

/*********************������ȱ���******************************/
void DFSTraverse(MyGraph * pG);                // �ڽӾ������ȱ�������
void DFS(MyGraph * pG, int i);                 //

int visited[MAXSIZE] ;                    // ��ȫ�ֶ���һ�� �������� 1��ʾ���ʹ�
/**************************************************************/

int main(void)
{
    MyGraph G;
    createGraph(&G);
    showGraph(&G);

    DFSTraverse(&G);
    return 0;
}

void createGraph(MyGraph *pG)
{
    int i, j, k, type;
    char ch1, ch2;
    printf("�����붥�����ͱ���(�Կո����)��\n");
    scanf("%d %d", &pG->n, &pG->e);
    printf("�����붥����Ϣ(�����־):\n");
    // ���� ������Ϣ
    for (i = 0; i < pG->n; ++i)
    {
        getchar();                                      // �������� �ո��س�
        scanf("%c", &pG->vertices[i]);
    }

    // ���ڽӾ��� ���г�ʼ��
    for (i = 0; i < MAXSIZE; ++i)
    {
        for (j = 0; j < MAXSIZE; ++j)
        {
            pG->edges[i][j] = 0;
        }
    }

    printf("������ͼ�����ͣ�����ͼ(0)������ͼ(1):");
    scanf("%d", &type);

    for (k = 0; k < pG->e; ++k)
    {
        fflush(stdin);                                 // ˢ�»�����
        printf("�������%d���ߵ����������־(�ÿո�ָ�):", k + 1);
        scanf("%c %c", &ch1, &ch2);
        for (i = 0; ch1 != pG->vertices[i]; ++i);
        for (j = 0; ch2 != pG->vertices[j]; ++j);
        if (type == 0)
        {
            // ���������ͼ �������ｫpG->edges[i][j] �ĶԳ�Ԫ�� pG->edges[j][i] Ҳ��Ϊ1
            pG->edges[i][j] = pG->edges[j][i] = 1;
        } else{
            // ����ͼ
            pG->edges[i][j] = 1;
        }

    }
}


void showGraph(MyGraph *pG)
{
    int i, j;
    printf("vertices is: ");
    for (i = 0; i < pG->n; ++i)
    {
        printf(" %c ", pG->vertices[i]);
    }
    printf("\n");

    printf("�ڽӾ���\n");
    for (i = 0; i < pG->n; ++i)
    {
        for (j = 0; j < pG->n; ++j)
        {
            printf("%d   ", pG->edges[i][j]);
        }
        printf("\n");
    }
}


/************************�ڽӾ���---������ȱ���*******************************/
void DFSTraverse(MyGraph * pG)
{
    int i;
    // ��ʼ���������� 0   Ҳ������ int visited[MAXSIZE] = {0} ; ʱ��ֱ�ӳ�ʼ�� 0
    for (i = 0; i < pG->n; ++i)
    {
        visited[i] = 0;     // ��ʼ�����ж��㶼��δ����״̬
    }

    // ������ͨͼ ֻ�ᱻ����һ��
    // �������ͨͼ ����ֱ��д�� DFS(pG, 0; ��0�ſ�ʼ������ȱ���  ֮���Դ�0��pG->n��Ϊ�˷�ֹ������ͨͼ�����
    // ��0��pG->n �е�ÿ������Ϊ��� ��������ȱ���һ��    if (!visited[i])  ��Ҫ��c��Ϊ������ʱ ��������AΪ����ʱ���Ѿ�������B�� visit
    for (i = 0; i < pG->n; ++i)
    {
        if (!visited[i])    // ����Ķ���δ�����ʹ� 
        {
            DFS(pG, i);		// �Ӹö��㿪ʼDFS����һ����ͨ���� 
        }
    }

}

void DFS(MyGraph *pG, int i)
{
    int j;
    printf("\t������ȱ�����㣺���%c\n", pG->vertices[i]); // ��ӡ����
    visited[i] = 1;          // ���ʹ��Ķ�������Ϊ1

    for (j = 0; j < pG->n; ++j)
    {
        if (pG->edges[i][j] == 1 && !visited[j])
        {
            DFS(pG, j);      // ��δ���ʵ��ڽӶ���ݹ����
        }
    }
}

//��������  ABCDEF Ϊһ����ͨͼ   MN Ϊһ����ͨͼ  
/*
�����붥�����ͱ���(�Կո����)��
8 7
�����붥����Ϣ(�����־):
A B C D E F M N
������ͼ�����ͣ�����ͼ(0)������ͼ(1):0
�������1���ߵ����������־(�ÿո�ָ�):A B
�������2���ߵ����������־(�ÿո�ָ�):A C
�������3���ߵ����������־(�ÿո�ָ�):B D
�������4���ߵ����������־(�ÿո�ָ�):B E
�������5���ߵ����������־(�ÿո�ָ�):D F
�������6���ߵ����������־(�ÿո�ָ�):E F
�������7���ߵ����������־(�ÿո�ָ�):M N
vertices is:  A  B  C  D  E  F  M  N
�ڽӾ���
0   1   1   0   0   0   0   0
1   0   0   1   1   0   0   0
1   0   0   0   0   0   0   0
0   1   0   0   0   1   0   0
0   1   0   0   0   1   0   0
0   0   0   1   1   0   0   0
0   0   0   0   0   0   0   1
0   0   0   0   0   0   1   0
������ȱ�����㣺���A
        ������ȱ�����㣺���B
        ������ȱ�����㣺���D
        ������ȱ�����㣺���F
        ������ȱ�����㣺���E
        ������ȱ�����㣺���C
        ������ȱ�����㣺���M
        ������ȱ�����㣺���N
*/

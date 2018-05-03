#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100                                     // ��󶥵�����Ϊ100


// ����ͼ -- �ڽӾ���

typedef struct {
    char vertices[MAXSIZE];                             // �洢���� ��Ϣ
    int edges[MAXSIZE][MAXSIZE];                        // �ڽӾ��� �洢��������֮��Ĺ�ϵ
    int n;                                              // ������
    int e;                                              // ����
}MyGraph;

void createGraph(MyGraph * pG);                         // ����ͼ
void showGraph(MyGraph * pG);                           // ����ͼ

int main(void)
{
    MyGraph G;
    createGraph(&G);
    showGraph(&G);
    return 0;
}

void createGraph(MyGraph *pG)
{
    int i, j, k;
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
    for (i = 0; i < pG->n; ++i)
    {
        for (j = 0; j < pG->n; ++j)
        {
            pG->edges[i][j] = 0;
        }
    }

    printf("������ÿ���߶�Ӧ����������(�����뻡β�������뻡ͷ):\n");
    for (k = 0; k < pG->e; ++k)
    {
        fflush(stdin);                                 // ˢ�»�����
        printf("�������%d���ߵ����������־(�ö��ŷָ�):", k + 1);
        scanf("%c %c", &ch1, &ch2);
        for (i = 0; ch1 != pG->vertices[i]; ++i);
        for (j = 0; ch2 != pG->vertices[j]; ++j);
        pG->edges[i][j] = 1;
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

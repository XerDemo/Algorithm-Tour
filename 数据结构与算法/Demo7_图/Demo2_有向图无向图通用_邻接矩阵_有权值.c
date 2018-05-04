#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct {
    char vexs[MAXSIZE];                         // ��Ŷ���Ԫ��
    int edges[MAXSIZE][MAXSIZE];                // �ڽӾ��� ��ű����֮��Ĺ�ϵ
    int n;                                      // ������
    int e;                                      // ����
} myGraph;


myGraph *createGraph();                        // ����ͼ
void showGraph(myGraph *pG);                   // ��ӡ�ڽӾ���

int main(void)
{
    myGraph *pG = createGraph();
    showGraph(pG);
    return 0;
}

myGraph *createGraph()
{
    int i, j, k, type, weight = 9999;
    char ch1, ch2;

    myGraph *pG = (myGraph *) malloc(sizeof(myGraph));
    if (!pG)
    {
        printf("malloc is failed!");
        exit(-1);
    }
    printf("�����붥������");
    scanf("%d", &pG->n);
    printf("���������:");
    scanf("%d", &pG->e);

    printf("�����붥����Ϣ(�����־):");
    for (i = 0; i < pG->n; ++i)
    {
        getchar();                              // ���ջس���ո�
        scanf("%c", &(pG->vexs[i]));
    }

    // �� �ڽӾ�����г�ʼ��
    for (i = 0; i < MAXSIZE; ++i)
    {
        for (j = 0; j < MAXSIZE; ++j)
        {
            pG->edges[i][j] = 0;               // ����Ȩֵ��ͼ�� ��Ϊ0���ܱ�����Ϊ��Ȩֵ��������ʱ��������ʾû�б� ��������0���´�ӡ���ʺϺÿ�һ��
        }
    }

    printf("������ͼ������(����ͼ:0)��(����ͼ:1):\n");
    scanf("%d", &type);

    for (k = 0; k < pG->e; ++k)
    {
        fflush(stdin);                          // ˢ�»�����
        printf("������%d���ߵ����������Լ�Ȩֵ(�Կո����)��", k + 1);
        scanf("%c %c %d", &ch1, &ch2, &weight);

        // �õ� ���������ڽӾ����е��±� i j
        for (i = 0;  ch1 != pG->vexs[i]; ++i);
        for (j = 0;  ch2 != pG->vexs[j]; ++j);


//        printf("i = %d, j = %d\n", i, j);
        if (type == 0)
        {
            pG->edges[i][j] = pG->edges[j][i] = weight;
        } else
        {
            pG->edges[i][j] = weight;
        }
    }

    return pG;
}

void showGraph(myGraph *pG)
{
    int i, j;
    printf("vexs is : ");
    for (i = 0; i < pG->n; ++i)
    {
        printf("%c  ", pG->vexs[i]);
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

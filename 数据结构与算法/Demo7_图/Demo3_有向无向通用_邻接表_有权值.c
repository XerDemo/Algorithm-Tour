#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10                                  // ��󶥵��� 10

typedef struct node{
    int adjVex;                                     // �ڽӵ���
    int info;                                       // Ȩֵ
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

int main(void)
{
    ALGraph G;
    createGraph(&G);
    showGraph(&G);
    return 0;
}

void createGraph(ALGraph * pG)
{
    int i, j, k, type;

    /********����weight��ʾȨֵ***********/
    int weight;
    /***************�Ͳ���Ȩֵ������֮��***************/
    char ch1, ch2;

    printf("������ͼ�Ķ�������ͱ���(�ո����)��");
    scanf("%d %d", &pG->n, &pG->e);

    printf("������ͼ�Ķ�����Ϣ��");
    for (i = 0; i < pG->n; ++i)
    {
        getchar();                                  // ���տո�ͻس�
        scanf("%c", &(pG->adjlist[i].vertex));      // ���붥����Ϣ
        pG->adjlist[i].firstedges = NULL;           // ָ���һ���߽ڵ��ָ����Ϊ null
    }

    printf("������ͼ������(����ͼ:0)��(����ͼ:1):\n");
    scanf("%d", &type);

    for (k = 0; k < pG->e; ++k)
    {
        getchar();
        printf("�������%d���ߵ����������Ȩֵ(�ո����)��", k + 1);

        /********************����һ������*******************/
        scanf("%c %c %d", &ch1, &ch2, &weight);                     // ch1����β  ch2����ͷ
        /**************�Ͳ���Ȩֵ������֮��******************/

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
            /*********************/
            pNew->info = weight;
            /**********************/
            pNew->pNext = pG->adjlist[i].firstedges;
            pG->adjlist[i].firstedges = pNew;
        }
        else
        {
            pNew->adjVex = j;
            pNew->info = weight;
            pNew->pNext = pG->adjlist[i].firstedges;
            pG->adjlist[i].firstedges = pNew;
            // �ٴ���һ���ڵ� Ȼ�� i�ĳ�j j�ĳ�i
            edgesNode *p = (edgesNode *) malloc(sizeof(edgesNode));
            p->adjVex = i;
            p->info = weight;
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
        printf("%d   %c     ", i, pG->adjlist[i].vertex);
        edgesNode * p = pG->adjlist[i].firstedges;
        while (p != NULL)
        {
            printf("%d | %d     ",p->adjVex,  p->info);
            p = p->pNext;
        }
        printf("\n");
    }
}

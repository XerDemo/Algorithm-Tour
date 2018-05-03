#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100                                     // 最大顶点数设为100


// 有向图 -- 邻接矩阵

typedef struct {
    char vertices[MAXSIZE];                             // 存储顶点 信息
    int edges[MAXSIZE][MAXSIZE];                        // 邻接矩阵 存储两个顶点之间的关系
    int n;                                              // 顶点数
    int e;                                              // 边数
}MyGraph;

void createGraph(MyGraph * pG);                         // 创建图
void showGraph(MyGraph * pG);                           // 遍历图

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
    printf("请输入顶点数和边数(以空格隔开)：\n");
    scanf("%d %d", &pG->n, &pG->e);
    printf("请输入顶点信息(顶点标志):\n");
    // 输入 顶点信息
    for (i = 0; i < pG->n; ++i)
    {
        getchar();                                      // 用来接收 空格或回车
        scanf("%c", &pG->vertices[i]);
    }

    // 对邻接矩阵 进行初始化
    for (i = 0; i < pG->n; ++i)
    {
        for (j = 0; j < pG->n; ++j)
        {
            pG->edges[i][j] = 0;
        }
    }

    printf("请输入每条边对应的两个顶点(先输入弧尾，再输入弧头):\n");
    for (k = 0; k < pG->e; ++k)
    {
        fflush(stdin);                                 // 刷新缓冲区
        printf("请输入第%d条边的两个顶点标志(用逗号分隔):", k + 1);
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

    printf("邻接矩阵：\n");
    for (i = 0; i < pG->n; ++i)
    {
        for (j = 0; j < pG->n; ++j)
        {
            printf("%d   ", pG->edges[i][j]);
        }
        printf("\n");
    }
}

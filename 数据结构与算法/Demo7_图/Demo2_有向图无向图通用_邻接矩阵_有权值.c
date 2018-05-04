#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct {
    char vexs[MAXSIZE];                         // 存放顶点元素
    int edges[MAXSIZE][MAXSIZE];                // 邻接矩阵 存放边与边之间的关系
    int n;                                      // 顶点数
    int e;                                      // 边数
} myGraph;


myGraph *createGraph();                        // 创建图
void showGraph(myGraph *pG);                   // 打印邻接矩阵

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
    printf("请输入顶点数：");
    scanf("%d", &pG->n);
    printf("请输入边数:");
    scanf("%d", &pG->e);

    printf("请输入顶点信息(顶点标志):");
    for (i = 0; i < pG->n; ++i)
    {
        getchar();                              // 接收回车或空格
        scanf("%c", &(pG->vexs[i]));
    }

    // 对 邻接矩阵进行初始化
    for (i = 0; i < MAXSIZE; ++i)
    {
        for (j = 0; j < MAXSIZE; ++j)
        {
            pG->edges[i][j] = 0;               // 在有权值的图中 因为0可能被误以为是权值，所以有时用无穷大表示没有边 这里我用0等下打印的适合好看一点
        }
    }

    printf("请输入图的类型(无向图:0)、(有向图:1):\n");
    scanf("%d", &type);

    for (k = 0; k < pG->e; ++k)
    {
        fflush(stdin);                          // 刷新缓冲区
        printf("请输入%d条边的两个顶点以及权值(以空格隔开)：", k + 1);
        scanf("%c %c %d", &ch1, &ch2, &weight);

        // 得到 两顶点在邻接矩阵中的下标 i j
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

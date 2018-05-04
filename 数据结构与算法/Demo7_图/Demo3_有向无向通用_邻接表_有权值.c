#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10                                  // 最大顶点数 10

typedef struct node{
    int adjVex;                                     // 邻接点域
    int info;                                       // 权值
    struct node * pNext;                            // 下一条邻接边的结点地址
}edgesNode;

typedef struct vNode{
    char vertex;                                    // 顶点标志
    edgesNode * firstedges;                         // 保存第一个边节点地址的指针
}vertexNode;

typedef struct {
    vertexNode adjlist[MAXSIZE];                    // 顶点数组
    int n;                                          // 顶点数
    int e;                                          // 边数
}ALGraph;


void createGraph(ALGraph * pG);                     // 创建图
void showGraph(ALGraph * pG);                       // 打印邻接表

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

    /********加上weight表示权值***********/
    int weight;
    /***************和不加权值的区别之处***************/
    char ch1, ch2;

    printf("请输入图的顶点个数和边数(空格隔开)：");
    scanf("%d %d", &pG->n, &pG->e);

    printf("请输入图的顶点信息；");
    for (i = 0; i < pG->n; ++i)
    {
        getchar();                                  // 接收空格和回车
        scanf("%c", &(pG->adjlist[i].vertex));      // 输入顶点信息
        pG->adjlist[i].firstedges = NULL;           // 指向第一个边节点的指针置为 null
    }

    printf("请输入图的类型(无向图:0)、(有向图:1):\n");
    scanf("%d", &type);

    for (k = 0; k < pG->e; ++k)
    {
        getchar();
        printf("请输入第%d条边的两个顶点和权值(空格隔开)：", k + 1);

        /********************加上一个输入*******************/
        scanf("%c %c %d", &ch1, &ch2, &weight);                     // ch1：弧尾  ch2：弧头
        /**************和不加权值的区别之处******************/

        // 查找这条边 对应的两个顶点的位置 i j
        for (i = 0; ch1 != pG->adjlist[i].vertex; ++i);
        for (j = 0; ch2 != pG->adjlist[j].vertex; ++j);

        // 创建一个新的边结点挂到对应的边上  采用头部插入法
        edgesNode *pNew = (edgesNode *) malloc(sizeof(edgesNode));
        if (!pNew)
        {
            printf("malloc is failed!\n");
            exit(-1);
        }
        if (type == 1)
        {
            // 有向图
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
            // 再创建一个节点 然后将 i改成j j改成i
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
    printf("该图的邻接表为：\n");
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

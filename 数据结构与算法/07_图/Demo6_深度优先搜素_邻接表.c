#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10                                  // 最大顶点数 10

typedef struct node{
    int adjVex;                                     // 邻接点域
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
/********************深度优先搜索————邻接表***********************/
void DFSTraverse(ALGraph *pG);                      // 邻接表 深度优先搜索
void DFS(ALGraph *pG, int i);

int visited[MAXSIZE];                               // 访问数组 可以直接在此处visited[MAXSIZE] = {0} 初始化
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

    printf("请输入图的顶点个数和边数(空格隔开)：");
    scanf("%d %d", &pG->n, &pG->e);

    printf("请输入图的顶点信息；");
    for (i = 0; i < pG->n; ++i)
    {
        getchar();    // 第一次循环用来接收 scanf("%d %d", &pG->n, &pG->e)的空格和回车;  其它循环接收 scanf("%c", &pG->vertices[i]);的空格回车 
        scanf("%c", &(pG->adjlist[i].vertex));      // 输入顶点信息
        pG->adjlist[i].firstedges = NULL;           // 指向第一个边节点的指针置为 null
    }

    printf("请输入图的类型(无向图:0)、(有向图:1):\n");
    scanf("%d", &type);

    for (k = 0; k < pG->e; ++k)
    {
        getchar();
        printf("请输入第%d条边的两个顶点(空格隔开)：", k + 1);
        scanf("%c %c", &ch1, &ch2);                     // ch1：弧尾  ch2：弧头

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
            pNew->pNext = pG->adjlist[i].firstedges;
            pG->adjlist[i].firstedges = pNew;
        }
        else
        {
            pNew->adjVex = j;
            pNew->pNext = pG->adjlist[i].firstedges;
            pG->adjlist[i].firstedges = pNew;
            // 再创建一个节点 然后将 i改成j j改成i
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
    printf("该图的邻接表为：\n");
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

/************************深度优先搜索--邻接表***************************/
void DFSTraverse(ALGraph * pG)
{
    int i;

    //  访问数组 初始化
    for (i = 0; i < pG->n; ++i)
    {
        visited[i] = 0;         // 初始化所有顶点状态都是未访问过状态
    }

    // 若是连通图 只会被访问一次
    // 如果是连通图 可以直接写成 DFS(pG, 0; 从0号开始深度优先遍历  之所以从0到pG->n是为了防止不是连通图的情况
    // 以0到pG->n 中的每个顶点为起点 都深度优先遍历一次    if (!visited[i])  当要以c点为起点遍历时 发现在以A为起点的时候已经访问了B点 visited=1 i++换一个点作为起点
    for (i = 0; i < pG->n; ++i)
    {
        if (!visited[i])   // 如果Vi未被访问过
        {
            DFS(pG, i);    // 从Vi开始DFS搜索一个连通分量
        }
    }
}

void DFS(ALGraph * pG, int i)
{
    int j;
    // 以Vi为出发点对邻接表存储的图 pG进行DFS搜索
    printf("\t深度优先遍历结点：结点%c\n", pG->adjlist[i].vertex); // 打印顶点
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

//测试数据  ABCDEF 为一个连通图   MN 为一个连通图
/*
请输入图的顶点个数和边数(空格隔开)：8 7
请输入图的顶点信息；A B C D E F M N
请输入图的类型(无向图:0)、(有向图:1):
0

请输入第1条边的两个顶点(空格隔开)：A B
请输入第2条边的两个顶点(空格隔开)：A C
请输入第3条边的两个顶点(空格隔开)：B D
请输入第4条边的两个顶点(空格隔开)：B E
请输入第5条边的两个顶点(空格隔开)：D F
请输入第6条边的两个顶点(空格隔开)：E F
请输入第7条边的两个顶点(空格隔开)：M N
该图的邻接表为：
0   A   2   1
1   B   4   3   0
2   C   0
3   D   5   1
4   E   5   1
5   F   4   3
6   M   7
7   N   6
深度优先遍历结点：结点A
        深度优先遍历结点：结点C
        深度优先遍历结点：结点B
        深度优先遍历结点：结点E
        深度优先遍历结点：结点F
        深度优先遍历结点：结点D
        深度优先遍历结点：结点M
        深度优先遍历结点：结点N
*/

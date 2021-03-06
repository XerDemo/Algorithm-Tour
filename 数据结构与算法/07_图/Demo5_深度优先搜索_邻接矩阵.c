#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100                                     // 最大顶点数设为100

/*
 * 邻接矩阵---深度优先遍历
 * 基本思想：假设初始状态是图中所有顶点未曾被访问，从图中某个顶点A出发，访问此顶点，然后选择访问一个与A相邻的顶点B
 * 从B出现访问与其相邻的顶点(已经访问过的不再访问，比如A),直到所有顶点都被访问到，如果有与顶点相邻的结点都被访问过，则回退(回溯)到上一步
 * 若此时图中尚有顶点未被访问(不是一个连通图)，则另选图中一个未曾被访问的顶点作为起始点，重复上述过程，直到图中所有顶点都被访问到为止。
 */

typedef struct {
    char vertices[MAXSIZE];                             // 存储顶点 信息
    int edges[MAXSIZE][MAXSIZE];                        // 邻接矩阵 存储两个顶点之间的关系
    int n;                                              // 顶点数
    int e;                                              // 边数
}MyGraph;

void createGraph(MyGraph * pG);                         // 创建图
void showGraph(MyGraph * pG);                           // 遍历图

/*********************深度优先遍历******************************/
void DFSTraverse(MyGraph * pG);                // 邻接矩阵的深度遍历操作
void DFS(MyGraph * pG, int i);                 //

int visited[MAXSIZE] ;                    // 在全局定义一个 访问数组 1表示访问过
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
    printf("请输入顶点数和边数(以空格隔开)：\n");
    scanf("%d %d", &pG->n, &pG->e);
    printf("请输入顶点信息(顶点标志):\n");
    // 输入 顶点信息
    for (i = 0; i < pG->n; ++i)
    {
        getchar();      // 第一次循环用来接收 scanf("%d %d", &pG->n, &pG->e)的空格和回车;  其它循环接收 scanf("%c", &pG->vertices[i]);的空格回车
        scanf("%c", &pG->vertices[i]);
    }

    // 对邻接矩阵 进行初始化
    for (i = 0; i < MAXSIZE; ++i)
    {
        for (j = 0; j < MAXSIZE; ++j)
        {
            pG->edges[i][j] = 0;
        }
    }

    printf("请输入图的类型：无向图(0)、有向图(1):");
    scanf("%d", &type);

    for (k = 0; k < pG->e; ++k)
    {
        fflush(stdin);                                 // 刷新缓冲区
        printf("请输入第%d条边的两个顶点标志(用空格分隔):", k + 1);
        scanf("%c %c", &ch1, &ch2);
        for (i = 0; ch1 != pG->vertices[i]; ++i);
        for (j = 0; ch2 != pG->vertices[j]; ++j);
        if (type == 0)
        {
            // 如果是无向图 就在这里将pG->edges[i][j] 的对称元素 pG->edges[j][i] 也设为1
            pG->edges[i][j] = pG->edges[j][i] = 1;
        } else{
            // 有向图
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


/************************邻接矩阵---深度优先遍历*******************************/
void DFSTraverse(MyGraph * pG)
{
    int i;
    // 初始化访问数组 0   也可以在 int visited[MAXSIZE] = {0} ; 时候直接初始化 0
    for (i = 0; i < pG->n; ++i)
    {
        visited[i] = 0;     // 初始化所有顶点都是未访问状态
    }

    // 若是连通图 只会被访问一次
    // 如果是连通图 可以直接写成 DFS(pG, 0); 从0号开始深度优先遍历  之所以从0到pG->n是为了防止不是连通图的情况
    // 以0到pG->n 中的每个顶点为起点 都深度优先遍历一次    if (!visited[i])  当要以c点为起点遍历时 发现在以A为起点的时候已经访问了B点 visit
    for (i = 0; i < pG->n; ++i)
    {
        if (!visited[i])    // 如果改顶点未被访问过
        {
            DFS(pG, i);		// 从该顶点开始DFS搜索一个连通分量
        }
    }

}

/*
 * 深度优先搜索：
 *     基本思想：从一个点A出发 依次访问与其相邻的结点(比如访问到了B)  如果当前结点(B)未被访问过 访问之并将访问数组置为1表示以及访问过
 *              再从B出发 依次访问与其相邻的结点(比如访问到了C) 发现C被访问过 则回退到B结点，访问与B相邻的其它结点，若发现可以访问访问之，重复上述步骤，
 *              若发现不能访问，则继续回退到,直到有可以访问的点或程序终止为止
 *
 */
void DFS(MyGraph *pG, int i)
{
    int j;
    printf("\t深度优先遍历结点：结点%c\n", pG->vertices[i]); // 打印顶点
    visited[i] = 1;          // 访问过的顶点设置为1

    // 从当前点出发 寻找与其相邻的的结点
    for (j = 0; j < pG->n; ++j)
    {
        // 如果满足 相邻 并且 这个点未被访问过 访问之
        if (pG->edges[i][j] == 1 && !visited[j])
        {
            DFS(pG, j);      // 对未访问的邻接顶点递归调用
        }
    }
    // 递归结束条件就是 所有点都遍历完了 自然结束
}

//测试数据  ABCDEF 为一个连通图   MN 为一个连通图
/*
请输入顶点数和边数(以空格隔开)：
8 7
请输入顶点信息(顶点标志):
A B C D E F M N
请输入图的类型：无向图(0)、有向图(1):0
请输入第1条边的两个顶点标志(用空格分隔):A B
请输入第2条边的两个顶点标志(用空格分隔):A C
请输入第3条边的两个顶点标志(用空格分隔):B D
请输入第4条边的两个顶点标志(用空格分隔):B E
请输入第5条边的两个顶点标志(用空格分隔):D F
请输入第6条边的两个顶点标志(用空格分隔):E F
请输入第7条边的两个顶点标志(用空格分隔):M N
vertices is:  A  B  C  D  E  F  M  N
邻接矩阵：
0   1   1   0   0   0   0   0
1   0   0   1   1   0   0   0
1   0   0   0   0   0   0   0
0   1   0   0   0   1   0   0
0   1   0   0   0   1   0   0
0   0   0   1   1   0   0   0
0   0   0   0   0   0   0   1
0   0   0   0   0   0   1   0
深度优先遍历结点：结点A
        深度优先遍历结点：结点B
        深度优先遍历结点：结点D
        深度优先遍历结点：结点F
        深度优先遍历结点：结点E
        深度优先遍历结点：结点C
        深度优先遍历结点：结点M
        深度优先遍历结点：结点N
*/

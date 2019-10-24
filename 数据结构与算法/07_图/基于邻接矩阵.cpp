#include <queue>
#include <stack>
#include <iostream>

#define MAXSIZE 10                                  // 最大顶点数 10
using namespace std;

typedef struct {
    char vexs[MAXSIZE];                         // 存放顶点元素
    int edges[MAXSIZE][MAXSIZE];                // 邻接矩阵 存放边与边之间的关系
    int n;                                      // 顶点数
    int e;                                      // 边数
} myGraph;

bool visit[MAXSIZE];

myGraph *createGraph();                        // 创建图
void showGraph(myGraph *pG);                   // 打印邻接矩阵
void BFS(myGraph *pG, int i);                      // bfs
void dfs_1(myGraph *pG, int i);                    // DFS 递归
void dfs_2(myGraph *pG, int i);                    // DFS 栈

int main(void) {
    myGraph *pG = createGraph();
    showGraph(pG);

    // BFS
    cout << "bfs: ";
    for (int i = 0; i < MAXSIZE; ++i) {  // 访问数组初始化
        visit[i] = false;
    }
    BFS(pG, 0);

    // DFS 递归
    printf("\nDFS1: ");
    for (int i = 0; i < MAXSIZE; ++i) {  // 访问数组初始化
        visit[i] = false;
    }
    dfs_1(pG, 0);

    // DFS 栈
    printf("\nDFS2: ");
    for (int i = 0; i < MAXSIZE; ++i) {  // 访问数组初始化
        visit[i] = false;
    }
    dfs_2(pG, 0);

    return 0;
}

void BFS(myGraph *pG, int i) {
    queue<int> q;
    visit[i] = true;
    q.push(i);
    printf("%c  ", pG->vexs[i]);
    while (q.size() != 0) {
        int front = q.front();
        q.pop();
        for (int i = 0; i < pG->n; ++i) {
            if (pG->edges[front][i] != 0 && visit[i] == false) {
                printf("%c  ", pG->vexs[i]);
                visit[i] = true;
                q.push(i);
            }
        }
    }
}

void dfs_1(myGraph *pG, int i) {
    printf("%c  ", pG->vexs[i]);
    visit[i] = true;
    for (int j = 0; j < pG->n; ++j) {
        if (pG->edges[i][j] != 0 && visit[j] == false) {
            dfs_1(pG, j);
        }
    }
}

void dfs_2(myGraph *pG, int i) {
    stack<int> s;
    printf("%c  ", pG->vexs[i]);
    visit[i] = true;
    s.push(i);
    while (s.size() != 0) {
        int top = s.top();
        s.pop();
        for (int j = 0; j < pG->n; ++j) {
            if (pG->edges[top][j] != 0 && visit[j] == false) {
                printf("%c  ", pG->vexs[j]);
                visit[j] = true;
                s.push(j);
            }
        }
    }

}

myGraph *createGraph() {
    int i, j, k, type, weight = 9999;
    char ch1, ch2;

    myGraph *pG = (myGraph *) malloc(sizeof(myGraph));
//    if (!pG)
//    {
//        printf("malloc is failed!");
//        exit(-1);
//    }
    printf("请输入顶点数：");
    scanf("%d", &pG->n);
    printf("请输入边数:");
    scanf("%d", &pG->e);

    printf("请输入顶点信息(顶点标志):");
    for (i = 0; i < pG->n; ++i) {
        getchar();     // 第一次循环用来接收 scanf("%d %d", &pG->n, &pG->e)的空格和回车;  其它循环接收 scanf("%c", &pG->vertices[i]);的空格回车
        scanf("%c", &(pG->vexs[i]));
    }

    // 对 邻接矩阵进行初始化
    for (i = 0; i < MAXSIZE; ++i) {
        for (j = 0; j < MAXSIZE; ++j) {
            pG->edges[i][j] = 0;               // 在有权值的图中 因为0可能被误以为是权值，所以有时用无穷大表示没有边 这里我用0等下打印的适合好看一点
        }
    }

    printf("请输入图的类型(无向图:0)、(有向图:1):\n");
    scanf("%d", &type);

    for (k = 0; k < pG->e; ++k) {
        fflush(stdin);                          // 刷新缓冲区
        printf("请输入%d条边的两个顶点以及权值(以空格隔开)：", k + 1);
        scanf("%c %c %d", &ch1, &ch2, &weight);

        // 得到 两顶点在邻接矩阵中的下标 i j
        for (i = 0; ch1 != pG->vexs[i]; ++i);
        for (j = 0; ch2 != pG->vexs[j]; ++j);


//        printf("i = %d, j = %d\n", i, j);
        if (type == 0) {
            pG->edges[i][j] = pG->edges[j][i] = weight;
        } else {
            pG->edges[i][j] = weight;
        }
    }

    return pG;
}

void showGraph(myGraph *pG) {
    int i, j;
    printf("vexs is : ");
    for (i = 0; i < pG->n; ++i) {
        printf("%c  ", pG->vexs[i]);
    }
    printf("\n");

    printf("邻接矩阵：\n");
    for (i = 0; i < pG->n; ++i) {
        for (j = 0; j < pG->n; ++j) {
            printf("%d   ", pG->edges[i][j]);
        }
        printf("\n");
    }
}
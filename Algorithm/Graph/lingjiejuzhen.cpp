#include <queue>
#include <stack>
#include <iostream>
#include <memory.h>

#define MAXSIZE 10                                  // 最大顶点数 10
#define INFINITY 9999                               // 无穷大

using namespace std;

typedef struct {
    char vexs[MAXSIZE];                         // 存放顶点元素
    int edges[MAXSIZE][MAXSIZE];                // 邻接矩阵 存放边与边之间的关系
    int n;                                      // 顶点数
    int e;                                      // 边数
} myGraph;

bool visit[MAXSIZE];  // visit[i] = true 表示顶点vi被访问
int dist[MAXSIZE];    // dist[i]:记录顶点vi的最短距离
int path[MAXSIZE];    // 记录最短路径

int dp[MAXSIZE][MAXSIZE];
int pathDp[MAXSIZE][MAXSIZE];

int lowcost[MAXSIZE]; // lowcost[i]记录顶点i到目前最小生成树边上的最小权值

myGraph *createGraph();                        // 创建图
void showGraph(myGraph *pG);                   // 打印邻接矩阵
void BFS(myGraph *pG, int i);                      // bfs
void dfs_1(myGraph *pG, int i);                    // DFS 递归
void dfs_2(myGraph *pG, int i);                    // DFS 栈
void Dijkstra(myGraph *pG, int i);     // Dijkstra求有权图的最短路径 只能打印从源点vi到vj的路径，不能打印非源点到vj的路径
void BFS_minPath(myGraph *pG, int i);              // BFS求无权图的最短路径，只能打印从源点vi到vj的路径，不能打印非源点到vj的路径
void printPath(myGraph *pG, int path[], int i, int j);
void floyd(myGraph *pG);                           // floyd
void printPathDp(myGraph * pG,int i, int j);  // 打印floyd的路径
void prim(myGraph *pG, int v,int &sum);      // 求最小生成树的代价


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

    // 无权图单元最短路径
    BFS_minPath(pG, 3);
    printf("\nLength: %d\n", dist[5]);
    printPath(pG, path,3, 5);

    // Dijkstra 求最短路径
    memset(dist, -1, sizeof(dist));  //
    memset(path, -1, sizeof(path));  //
    memset(visit, false, sizeof(visit));
    printf("\n*** Dijkstra ***\n");
    Dijkstra(pG, 3);
    printf("\nLength: %d\n", dist[5]);
    printPath(pG, path,3, 5);

    // floyd 求最短路径
    printf("\n*** floyd  ***\n");
    floyd(pG);
    printf("len : %d\n", dp[3][5]);
    printf("%c ", pG->vexs[3]);
    printPathDp(pG, 3, 5);
    printf("%c ", pG->vexs[5]);

    // prim 求最小生成树
    printf("\n*** prim  ***\n");
    int sum = 0;
    prim(pG,0, sum);
    printf("\nsum  = %d \n", sum);
    
    return 0;
}

/**
    思路:从图中任选一个顶点，把它当成一棵树
    然后从与这颗树相邻的边中，找到权值最小的边，再把该边以及其所连接的顶点，并入树中，重复此过程直到图中所有顶点都被并入树中
    时间复杂度O（N^2）
 */
void prim(myGraph *pG, int v, int &sum){
    for (int i = 0; i < pG->n; ++i) {  // 初始化
        visit[i] = false;
        lowcost[i] = pG->edges[v][i];
//        if (lowcost[i] != INFINITY){  // 可以用path记录最小生成树的路径 打印 我直接打印
//            path[i] = v;
//        }else{
//            path[i] = -1;
//        }
    }
    visit[v] = true;
    lowcost[v] = 0;
    printf("%c ", pG->vexs[v]); // 打印
    for (int i = 0; i < pG->n - 1; ++i) {
        int min = INFINITY;
        int u = v;
        for (int j = 0; j < pG->n; ++j) {
            if (!visit[j] && lowcost[j] < min) {
                min = lowcost[j];
                u = j;
            }
        }
        visit[u] = true;
        printf("%c ", pG->vexs[u]); // 打印
        sum += lowcost[u];
        for (int k = 0; k <pG->n ; ++k) {
            if (!visit[k] && pG->edges[u][k] != INFINITY) {
                if (lowcost[k] > pG->edges[u][k]){ // 与迪杰什塔拉的区别
                    lowcost[k] = pG->edges[u][k];
//                    path[k] = v;
                }
            }
        }
    }
}

void BFS_minPath(myGraph *pG, int i){
    memset(dist, -1, sizeof(dist));  //
    memset(path, -1, sizeof(path));  //
    memset(visit, false, sizeof(visit));

    queue<int> q;
    dist[i] = 0; // 从vi到vi 路径长度为0
    visit[i] = true;
    q.push(i);
    while (q.size() != 0) {
        int front = q.front();
        q.pop();
        for (int i = 0; i<pG->n ; ++i) {
            if (!visit[i] && pG->edges[front][i] != INFINITY) {
                dist[i] = dist[front] + 1;
                visit[i] = true;
                path[i] = front;
                q.push(i);
            }
        }
    }
}

void floyd(myGraph *pG){
    for (int i = 0; i <pG->n ; ++i) { // 初始化
        for (int j = 0; j < pG->n; ++j) {
            dp[i][j] = pG->edges[i][j];
            pathDp[i][j] = -1;
        }
    }

    for (int i = 0; i < pG->n; ++i) {
        for (int j = 0; j < pG->n; ++j) {
            for (int k = 0; k < pG->n; ++k) {
                int temp = dp[i][k] + dp[k][j];
                if (dp[i][j] > temp) {
                    dp[i][j] = temp;
                    pathDp[i][j] = k;
//                    printf("%d \n", k);
                }
            }
        }
    }
}

void printPathDp(myGraph * pG,int i, int j){  // 只能打印 i -> j 之间的路径 不包括i，j
    if (pathDp[i][j] == -1){
        return;
    }
    int k = pathDp[i][j];
    printPathDp(pG, i, k);
    printf("%c ", pG->vexs[k]);
    printPathDp(pG, k, j);
}
/**
    思想：设置两个顶点集合S，T，其中S存放图中已找到最短路径的顶点,T存放图中剩余顶点
         初始时S包含源点v0，然后从T中选取到V0路径长度最小的顶点vi，将vi纳入S，并修改v0到T中的最短路径值，直到T的顶点全部并入S为止
    时间复杂度：O(N^2)

 */
void Dijkstra(myGraph *pG, int v){
    for (int i = 0; i <pG->n ; ++i) { // 初始化 INFINITY:表示无穷大  即不通
        dist[i] = pG->edges[v][i];
        visit[i] = false;
        if (dist[i] != INFINITY){
            path[i] = v;
        }else{
            path[i] = -1;
        }
    }

    visit[v] = true;  // 将源点加入集合S
    dist[v] = 0;
    for (int i = 0; i < pG->n-1; ++i) { //  n-1次
        int temp = INFINITY;
        int u = v;
        for (int j = 0; j < pG->n; ++j) {  // 选取 T到S中的最短路径所在的顶点Vu
            if (!visit[j] && dist[j] < temp){
                temp = dist[j];
                u = j;
            }
        }

        visit[u] = true; // 将其纳入集合S
        for (int k = 0; k < pG->n; ++k) {  // 更新源点v0到T中的最短路径
            if (!visit[k] && pG->edges[u][k] != INFINITY){
                int newDist = dist[u] + pG->edges[u][k];
                if (newDist < dist[k]) {
                    dist[k] = newDist;
                    path[k] = u;
                }
            }
        }
    }
}

// 打印 从i到j的最短路径
void printPath(myGraph *pG, int path[], int i, int j) {
    if (i == j) {
        printf("%c  ", pG->vexs[i]);
        return;
    }
    printPath(pG, path, i, path[j]);
    printf("%c ", pG->vexs[j]);
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
            if (pG->edges[front][i] != INFINITY && visit[i] == false) {
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
            pG->edges[i][j] = INFINITY;               // 在有权值的图中 因为0可能被误以为是权值，所以有时用无穷大表示没有边 这里我用0等下打印的适合好看一点
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
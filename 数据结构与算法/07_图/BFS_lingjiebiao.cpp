#include <queue>
#include <stack>
#include <iostream>
#include <memory.h>

#define MAXSIZE 10                                  // 最大顶点数 10
#define INFINITY 9999                               // 无穷大
using namespace std;

typedef struct node {
    int adjVex;                                     // 邻接点域
    int info;                                       // 权值
    struct node *pNext;                            // 下一条邻接边的结点地址
} edgesNode;

typedef struct vNode {
    char vertex;                                    // 顶点标志
    edgesNode *firstedges;                         // 保存第一个边节点地址的指针
} vertexNode;

typedef struct {
    vertexNode adjlist[MAXSIZE];                    // 顶点数组
    int n;                                          // 顶点数
    int e;                                          // 边数
} ALGraph;

bool visit[MAXSIZE];  // visit[i] = true 表示顶点vi被访问
int dist[MAXSIZE];    // dist[i]:记录顶点vi的最短距离
int path[MAXSIZE];    // 记录最短路径
int ve[MAXSIZE]; // 各节点最早开始时间
int vl[MAXSIZE]; // 各节点最晚开始时间

void createGraph(ALGraph *pG);                     // 创建图
void showGraph(ALGraph *pG);                       // 打印邻接表
void BFS(ALGraph *pG, int i);                      // bfs
void dfs_1(ALGraph *pG, int i);                    // DFS 递归
void dfs_2(ALGraph *pG, int i);                    // DFS 栈
void BFS_minPath(ALGraph *pG, int i);              // BFS求无权图的最短路径，只能打印从源点vi到vj的路径，不能打印非源点到vj的路径
void printPath(ALGraph *pG, int path[], int i, int j);

void Dijkstra(ALGraph *pG, int i);     // Dijkstra求有权图的最短路径 只能打印从源点vi到vj的路径，不能打印非源点到vj的路径
bool TopoSort(ALGraph *pG);           // 拓扑排序
void pathItoJ(ALGraph *pG, int i, int j, bool visit[],vector<int> path);  // 打印从顶点i到j的所有路径

bool TopSort2(ALGraph *pG, int marked[],vector<char >& res); // DFS 拓扑排序

// 关键路径
ALGraph * createReverse(ALGraph * pG);
bool TopoSort_path(ALGraph *pG, int flag);
void criticalPath(ALGraph *pG);


int main(void) {
    ALGraph G;
    createGraph(&G);
    showGraph(&G);

//    // BFS
//    cout << "bfs: ";
//    for (int i = 0; i < MAXSIZE; ++i) {  // 访问数组初始化
//        visit[i] = false;
//    }
//    BFS(&G, 0);
//
//    // DFS 递归
//    printf("\nDFS1: ");
//    for (int i = 0; i < MAXSIZE; ++i) {  // 访问数组初始化
//        visit[i] = false;
//    }
//    dfs_1(&G, 0);
//
//    // DFS 栈
//    printf("\nDFS2: ");
//    for (int i = 0; i < MAXSIZE; ++i) {  // 访问数组初始化
//        visit[i] = false;
//    }
//    dfs_2(&G, 0);

//    printf("\n无向图单源最短路:\n");
//    BFS_minPath(&G, 4); // 初始源点为v0
//    printf("------\n");
//    printPath(&G, path, 4, 7);

    printf("\n******拓扑排序******\n");
    if (TopoSort(&G)) {
        printf("ok\n");
    } else {
        printf("false\n");
    }

//    cout << endl;
//    cout << " DFS拓扑排序   " << endl;
//    int finishTime[G.n];
//    memset(finishTime, 0, sizeof(finishTime));
//    memset(visit, false, sizeof(visit));
//    int time = 0;
//    for (int i = 0; i <G.n ; ++i) {
//        if (!visit[i]) {
//            topSort2(&G, i, visit, time, finishTime);
//        }
//    }
//
//    for (int i = 0; i < G.n; ++i) {
//        i
//    }

//    cout << "i  to J DFS path:" << endl;
//    memset(visit, false, sizeof(visit));
//    vector<int> path;
//    pathItoJ(&G, 3, 4, visit, path);

    int marked[500];
    memset(marked, 0, sizeof(marked));
    vector<char > res;
    if (TopSort2(&G, marked, res)){
        cout << "ok" << endl;
        for (int i = res.size(); i >= 0 ; --i) {
            cout << res[i] << "   ";
        }
    }else{
        cout << "false" << endl;
    }


    cout << "\n\n关键路径 " << endl;
    criticalPath(&G);
    return 0;
}


void pathItoJ(ALGraph *pG, int i, int j, bool visit[],vector<int> path){
    if (i == j) {
        path.push_back(i);
        for (int k = 0; k <path.size() ; ++k) {
            cout << pG->adjlist[path[k]].vertex << "  ";
        }
        cout << endl;
        return;
    }
    visit[i] = true;
    path.push_back(i);
    edgesNode * p = pG->adjlist[i].firstedges;
    while (p != NULL) {
        int k = p->adjVex;
        if (!visit[k]) {
            pathItoJ(pG, k, j, visit, path);
        }
        p = p->pNext;
    }
    visit[i] = false;  // 回溯
    path.pop_back();   // 回溯
}

bool TopoSort(ALGraph *pG) {
//    printf("8664646\n");
    int indegree[pG->n]; // 顶点i的入度
    memset(indegree, 0, sizeof(indegree));
    queue<int> q;  // 只要是容器就行 队列到时候是正序

    // 统计每个顶点的入度
    for (int i = 0; i < pG->n; ++i) {
        edgesNode *p = pG->adjlist[i].firstedges;
        while (p != NULL) {
            indegree[p->adjVex]++;
            p = p->pNext;
        }
    }

//    for (int i = 0; i < pG->n; ++i) {
//        printf("%d \n", indegree[i]);
//    }

    // 入度为0 入队
    for (int i = 0; i < pG->n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    int count = 0;  // 统计已经输出的顶点数
    while (q.size() != 0) {
        int front = q.front(); // 弹出一个入度为0的点
        q.pop();
        printf("%c  ", pG->adjlist[front].vertex);
        count++;
        // 将所有front指向的节点 入度-1
        edgesNode *p = pG->adjlist[front].firstedges;
        while (p != NULL) {
            indegree[p->adjVex]--; // 入度-1
            if (indegree[p->adjVex] == 0) { // 发现入度为0的点
                q.push(p->adjVex);
            }
            p = p->pNext;
        }

    }

    if (count < pG->n) {
        return false;  // 失败 有向图中 有回路
    } else {
        return true;
    }
}

// DFS 拓扑排序
// marked[i] = 0 尚未访问
// marked[i] = -1 正在当前节点及其子孙
// marked[i] = 1 已经被访问
bool __TopSort2(ALGraph *pG, int v, int marked[],vector<char> &res){
    if (marked[v] == -1){
        return false; //有环
    }
    if (marked[v] == 1){
        return true;
    }
    marked[v] = -1;
    // 遍历相邻节点
    edgesNode *p = pG->adjlist[v].firstedges;
    while (p != NULL) {
        int k = p->adjVex;
        if (!__TopSort2(pG, k, marked, res)) {
            return false;
        }
        p = p->pNext;
    }
    marked[v] = 1;
    res.push_back(pG->adjlist[v].vertex);
    return true; // 无环
}


bool TopSort2(ALGraph *pG, int marked[],vector<char >& res){
    for (int i = 0; i <pG->n ; ++i) {
        if (!__TopSort2(pG, i, marked, res)) {
            return false;
        }
    }
    return true;
}

/**
 *  关键路径：图G采用邻接表存储结构，构造图G的逆邻接表G2，对G采用拓扑排序，计算出各顶点最早发生时间ve[]
 *          对G2采用拓扑排序，计算最晚发生时间vl[]
 *          然后再遍历图，活动k->j的最早时间（ve[k]）与最晚时间（vl[j]-权值） 相等，即为关键活动
 */


// 构造逆邻接表
ALGraph * createReverse(ALGraph * pG){
    if (pG == NULL) {
        return pG;
    }
    // 初始化
    ALGraph *G2 = (ALGraph *) malloc(sizeof(ALGraph));
    G2->n = pG->n;
    G2->e = pG->e;
    for (int i = 0; i <G2->n ; ++i) {
        G2->adjlist[i].vertex = pG->adjlist[i].vertex;
        G2->adjlist[i].firstedges = NULL;
    }
    // 构造
    for (int i = 0; i <pG->n ; ++i) {
        edgesNode *p = pG->adjlist[i].firstedges;
        while (p != NULL) {
            int k = p->adjVex;
            edgesNode *newNode = (edgesNode *) malloc(sizeof(edgesNode));
            newNode->adjVex = i;
            newNode->info = p->info;
            newNode->pNext = G2->adjlist[k].firstedges;  // 头插法
            G2->adjlist[k].firstedges = newNode;
            p = p->pNext;
        }
    }
    return G2;
}

// 用于关键路径
bool TopoSort_path(ALGraph *pG, int flag) {
    int indegree[pG->n]; // 顶点i的入度
    memset(indegree, 0, sizeof(indegree));
    queue<int> q;  // 只要是容器就行 队列到时候是正序

    // 统计每个顶点的入度
    for (int i = 0; i < pG->n; ++i) {
        edgesNode *p = pG->adjlist[i].firstedges;
        while (p != NULL) {
            indegree[p->adjVex]++;
            p = p->pNext;
        }
    }
    if (flag == 1){ // 求 各顶点最早时间
        memset(ve, 0, sizeof(ve)); // 初始
    } else{ // 求各顶点最晚时间
        memset(vl, 0, sizeof(vl));
        vl[pG->n - 1] = ve[pG->n - 1];
    }


    // 入度为0 入队
    for (int i = 0; i < pG->n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    int count = 0;  // 统计已经输出的顶点数
    while (q.size() != 0) {
        int front = q.front(); // 弹出一个入度为0的点
        q.pop();
        printf("%c  ", pG->adjlist[front].vertex);
        count++;
        // 将所有front指向的节点 入度-1
        edgesNode *p = pG->adjlist[front].firstedges;
        while (p != NULL) {
            int k = p->adjVex;
            indegree[k]--; // 入度-1
            if (indegree[k] == 0) { // 发现入度为0的点
                q.push(k);
            }

            if (flag == 1) {
                if (ve[front] + p->info > ve[k]){ // 更新节点k的最早发生时间，取最大值
                    ve[k] = ve[front] + p->info;
                }
            } else{
                if (vl[front] - p->info < vl[k]) {
                    vl[k] = vl[front] - p->info;
                }
            }
            p = p->pNext;
        }
    }

    if (count < pG->n) {
        return false;  // 失败 有向图中 有回路
    } else {
        return true;
    }
}

void criticalPath(ALGraph *pG){
    if (pG == NULL) {
        return;
    }
    ALGraph *G2 = createReverse(pG);
    TopoSort_path(pG, 1);
    TopoSort_path(G2, 2);
    for (int i = 0; i < pG->n; ++i) {
        edgesNode *p = pG->adjlist[i].firstedges;
        while (p) {
            int k = p->adjVex;
            if (ve[i] == vl[k] - p->info) {
                cout << pG->adjlist[i].vertex << "->" << pG->adjlist[k].vertex;
            }
            p = p->pNext;
        }
    }
}

// 广度优先遍历
void BFS(ALGraph *pG, int i) {
    queue<int> q;
    printf("%c ", pG->adjlist[i].vertex);
    visit[i] = true;
    q.push(i);
    while (q.size() != 0) {
        int front = q.front();
        q.pop();
        edgesNode *p = pG->adjlist[front].firstedges; // 获取节点adjlist[front]的边表
        while (p != NULL) {      // 容易漏是否访问这个条件
            if (visit[p->adjVex] == false) {
                printf("%c ", pG->adjlist[p->adjVex].vertex);
                visit[p->adjVex] = true;
                q.push(p->adjVex);
            }
            p = p->pNext;
        }
    }
}

// DFS 递归
void dfs_1(ALGraph *pG, int i) {
    printf("%c ", pG->adjlist[i].vertex);
    visit[i] = true;

    edgesNode *p = pG->adjlist[i].firstedges;
    while (p != NULL) {
        if (visit[p->adjVex] == false) {
            dfs_1(pG, p->adjVex);
        }
        p = p->pNext;
    }
}

// DFS 非递归 栈
void dfs_2(ALGraph *pG, int i) {
    stack<int> s;
    visit[i] = true;
    printf("%c ", pG->adjlist[i].vertex);
    s.push(i);
    while (s.size() != 0) {
        int top = s.top();
        s.pop();
        edgesNode *p = pG->adjlist[top].firstedges;
        while (p != NULL) {
            if (visit[p->adjVex] == false) {
                visit[p->adjVex] = true;
                printf("%c ", pG->adjlist[p->adjVex].vertex);
                s.push(p->adjVex);
                p = pG->adjlist[p->adjVex].firstedges;  // 指向顶点数组标号为p->adjVex的节点
            } else { // p = p->next 是在else里面 与前面不一样
                p = p->pNext;
            }
        }
    }
}

/***
 * BFS (无权图)求单源最短路径 ，只能打印从源点vi到vj的路径，不能打印非源点到vj的路径
 * 思考: 1. dist 起到了什么作用?
 *                起到了visit[]作用 只要dist[i] != -1 就代表没访问过
 */

void BFS_minPath(ALGraph *pG, int i) {
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
//        printf("%c \n", pG->adjlist[front].vertex);
        edgesNode *p = pG->adjlist[front].firstedges;

        while (p != NULL) {
            int j = p->adjVex;
            if (visit[j] == false) { // vj没有被访问过
                visit[j] = true;
                dist[j] = dist[front] + 1; // 更新从源点到vj的路径长度  也起到了visit[]的效果
                path[j] = front;  // 记录最短路径vj的前一个顶点
//                cout << "path[" << j << "]  =  " << front << endl;
                q.push(j);
            }
            p = p->pNext;
        }
    }
}


// 打印 从i到j的最短路径
void printPath(ALGraph *pG, int path[], int i, int j) {
    if (i == j) {
        printf("%c  ", pG->adjlist[j].vertex);
        return;
    }
    printPath(pG, path, i, path[j]);
    printf("%c ", pG->adjlist[j].vertex);
}

void createGraph(ALGraph *pG) {
    int i, j, k, type;
    /********加上weight表示权值***********/
    int weight;
    /***************和不加权值的区别之处***************/
    char ch1, ch2;
    printf("请输入图的顶点个数和边数(空格隔开)：");
    scanf("%d %d", &pG->n, &pG->e);

    printf("请输入图的顶点信息；");
    for (i = 0; i < pG->n; ++i) {
        getchar();       // 第一次循环用来接收 scanf("%d %d", &pG->n, &pG->e)的空格和回车;  其它循环接收 scanf("%c", &pG->vertices[i]);的空格回车
        scanf("%c", &(pG->adjlist[i].vertex));      // 输入顶点信息
        pG->adjlist[i].firstedges = NULL;           // 指向第一个边节点的指针置为 null
    }

    printf("请输入图的类型(无向图:0)、(有向图:1):\n");
    scanf("%d", &type);

    for (k = 0; k < pG->e; ++k) {
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
        if (!pNew) {
            printf("malloc is failed!\n");
            exit(-1);
        }
        if (type == 1) {
            // 有向图
            pNew->adjVex = j;    // 不要写成i了
            /*********************/
            pNew->info = weight;
            /**********************/
            pNew->pNext = pG->adjlist[i].firstedges;
            pG->adjlist[i].firstedges = pNew;
        } else {
            pNew->adjVex = j;
            pNew->info = weight;
            pNew->pNext = pG->adjlist[i].firstedges;   // 易出错
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


void showGraph(ALGraph *pG) {
    int i;
    printf("该图的邻接表为：\n");
    for (i = 0; i < pG->n; ++i) {
        printf("%d   %c     ", i, pG->adjlist[i].vertex);
        edgesNode *p = pG->adjlist[i].firstedges;
        while (p != NULL) {
            printf("%d | %d     ", p->adjVex, p->info);
            p = p->pNext;
        }
        printf("\n");
    }
}
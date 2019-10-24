#include <queue>
#include <stack>
#include <iostream>

#define MAXSIZE 10                                  // 最大顶点数 10
using namespace std;

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

bool visit[MAXSIZE];


void createGraph(ALGraph * pG);                     // 创建图
void showGraph(ALGraph * pG);                       // 打印邻接表
void BFS(ALGraph * pG, int i);                      // bfs
void dfs_1(ALGraph * pG, int i);                    // DFS 递归
void dfs_2(ALGraph * pG, int i);                    // DFS 栈

int main(void)
{
    ALGraph G;
    createGraph(&G);
    showGraph(&G);

    // BFS
    cout << "bfs: ";
    for (int i = 0; i < MAXSIZE; ++i) {  // 访问数组初始化
        visit[i] = false;
    }
    BFS(&G, 0);

    // DFS 递归
    printf("\nDFS1: ");
    for (int i = 0; i < MAXSIZE; ++i) {  // 访问数组初始化
        visit[i] = false;
    }
    dfs_1(&G, 0);

    // DFS 栈
    printf("\nDFS2: ");
    for (int i = 0; i < MAXSIZE; ++i) {  // 访问数组初始化
        visit[i] = false;
    }
    dfs_2(&G, 0);

    return 0;
}

// 广度优先遍历
void BFS(ALGraph * pG, int i){
    queue<int> q;
    printf("%c ", pG->adjlist[i].vertex) ;
    visit[i] = true;
    q.push(i);
    while (q.size() != 0) {
        int front = q.front();
        q.pop();
        edgesNode * p = pG->adjlist[front].firstedges; // 获取节点adjlist[front]的边表
        while (p != NULL){
            if (visit[p->adjVex] == false) {
                printf("%c ", pG->adjlist[p->adjVex].vertex) ;
                visit[p->adjVex] = true;
                q.push(p->adjVex);
            }
            p = p->pNext;
        }
    }
}


void dfs_1(ALGraph * pG, int i){
    printf("%c ", pG->adjlist[i].vertex) ;
    visit[i] = true;

    edgesNode *p = pG->adjlist[i].firstedges;
    while (p != NULL) {
        if (visit[p->adjVex] == false){
            dfs_1(pG, p->adjVex);
        }
        p = p->pNext;
    }
}


// DFS 非递归 栈
void dfs_2(ALGraph * pG, int i){
    stack<int> s;
    visit[i] = true;
    printf("%c ", pG->adjlist[i].vertex);
    s.push(i);
    while (s.size() != 0){
        int top = s.top();
        s.pop();
        edgesNode *p = pG->adjlist[top].firstedges;
        while (p != NULL) {
            if (visit[p->adjVex] == false){
                visit[p->adjVex] = true;
                printf("%c ", pG->adjlist[p->adjVex].vertex);
                s.push(p->adjVex);
                p = pG->adjlist[p->adjVex].firstedges;  // 指向顶点数组标号为p->adjVex的节点
            }else{
                p = p->pNext;
            }
        }
    }
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
        getchar();       // 第一次循环用来接收 scanf("%d %d", &pG->n, &pG->e)的空格和回车;  其它循环接收 scanf("%c", &pG->vertices[i]);的空格回车
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
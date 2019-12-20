#include <queue>
#include <stack>
#include <iostream>
#include <memory.h>

#define MAXSIZE 10                                  // ��󶥵��� 10
#define INFINITY 9999                               // �����

using namespace std;

typedef struct {
    char vexs[MAXSIZE];                         // ��Ŷ���Ԫ��
    int edges[MAXSIZE][MAXSIZE];                // �ڽӾ��� ��ű����֮��Ĺ�ϵ
    int n;                                      // ������
    int e;                                      // ����
} myGraph;

bool visit[MAXSIZE];  // visit[i] = true ��ʾ����vi������
int dist[MAXSIZE];    // dist[i]:��¼����vi����̾���
int path[MAXSIZE];    // ��¼���·��

int dp[MAXSIZE][MAXSIZE];
int pathDp[MAXSIZE][MAXSIZE];

int lowcost[MAXSIZE]; // lowcost[i]��¼����i��Ŀǰ��С���������ϵ���СȨֵ

myGraph *createGraph();                        // ����ͼ
void showGraph(myGraph *pG);                   // ��ӡ�ڽӾ���
void BFS(myGraph *pG, int i);                      // bfs
void dfs_1(myGraph *pG, int i);                    // DFS �ݹ�
void dfs_2(myGraph *pG, int i);                    // DFS ջ
void Dijkstra(myGraph *pG, int i);     // Dijkstra����Ȩͼ�����·�� ֻ�ܴ�ӡ��Դ��vi��vj��·�������ܴ�ӡ��Դ�㵽vj��·��
void BFS_minPath(myGraph *pG, int i);              // BFS����Ȩͼ�����·����ֻ�ܴ�ӡ��Դ��vi��vj��·�������ܴ�ӡ��Դ�㵽vj��·��
void printPath(myGraph *pG, int path[], int i, int j);
void floyd(myGraph *pG);                           // floyd
void printPathDp(myGraph * pG,int i, int j);  // ��ӡfloyd��·��
void prim(myGraph *pG, int v,int &sum);      // ����С�������Ĵ���


int main(void) {
    myGraph *pG = createGraph();
    showGraph(pG);

    // BFS
    cout << "bfs: ";
    for (int i = 0; i < MAXSIZE; ++i) {  // ���������ʼ��
        visit[i] = false;
    }
    BFS(pG, 0);

    // DFS �ݹ�
    printf("\nDFS1: ");
    for (int i = 0; i < MAXSIZE; ++i) {  // ���������ʼ��
        visit[i] = false;
    }
    dfs_1(pG, 0);

    // DFS ջ
    printf("\nDFS2: ");
    for (int i = 0; i < MAXSIZE; ++i) {  // ���������ʼ��
        visit[i] = false;
    }
    dfs_2(pG, 0);

    // ��Ȩͼ��Ԫ���·��
    BFS_minPath(pG, 3);
    printf("\nLength: %d\n", dist[5]);
    printPath(pG, path,3, 5);

    // Dijkstra �����·��
    memset(dist, -1, sizeof(dist));  //
    memset(path, -1, sizeof(path));  //
    memset(visit, false, sizeof(visit));
    printf("\n*** Dijkstra ***\n");
    Dijkstra(pG, 3);
    printf("\nLength: %d\n", dist[5]);
    printPath(pG, path,3, 5);

    // floyd �����·��
    printf("\n*** floyd  ***\n");
    floyd(pG);
    printf("len : %d\n", dp[3][5]);
    printf("%c ", pG->vexs[3]);
    printPathDp(pG, 3, 5);
    printf("%c ", pG->vexs[5]);

    // prim ����С������
    printf("\n*** prim  ***\n");
    int sum = 0;
    prim(pG,0, sum);
    printf("\nsum  = %d \n", sum);
    
    return 0;
}

/**
    ˼·:��ͼ����ѡһ�����㣬��������һ����
    Ȼ�������������ڵı��У��ҵ�Ȩֵ��С�ıߣ��ٰѸñ��Լ��������ӵĶ��㣬�������У��ظ��˹���ֱ��ͼ�����ж��㶼����������
    ʱ�临�Ӷ�O��N^2��
 */
void prim(myGraph *pG, int v, int &sum){
    for (int i = 0; i < pG->n; ++i) {  // ��ʼ��
        visit[i] = false;
        lowcost[i] = pG->edges[v][i];
//        if (lowcost[i] != INFINITY){  // ������path��¼��С��������·�� ��ӡ ��ֱ�Ӵ�ӡ
//            path[i] = v;
//        }else{
//            path[i] = -1;
//        }
    }
    visit[v] = true;
    lowcost[v] = 0;
    printf("%c ", pG->vexs[v]); // ��ӡ
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
        printf("%c ", pG->vexs[u]); // ��ӡ
        sum += lowcost[u];
        for (int k = 0; k <pG->n ; ++k) {
            if (!visit[k] && pG->edges[u][k] != INFINITY) {
                if (lowcost[k] > pG->edges[u][k]){ // ��Ͻ�ʲ����������
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
    dist[i] = 0; // ��vi��vi ·������Ϊ0
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
    for (int i = 0; i <pG->n ; ++i) { // ��ʼ��
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

void printPathDp(myGraph * pG,int i, int j){  // ֻ�ܴ�ӡ i -> j ֮���·�� ������i��j
    if (pathDp[i][j] == -1){
        return;
    }
    int k = pathDp[i][j];
    printPathDp(pG, i, k);
    printf("%c ", pG->vexs[k]);
    printPathDp(pG, k, j);
}
/**
    ˼�룺�����������㼯��S��T������S���ͼ�����ҵ����·���Ķ���,T���ͼ��ʣ�ඥ��
         ��ʼʱS����Դ��v0��Ȼ���T��ѡȡ��V0·��������С�Ķ���vi����vi����S�����޸�v0��T�е����·��ֵ��ֱ��T�Ķ���ȫ������SΪֹ
    ʱ�临�Ӷȣ�O(N^2)

 */
void Dijkstra(myGraph *pG, int v){
    for (int i = 0; i <pG->n ; ++i) { // ��ʼ�� INFINITY:��ʾ�����  ����ͨ
        dist[i] = pG->edges[v][i];
        visit[i] = false;
        if (dist[i] != INFINITY){
            path[i] = v;
        }else{
            path[i] = -1;
        }
    }

    visit[v] = true;  // ��Դ����뼯��S
    dist[v] = 0;
    for (int i = 0; i < pG->n-1; ++i) { //  n-1��
        int temp = INFINITY;
        int u = v;
        for (int j = 0; j < pG->n; ++j) {  // ѡȡ T��S�е����·�����ڵĶ���Vu
            if (!visit[j] && dist[j] < temp){
                temp = dist[j];
                u = j;
            }
        }

        visit[u] = true; // �������뼯��S
        for (int k = 0; k < pG->n; ++k) {  // ����Դ��v0��T�е����·��
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

// ��ӡ ��i��j�����·��
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

    printf("�����붥������");
    scanf("%d", &pG->n);
    printf("���������:");
    scanf("%d", &pG->e);

    printf("�����붥����Ϣ(�����־):");
    for (i = 0; i < pG->n; ++i) {
        getchar();     // ��һ��ѭ���������� scanf("%d %d", &pG->n, &pG->e)�Ŀո�ͻس�;  ����ѭ������ scanf("%c", &pG->vertices[i]);�Ŀո�س�
        scanf("%c", &(pG->vexs[i]));
    }

    // �� �ڽӾ�����г�ʼ��
    for (i = 0; i < MAXSIZE; ++i) {
        for (j = 0; j < MAXSIZE; ++j) {
            pG->edges[i][j] = INFINITY;               // ����Ȩֵ��ͼ�� ��Ϊ0���ܱ�����Ϊ��Ȩֵ��������ʱ��������ʾû�б� ��������0���´�ӡ���ʺϺÿ�һ��
        }
    }

    printf("������ͼ������(����ͼ:0)��(����ͼ:1):\n");
    scanf("%d", &type);

    for (k = 0; k < pG->e; ++k) {
        fflush(stdin);                          // ˢ�»�����
        printf("������%d���ߵ����������Լ�Ȩֵ(�Կո����)��", k + 1);
        scanf("%c %c %d", &ch1, &ch2, &weight);

        // �õ� ���������ڽӾ����е��±� i j
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

    printf("�ڽӾ���\n");
    for (i = 0; i < pG->n; ++i) {
        for (j = 0; j < pG->n; ++j) {
            printf("%d   ", pG->edges[i][j]);
        }
        printf("\n");
    }
}
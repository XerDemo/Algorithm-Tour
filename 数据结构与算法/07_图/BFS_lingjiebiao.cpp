#include <queue>
#include <stack>
#include <iostream>
#include <memory.h>

#define MAXSIZE 10                                  // ��󶥵��� 10
#define INFINITY 9999                               // �����
using namespace std;

typedef struct node {
    int adjVex;                                     // �ڽӵ���
    int info;                                       // Ȩֵ
    struct node *pNext;                            // ��һ���ڽӱߵĽ���ַ
} edgesNode;

typedef struct vNode {
    char vertex;                                    // �����־
    edgesNode *firstedges;                         // �����һ���߽ڵ��ַ��ָ��
} vertexNode;

typedef struct {
    vertexNode adjlist[MAXSIZE];                    // ��������
    int n;                                          // ������
    int e;                                          // ����
} ALGraph;

bool visit[MAXSIZE];  // visit[i] = true ��ʾ����vi������
int dist[MAXSIZE];    // dist[i]:��¼����vi����̾���
int path[MAXSIZE];    // ��¼���·��
int ve[MAXSIZE]; // ���ڵ����翪ʼʱ��
int vl[MAXSIZE]; // ���ڵ�����ʼʱ��

void createGraph(ALGraph *pG);                     // ����ͼ
void showGraph(ALGraph *pG);                       // ��ӡ�ڽӱ�
void BFS(ALGraph *pG, int i);                      // bfs
void dfs_1(ALGraph *pG, int i);                    // DFS �ݹ�
void dfs_2(ALGraph *pG, int i);                    // DFS ջ
void BFS_minPath(ALGraph *pG, int i);              // BFS����Ȩͼ�����·����ֻ�ܴ�ӡ��Դ��vi��vj��·�������ܴ�ӡ��Դ�㵽vj��·��
void printPath(ALGraph *pG, int path[], int i, int j);

void Dijkstra(ALGraph *pG, int i);     // Dijkstra����Ȩͼ�����·�� ֻ�ܴ�ӡ��Դ��vi��vj��·�������ܴ�ӡ��Դ�㵽vj��·��
bool TopoSort(ALGraph *pG);           // ��������
void pathItoJ(ALGraph *pG, int i, int j, bool visit[],vector<int> path);  // ��ӡ�Ӷ���i��j������·��

bool TopSort2(ALGraph *pG, int marked[],vector<char >& res); // DFS ��������

// �ؼ�·��
ALGraph * createReverse(ALGraph * pG);
bool TopoSort_path(ALGraph *pG, int flag);
void criticalPath(ALGraph *pG);


int main(void) {
    ALGraph G;
    createGraph(&G);
    showGraph(&G);

//    // BFS
//    cout << "bfs: ";
//    for (int i = 0; i < MAXSIZE; ++i) {  // ���������ʼ��
//        visit[i] = false;
//    }
//    BFS(&G, 0);
//
//    // DFS �ݹ�
//    printf("\nDFS1: ");
//    for (int i = 0; i < MAXSIZE; ++i) {  // ���������ʼ��
//        visit[i] = false;
//    }
//    dfs_1(&G, 0);
//
//    // DFS ջ
//    printf("\nDFS2: ");
//    for (int i = 0; i < MAXSIZE; ++i) {  // ���������ʼ��
//        visit[i] = false;
//    }
//    dfs_2(&G, 0);

//    printf("\n����ͼ��Դ���·:\n");
//    BFS_minPath(&G, 4); // ��ʼԴ��Ϊv0
//    printf("------\n");
//    printPath(&G, path, 4, 7);

    printf("\n******��������******\n");
    if (TopoSort(&G)) {
        printf("ok\n");
    } else {
        printf("false\n");
    }

//    cout << endl;
//    cout << " DFS��������   " << endl;
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


    cout << "\n\n�ؼ�·�� " << endl;
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
    visit[i] = false;  // ����
    path.pop_back();   // ����
}

bool TopoSort(ALGraph *pG) {
//    printf("8664646\n");
    int indegree[pG->n]; // ����i�����
    memset(indegree, 0, sizeof(indegree));
    queue<int> q;  // ֻҪ���������� ���е�ʱ��������

    // ͳ��ÿ����������
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

    // ���Ϊ0 ���
    for (int i = 0; i < pG->n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    int count = 0;  // ͳ���Ѿ�����Ķ�����
    while (q.size() != 0) {
        int front = q.front(); // ����һ�����Ϊ0�ĵ�
        q.pop();
        printf("%c  ", pG->adjlist[front].vertex);
        count++;
        // ������frontָ��Ľڵ� ���-1
        edgesNode *p = pG->adjlist[front].firstedges;
        while (p != NULL) {
            indegree[p->adjVex]--; // ���-1
            if (indegree[p->adjVex] == 0) { // �������Ϊ0�ĵ�
                q.push(p->adjVex);
            }
            p = p->pNext;
        }

    }

    if (count < pG->n) {
        return false;  // ʧ�� ����ͼ�� �л�·
    } else {
        return true;
    }
}

// DFS ��������
// marked[i] = 0 ��δ����
// marked[i] = -1 ���ڵ�ǰ�ڵ㼰������
// marked[i] = 1 �Ѿ�������
bool __TopSort2(ALGraph *pG, int v, int marked[],vector<char> &res){
    if (marked[v] == -1){
        return false; //�л�
    }
    if (marked[v] == 1){
        return true;
    }
    marked[v] = -1;
    // �������ڽڵ�
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
    return true; // �޻�
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
 *  �ؼ�·����ͼG�����ڽӱ�洢�ṹ������ͼG�����ڽӱ�G2����G�����������򣬼�������������緢��ʱ��ve[]
 *          ��G2�����������򣬼���������ʱ��vl[]
 *          Ȼ���ٱ���ͼ���k->j������ʱ�䣨ve[k]��������ʱ�䣨vl[j]-Ȩֵ�� ��ȣ���Ϊ�ؼ��
 */


// �������ڽӱ�
ALGraph * createReverse(ALGraph * pG){
    if (pG == NULL) {
        return pG;
    }
    // ��ʼ��
    ALGraph *G2 = (ALGraph *) malloc(sizeof(ALGraph));
    G2->n = pG->n;
    G2->e = pG->e;
    for (int i = 0; i <G2->n ; ++i) {
        G2->adjlist[i].vertex = pG->adjlist[i].vertex;
        G2->adjlist[i].firstedges = NULL;
    }
    // ����
    for (int i = 0; i <pG->n ; ++i) {
        edgesNode *p = pG->adjlist[i].firstedges;
        while (p != NULL) {
            int k = p->adjVex;
            edgesNode *newNode = (edgesNode *) malloc(sizeof(edgesNode));
            newNode->adjVex = i;
            newNode->info = p->info;
            newNode->pNext = G2->adjlist[k].firstedges;  // ͷ�巨
            G2->adjlist[k].firstedges = newNode;
            p = p->pNext;
        }
    }
    return G2;
}

// ���ڹؼ�·��
bool TopoSort_path(ALGraph *pG, int flag) {
    int indegree[pG->n]; // ����i�����
    memset(indegree, 0, sizeof(indegree));
    queue<int> q;  // ֻҪ���������� ���е�ʱ��������

    // ͳ��ÿ����������
    for (int i = 0; i < pG->n; ++i) {
        edgesNode *p = pG->adjlist[i].firstedges;
        while (p != NULL) {
            indegree[p->adjVex]++;
            p = p->pNext;
        }
    }
    if (flag == 1){ // �� ����������ʱ��
        memset(ve, 0, sizeof(ve)); // ��ʼ
    } else{ // �����������ʱ��
        memset(vl, 0, sizeof(vl));
        vl[pG->n - 1] = ve[pG->n - 1];
    }


    // ���Ϊ0 ���
    for (int i = 0; i < pG->n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    int count = 0;  // ͳ���Ѿ�����Ķ�����
    while (q.size() != 0) {
        int front = q.front(); // ����һ�����Ϊ0�ĵ�
        q.pop();
        printf("%c  ", pG->adjlist[front].vertex);
        count++;
        // ������frontָ��Ľڵ� ���-1
        edgesNode *p = pG->adjlist[front].firstedges;
        while (p != NULL) {
            int k = p->adjVex;
            indegree[k]--; // ���-1
            if (indegree[k] == 0) { // �������Ϊ0�ĵ�
                q.push(k);
            }

            if (flag == 1) {
                if (ve[front] + p->info > ve[k]){ // ���½ڵ�k�����緢��ʱ�䣬ȡ���ֵ
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
        return false;  // ʧ�� ����ͼ�� �л�·
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

// ������ȱ���
void BFS(ALGraph *pG, int i) {
    queue<int> q;
    printf("%c ", pG->adjlist[i].vertex);
    visit[i] = true;
    q.push(i);
    while (q.size() != 0) {
        int front = q.front();
        q.pop();
        edgesNode *p = pG->adjlist[front].firstedges; // ��ȡ�ڵ�adjlist[front]�ı߱�
        while (p != NULL) {      // ����©�Ƿ�����������
            if (visit[p->adjVex] == false) {
                printf("%c ", pG->adjlist[p->adjVex].vertex);
                visit[p->adjVex] = true;
                q.push(p->adjVex);
            }
            p = p->pNext;
        }
    }
}

// DFS �ݹ�
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

// DFS �ǵݹ� ջ
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
                p = pG->adjlist[p->adjVex].firstedges;  // ָ�򶥵�������Ϊp->adjVex�Ľڵ�
            } else { // p = p->next ����else���� ��ǰ�治һ��
                p = p->pNext;
            }
        }
    }
}

/***
 * BFS (��Ȩͼ)��Դ���·�� ��ֻ�ܴ�ӡ��Դ��vi��vj��·�������ܴ�ӡ��Դ�㵽vj��·��
 * ˼��: 1. dist ����ʲô����?
 *                ����visit[]���� ֻҪdist[i] != -1 �ʹ���û���ʹ�
 */

void BFS_minPath(ALGraph *pG, int i) {
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
//        printf("%c \n", pG->adjlist[front].vertex);
        edgesNode *p = pG->adjlist[front].firstedges;

        while (p != NULL) {
            int j = p->adjVex;
            if (visit[j] == false) { // vjû�б����ʹ�
                visit[j] = true;
                dist[j] = dist[front] + 1; // ���´�Դ�㵽vj��·������  Ҳ����visit[]��Ч��
                path[j] = front;  // ��¼���·��vj��ǰһ������
//                cout << "path[" << j << "]  =  " << front << endl;
                q.push(j);
            }
            p = p->pNext;
        }
    }
}


// ��ӡ ��i��j�����·��
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
    /********����weight��ʾȨֵ***********/
    int weight;
    /***************�Ͳ���Ȩֵ������֮��***************/
    char ch1, ch2;
    printf("������ͼ�Ķ�������ͱ���(�ո����)��");
    scanf("%d %d", &pG->n, &pG->e);

    printf("������ͼ�Ķ�����Ϣ��");
    for (i = 0; i < pG->n; ++i) {
        getchar();       // ��һ��ѭ���������� scanf("%d %d", &pG->n, &pG->e)�Ŀո�ͻس�;  ����ѭ������ scanf("%c", &pG->vertices[i]);�Ŀո�س�
        scanf("%c", &(pG->adjlist[i].vertex));      // ���붥����Ϣ
        pG->adjlist[i].firstedges = NULL;           // ָ���һ���߽ڵ��ָ����Ϊ null
    }

    printf("������ͼ������(����ͼ:0)��(����ͼ:1):\n");
    scanf("%d", &type);

    for (k = 0; k < pG->e; ++k) {
        getchar();
        printf("�������%d���ߵ����������Ȩֵ(�ո����)��", k + 1);

        /********************����һ������*******************/
        scanf("%c %c %d", &ch1, &ch2, &weight);                     // ch1����β  ch2����ͷ
        /**************�Ͳ���Ȩֵ������֮��******************/

        // ���������� ��Ӧ�����������λ�� i j
        for (i = 0; ch1 != pG->adjlist[i].vertex; ++i);
        for (j = 0; ch2 != pG->adjlist[j].vertex; ++j);

        // ����һ���µı߽��ҵ���Ӧ�ı���  ����ͷ�����뷨
        edgesNode *pNew = (edgesNode *) malloc(sizeof(edgesNode));
        if (!pNew) {
            printf("malloc is failed!\n");
            exit(-1);
        }
        if (type == 1) {
            // ����ͼ
            pNew->adjVex = j;    // ��Ҫд��i��
            /*********************/
            pNew->info = weight;
            /**********************/
            pNew->pNext = pG->adjlist[i].firstedges;
            pG->adjlist[i].firstedges = pNew;
        } else {
            pNew->adjVex = j;
            pNew->info = weight;
            pNew->pNext = pG->adjlist[i].firstedges;   // �׳���
            pG->adjlist[i].firstedges = pNew;
            // �ٴ���һ���ڵ� Ȼ�� i�ĳ�j j�ĳ�i
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
    printf("��ͼ���ڽӱ�Ϊ��\n");
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
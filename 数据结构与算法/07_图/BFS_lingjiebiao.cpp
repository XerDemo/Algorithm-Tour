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


void createGraph(ALGraph *pG);                     // ����ͼ
void showGraph(ALGraph *pG);                       // ��ӡ�ڽӱ�
void BFS(ALGraph *pG, int i);                      // bfs
void dfs_1(ALGraph *pG, int i);                    // DFS �ݹ�
void dfs_2(ALGraph *pG, int i);                    // DFS ջ
void BFS_minPath(ALGraph *pG, int i);              // BFS����Ȩͼ�����·����ֻ�ܴ�ӡ��Դ��vi��vj��·�������ܴ�ӡ��Դ�㵽vj��·��
void printPath(ALGraph *pG, int path[], int i, int j);

void Dijkstra(ALGraph *pG, int i);     // Dijkstra����Ȩͼ�����·�� ֻ�ܴ�ӡ��Դ��vi��vj��·�������ܴ�ӡ��Դ�㵽vj��·��
bool TopoSort(ALGraph *pG);           // ��������

int main(void) {
    ALGraph G;
    createGraph(&G);
    showGraph(&G);

    // BFS
    cout << "bfs: ";
    for (int i = 0; i < MAXSIZE; ++i) {  // ���������ʼ��
        visit[i] = false;
    }
    BFS(&G, 0);

    // DFS �ݹ�
    printf("\nDFS1: ");
    for (int i = 0; i < MAXSIZE; ++i) {  // ���������ʼ��
        visit[i] = false;
    }
    dfs_1(&G, 0);

    // DFS ջ
    printf("\nDFS2: ");
    for (int i = 0; i < MAXSIZE; ++i) {  // ���������ʼ��
        visit[i] = false;
    }
    dfs_2(&G, 0);

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
    return 0;
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
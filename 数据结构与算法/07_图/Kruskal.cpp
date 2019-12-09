#include <iostream>
#include<algorithm>
#define MAXSIZE 100
using namespace std;

typedef struct {
    int a, b;
    int w;
}Road;

Road road[MAXSIZE];
int v[MAXSIZE];  // 定义并查集数组   双亲存储结构

int getRoot(int a) { // 查找顶点编号a 的根节点
    while (a != v[a]){
        a = v[a];
    }
    return a;
}

bool cmp(Road a, Road b) { // 将边按照权值从小到大 排序
    return a.w < b.w;
}

/**
    思想：每次从图中找权值最小的边，并且与树不构成回路，将其加入树中，直到每个结点都在树中
 */

void Kruskal(Road road[], int e, int n, int &sum) {
    for (int i = 0; i < n; ++i) {  // 初始化并查集
        v[i] = i;
    }
    sort(road,road+e,cmp);
    for (int i = 0; i < e; ++i) {
        int v1 = getRoot(road[i].a);
        int v2 = getRoot(road[i].b);
        if (v1 != v2) {
            v[v1] = v2;
            sum += road[i].w;
            printf("%d -> %d w:%d\n", v1, v2, road[i].w);
        }
    }
}

int main(){
    int n , e;
    printf("顶点数 边数:\n");
    scanf("%d %d", &n, &e);
    printf("请输入边的两个顶点 及 权值\n");
    for (int i = 0; i < e; ++i) {
        cin >> road[i].a >> road[i].b >> road[i].w;
    }
    int sum = 0;
    Kruskal(road,e,n,sum);

    printf("sum = %d\n", sum);
    return 0;
}


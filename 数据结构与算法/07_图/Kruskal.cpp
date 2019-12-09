#include <iostream>
#include<algorithm>
#define MAXSIZE 100
using namespace std;

typedef struct {
    int a, b;
    int w;
}Road;

Road road[MAXSIZE];
int v[MAXSIZE];  // ���岢�鼯����   ˫�״洢�ṹ

int getRoot(int a) { // ���Ҷ�����a �ĸ��ڵ�
    while (a != v[a]){
        a = v[a];
    }
    return a;
}

bool cmp(Road a, Road b) { // ���߰���Ȩֵ��С���� ����
    return a.w < b.w;
}

/**
    ˼�룺ÿ�δ�ͼ����Ȩֵ��С�ıߣ��������������ɻ�·������������У�ֱ��ÿ����㶼������
 */

void Kruskal(Road road[], int e, int n, int &sum) {
    for (int i = 0; i < n; ++i) {  // ��ʼ�����鼯
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
    printf("������ ����:\n");
    scanf("%d %d", &n, &e);
    printf("������ߵ��������� �� Ȩֵ\n");
    for (int i = 0; i < e; ++i) {
        cin >> road[i].a >> road[i].b >> road[i].w;
    }
    int sum = 0;
    Kruskal(road,e,n,sum);

    printf("sum = %d\n", sum);
    return 0;
}


#ifndef _feed_dog_h
#define _feed_dog_h

#include <stdio.h>
#define MAXLEN 10

// 定义迷宫中点的信息
typedef struct node{
    int rowNo;                                  // 行
    int colNo;                                  // 列
    // int direction;                           // 我去掉了这个 方便统一 DFS BFS遍历下个方向  我使用了另外一种方法 
} Node;





const char ROAD = '*';                          // 路： 可以走
const char WALL = '#';                          // 墙： 不能走
char maze[MAXLEN][MAXLEN];                      // 定义迷宫
int visited[MAXLEN][MAXLEN];                    // 访问数组 1：走过  0：没有走过



int entranceX = 1, entranceY = 1;               // 入口(1,1)
int exitX = MAXLEN - 2, exitY = MAXLEN - 2;     // 出口(8,8)

// 为方便DFS深度优先搜索创建另外一种 探测方向的写法
int diretion  [4][2] = {{-1, 0}, {0,  1}, {1,  0}, {0,  -1}};  //  探测方向 依次从 上  右  下  左 四个方向顺时针探测

Node path[MAXLEN][MAXLEN]; 					    // 记录BFS 和 栈方法的路径
 
Node pathDFS[MAXLEN * MAXLEN];				   // 记录DFS遍历迷宫的最终路径
int cnt;                                       // 记录DFS遍历的部数 对应的是 pathDFE的下标 
 
#endif


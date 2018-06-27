#ifndef _feed_dog_h
#define _feed_dog_h

#include <stdio.h>
#define MAXLEN 10

// �����Թ��е����Ϣ
typedef struct node{
    int rowNo;                                  // ��
    int colNo;                                  // ��
    // int direction;                           // ��ȥ������� ����ͳһ DFS BFS�����¸�����  ��ʹ��������һ�ַ��� 
} Node;





const char ROAD = '*';                          // ·�� ������
const char WALL = '#';                          // ǽ�� ������
char maze[MAXLEN][MAXLEN];                      // �����Թ�
int visited[MAXLEN][MAXLEN];                    // �������� 1���߹�  0��û���߹�



int entranceX = 1, entranceY = 1;               // ���(1,1)
int exitX = MAXLEN - 2, exitY = MAXLEN - 2;     // ����(8,8)

// Ϊ����DFS�������������������һ�� ̽�ⷽ���д��
int diretion  [4][2] = {{-1, 0}, {0,  1}, {1,  0}, {0,  -1}};  //  ̽�ⷽ�� ���δ� ��  ��  ��  �� �ĸ�����˳ʱ��̽��

Node path[MAXLEN][MAXLEN]; 					    // ��¼BFS �� ջ������·��
 
Node pathDFS[MAXLEN * MAXLEN];				   // ��¼DFS�����Թ�������·��
int cnt;                                       // ��¼DFS�����Ĳ��� ��Ӧ���� pathDFE���±� 
 
#endif


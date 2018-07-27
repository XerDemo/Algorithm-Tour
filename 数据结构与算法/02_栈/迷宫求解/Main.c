#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"                     // ���� ��ջ
#include "cycleQueue.h"                    // ���� ѭ������


void readMaze();                           // ��ȡ�Թ��ļ��������Թ�
void printMaze();                   	   // �ڿ���̨��ӡ�Թ� ����ȡ�����Ƿ���ȷ
int inArea(int x, int y);                  // (x,y)�Ƿ����Թ���Χ��
int solverMazeDFS(int x, int y, int step); // ��(x,y)�ĵ㿪ʼ������ȱ��� step��ʾ��ӦpathDFS[step]���±��1��ʼ  
void solveMazeStack();                     // ��ջ��������Թ�
void solveMazeBFS();                       // ������ȱ�������Թ�
void clearVisited();                       // ����������������Ϊ0 δ����״̬ ��Ϊ���� DFS ջ���� BFS�� visited�����Ѿ�����ֵ�� ���ʼ��
void printPath(Node desc);				   // �ݹ���� ���� ��ӡ BFS �� ջ������·�� 
void printDFS();                           // ��ӡ DFS ���յı���·�� 

int main(void)
{
    char choice;					       // ѡ�� �˵���� 
	readMaze(maze);                        // ���ļ��ж�ȡ�Թ� �������Թ�  
    while (1)
    {
        printf("\n                    �Թ�ϵͳ                      ");
        printf("\n**************************************************");
        printf("\n*          1-------չ ʾ �� ��                   *");
        printf("\n*          2-------ջ  ��  ��                    *");
        printf("\n*          3-------�����������                  *");
        printf("\n*          4-------�����������                  *");
        printf("\n*          0-------�� �� �� ��                   *");
        printf("\n**************************************************");
        printf("\n���������:");
        scanf("%d", &choice);
        getchar();      // ���ܻس��ͻ���

        switch (choice)
        {
        	// ÿ��case ���涼��һ��  clearVisited() ��Ϊ������ȵ������������������Թ� �ᵼ��visited[][] �����в���ֵ
			case 1:
			     printMaze();				      // ���ô˷��� �ڿ���̨��ӡ������Ƿ��ȡ�ɹ�
			     printf("\n"); 
			     break;
            case 2:      
                printf("ջ����(����)��\n");
                clearVisited();                 
                solveMazeStack();
                printf("\n"); 
                break;
            case 3:
                printf("�������(DFS):\n");
                clearVisited();
                if (!solverMazeDFS(entranceX, entranceY, 1))
                {
                    printf("maze is no solve. DFS is failed.\n");
                }
                printf("\n"); 
                break;
            case 4:
                printf("�������(BFS)����:\n");
                clearVisited();
                solveMazeBFS(); 
                printf("\n"); 
                break;
            case 0:
                exit(0);          // �˳�����
            default:
                printf("\n\t\t����˵��������������룡\n");
        }
    }    
    return 0;
}

// ջ���� ����Թ�
void solveMazeStack()
{
	int isSolveStack = 0;                     // ջ���� �Ƿ����ҵ�·�� 1�����ҵ�
	int i;
    LinkStack *pS = createStack();			  // ����ջ
    
    Node entrance = {entranceX, entranceY};   // �Թ���� 
    push(pS, entrance);						  // �Թ���ڽ�ջ 
    visited[entranceX][entranceY] = 1;	      // ���õ���Ϊ1 ��ʾ���ʹ�
	 
    // ֻҪջ���� 
    while (!isEmpty(pS))
    {
        Node curPos = pop(pS);				 // curPos:��ǰ���ڵ� 
        // �����ǰ����λ�� �պ�ʱ�Թ�����   
        if (curPos.rowNo == exitX && curPos.colNo == exitY)
        {
            isSolveStack = 1;				 // �ҵ����߳��Թ��ķ��� 
            printPath(curPos);				 // ��ӡ����·�� 
            break;
        }
        // ����˳ʱ�� �� �������� ̽���Թ�  �����ҽ�����˳��̽�⵽�ĵ� ���� ̽��� newPoint 
        for (i = 0; i < 4; ++i)
        {
        	// ̽��� ���б꣺ curPos.rowNo + diretion[i][0]   �б꣺curPos.colNo + diretion[i][1]
            Node newPoint = {curPos.rowNo + diretion[i][0], curPos.colNo + diretion[i][1]};
            // ���̽���  ���Թ���Χ��   &&  ��·����   &&   �˵�û�б����ʹ� 
            if (inArea(newPoint.rowNo, newPoint.colNo) && maze[newPoint.rowNo][newPoint.colNo] == ROAD &&
                !visited[newPoint.rowNo][newPoint.colNo])
            {
                push(pS, newPoint);							     // ����̽����ջ 
                visited[newPoint.rowNo][newPoint.colNo] = 1;     // �����õ���Ϊ���ʹ�״̬ 
                path[newPoint.rowNo][newPoint.colNo] = curPos;   /* ��ӡ·���Ĺؼ� ��path[̽�����б�][̽�����б�]��¼��һ������˭ */ 
            }
        }
    }
    // ���ջ����û���ҵ��ҳ��Թ���·�� 
    if (!isSolveStack)
    {
        printf("maze is no solve. solveMazeStack is failed\n");
    }
}


// ������ȱ����� ���Թ�
void solveMazeBFS()
{
	int i;
	int isSolveBFS = 0;                         // BFS �Ƿ����ҵ�·�� 1�����ҵ�
    cycleQueue *pQ = create_queue();			// �������� 
    Node entrance = {entranceX, entranceY};     // �Թ��������     
	enQueue(pQ, entrance);                      // �� ��ڽ��� 
    visited[entranceX][entranceY] = 1;			// �����õ� ��Ϊ1 ��ʾ���ʹ�
    
	// ֻҪ���в�Ϊ�� 
    while (!isEmptyQueue(pQ))
    {
        Node curPos = outQueue(pQ);				//  curPos:��ǰ���ڵ� 
        // �����ǰ����λ�� �պ�ʱ�Թ�����   
        if (curPos.rowNo == exitX && curPos.colNo == exitY)
        {
            isSolveBFS = 1;                     // �ҵ����߳��Թ��ķ��� 
            printPath(curPos);
            break;
        }
        // ����˳ʱ�� �� �������� ̽���Թ�  �����ҽ�����˳��̽�⵽�ĵ� ���� ̽��� newPoint 
       
        for (i = 0; i < 4; ++i)
        {
        	// ̽��� ���б꣺ curPos.rowNo + diretion[i][0]   �б꣺curPos.colNo + diretion[i][1]
            Node newPoint = {curPos.rowNo + diretion[i][0], curPos.colNo + diretion[i][1]};
            // ���̽���  ���Թ���Χ��   &&  ��·����   &&   �˵�û�б����ʹ� 
            if (inArea(newPoint.rowNo, newPoint.colNo) && maze[newPoint.rowNo][newPoint.colNo] == ROAD &&
                !visited[newPoint.rowNo][newPoint.colNo])
            {
                enQueue(pQ,newPoint);                             // ����̽������ 
                visited[newPoint.rowNo][newPoint.colNo] = 1;      // �����õ���Ϊ���ʹ�״̬ 
                path[newPoint.rowNo][newPoint.colNo] = curPos;    /* ��ӡ·���Ĺؼ� ��path[̽�����б�][̽�����б�]��¼��һ������˭ */ 
            }
        }
    }
    // ���BFS����û���ҵ��ҳ��Թ���·�� 
    if (!isSolveBFS)
    {
        printf("maze is no solve. solveMazeBFS is failed\n");
    }
}


// ������ȱ��� 
int solverMazeDFS(int x, int y, int step)
{
	int i;
    // ��������Թ���
    if (!inArea(x, y))
    {
        return 0;
    }

    visited[x][y] = 1;                    // ���õ���Ϊ����״̬
    // printf("(%d, %d)\n", x, y);        // ��ӡ���õ� 

    // ����õ��ǳ���
    if (x == exitX && y == exitY)
    {
    	cnt = step;		                 // ��һ��ȫ�ֵı��� ���� step   
    	printDFS();						 // ��ӡ DFS ������·�� 
        return 1;
    }

    // ̽�����������ĸ�����  Ϊ�˷���DFS BFS ��ʹ����directDFS[4][2]���� ��ȷ����һ�����λ��
	for (i = 0; i < 4; ++i)
    {
        // �µ������ (newX, newY)
        int newX = x + diretion[i][0];
        int newY = y + diretion[i][1];
        Node newPoint = {newX, newY};

        // ��� ���Թ���Χ�� && ��·����  && �˵�û�б����ʹ�
        if (inArea(newX, newY) && maze[newX][newY] == ROAD && !visited[newX][newY])
        {
        	pathDFS[step] = newPoint;      /*  step��1��ʼ 0�����λ��  ÿ�ɹ��ı���һ���� �ٶ�ӦpathDFS[step]�м�¼�˵� �����ӡ·��  */
            // Ϊ�˷�ֹ�ҵ����ں󻹼����� ������������ void �ĳ� int  �ҵ����ں� return
            if (solverMazeDFS(newX, newY, step + 1))	 // �ݹ���� step+1 
            {
                return 1;
            }
        }
    }
    //  visited[x][y] = 0;     // �˴�����ֱ�ӻ��ݽ����ʹ�������Ϊ0 ����BFS��ջ������������������ ������ͳһ������clearVisited()��������� 
    // printf("���ݵĵ㣺(%d, %d)\n", x, y);      // ��ӡ ���ݵĵ� 
    return 0;
}

// �ݹ���� ���� ��ӡ BFS �� ջ������·��  
void printPath(Node desc)
{
	Node curPos = desc;  
	// ����õ������λ�� ��ӡ��ڲ�����  �ݹ���� 
	if (curPos.rowNo == entranceX && curPos.colNo ==entranceY)
	{
		printf("(%d,%d)", curPos.rowNo,curPos.colNo);
		return;
	}
	// ��ӡ��ǰ������� 
	printf("(%d,%d)->", curPos.rowNo,curPos.colNo);
	// ����ǰ�� ��Ϊ ��ǰ����path�����¼��ǰһ���� 
	curPos = path[curPos.rowNo][curPos.colNo];
	printPath(curPos);	 // �ݹ���� 

}

// ��ӡ DFS ���յı���·�� 
void printDFS()
{
	int i;
	printf("(%d,%d)->", entranceX , entranceY);   // ���·�� 
	// ��ӡ ������·�� �� ����֮ǰ��·�� 
	for (i = 1; i < cnt-1; ++i )							  
	{
		printf("(%d,%d)->", pathDFS[i].rowNo, pathDFS[i].colNo);
	} 
	// ��ӡ ���� ��ʵǰ���forѭ����cnt ��Ϊcnt���Ѿ����Խ����ڴ�ӡ������ Ϊ����ʾ()-> ������Ч�� �ҽ���ֿ��� 
	printf("(%d,%d)\n", exitX, exitY);
}


// �ڿ���̨��ӡ�Թ� ����ȡ�����Ƿ���ȷ
void printMaze()
{
    int i, j;
    for (i = 0; i < MAXLEN; ++i)
    {
        for (j = 0; j < MAXLEN; ++j)
        {
            printf("%c  ", maze[i][j]);
        }
        printf("\n");
    }
}

// �ж�(x,y)�Ƿ����Թ���Χ��
int inArea(int x, int y)
{
    return x >= 0 && x < MAXLEN && y >= 0 && y < MAXLEN;
}

// ����������������Ϊ0
void clearVisited()
{
    int i, j;
    for (i = 0; i < MAXLEN; ++i)
    {
        for (j = 0; j < MAXLEN; ++j)
        {
            visited[i][j] = 0;
        }
    }
}


// ��maze_10_10.txt�ж�ȡ10*10���Թ��ļ�
void readMaze()
{
	int i, j;
    FILE *fp;
    // ��ʹ�õ������·�� 
    if ((fp = fopen("./maze_10_10.txt", "rt")) == NULL)
    {
        printf("\nCannot open file strike any key exit��please modify the path!");
        getchar();
        exit(1);
    }
    // ���Թ� maze[][]��ֵ 
    for (i = 0; i < MAXLEN; ++i)
    {
        for (j = 0; j < MAXLEN; ++j)
        {
            fscanf(fp, "%c", &maze[i][j]);      /*ÿ�ζ�ȡһ������fscanf���������ո���߻��н���*/
            visited[i][j] = 0;                // ˳���ʼ��
        }
        fscanf(fp, "\n");
    }
    fclose(fp);
}




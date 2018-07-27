#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"                     // 引入 链栈
#include "cycleQueue.h"                    // 引入 循环队列


void readMaze();                           // 读取迷宫文件并创建迷宫
void printMaze();                   	   // 在控制台打印迷宫 看读取内容是否正确
int inArea(int x, int y);                  // (x,y)是否在迷宫范围内
int solverMazeDFS(int x, int y, int step); // 从(x,y)的点开始深度优先遍历 step表示对应pathDFS[step]的下标从1开始  
void solveMazeStack();                     // 用栈方法求解迷宫
void solveMazeBFS();                       // 广度优先遍历求解迷宫
void clearVisited();                       // 将访问数组重新置为0 未访问状态 因为经历 DFS 栈方法 BFS后 visited里面已经有数值了 需初始化
void printPath(Node desc);				   // 递归调用 倒序 打印 BFS 和 栈方法的路径 
void printDFS();                           // 打印 DFS 最终的遍历路径 

int main(void)
{
    char choice;					       // 选择 菜单序号 
	readMaze(maze);                        // 从文件中读取迷宫 并创建迷宫  
    while (1)
    {
        printf("\n                    迷宫系统                      ");
        printf("\n**************************************************");
        printf("\n*          1-------展 示 迷 宫                   *");
        printf("\n*          2-------栈  方  法                    *");
        printf("\n*          3-------深度优先搜索                  *");
        printf("\n*          4-------广度优先搜索                  *");
        printf("\n*          0-------退 出 程 序                   *");
        printf("\n**************************************************");
        printf("\n请输入序号:");
        scanf("%d", &choice);
        getchar();      // 接受回车和换行

        switch (choice)
        {
        	// 每个case 里面都有一个  clearVisited() 因为如果事先调用了其它方法遍历迷宫 会导致visited[][] 数组有残留值
			case 1:
			     printMaze();				      // 调用此方法 在控制台打印输出看是否读取成功
			     printf("\n"); 
			     break;
            case 2:      
                printf("栈方法(倒序)：\n");
                clearVisited();                 
                solveMazeStack();
                printf("\n"); 
                break;
            case 3:
                printf("深度优先(DFS):\n");
                clearVisited();
                if (!solverMazeDFS(entranceX, entranceY, 1))
                {
                    printf("maze is no solve. DFS is failed.\n");
                }
                printf("\n"); 
                break;
            case 4:
                printf("广度优先(BFS)倒序:\n");
                clearVisited();
                solveMazeBFS(); 
                printf("\n"); 
                break;
            case 0:
                exit(0);          // 退出程序
            default:
                printf("\n\t\t输入菜单错误，请重新输入！\n");
        }
    }    
    return 0;
}

// 栈方法 解决迷宫
void solveMazeStack()
{
	int isSolveStack = 0;                     // 栈方法 是否能找到路径 1：能找到
	int i;
    LinkStack *pS = createStack();			  // 创建栈
    
    Node entrance = {entranceX, entranceY};   // 迷宫入口 
    push(pS, entrance);						  // 迷宫入口进栈 
    visited[entranceX][entranceY] = 1;	      // 将该点置为1 表示访问过
	 
    // 只要栈不空 
    while (!isEmpty(pS))
    {
        Node curPos = pop(pS);				 // curPos:当前所在点 
        // 如果当前所在位置 刚好时迷宫出口   
        if (curPos.rowNo == exitX && curPos.colNo == exitY)
        {
            isSolveStack = 1;				 // 找到了走出迷宫的方法 
            printPath(curPos);				 // 打印最终路径 
            break;
        }
        // 按照顺时针 从 上右下左 探测迷宫  这里我将按此顺序探测到的点 叫做 探测点 newPoint 
        for (i = 0; i < 4; ++i)
        {
        	// 探测点 的行标： curPos.rowNo + diretion[i][0]   列标：curPos.colNo + diretion[i][1]
            Node newPoint = {curPos.rowNo + diretion[i][0], curPos.colNo + diretion[i][1]};
            // 如果探测点  在迷宫范围内   &&  有路可走   &&   此点没有被访问过 
            if (inArea(newPoint.rowNo, newPoint.colNo) && maze[newPoint.rowNo][newPoint.colNo] == ROAD &&
                !visited[newPoint.rowNo][newPoint.colNo])
            {
                push(pS, newPoint);							     // 将该探测点进栈 
                visited[newPoint.rowNo][newPoint.colNo] = 1;     // 并将该点置为访问过状态 
                path[newPoint.rowNo][newPoint.colNo] = curPos;   /* 打印路径的关键 用path[探测点的行标][探测点的列标]记录上一个点是谁 */ 
            }
        }
    }
    // 如果栈方法没有找到找出迷宫的路径 
    if (!isSolveStack)
    {
        printf("maze is no solve. solveMazeStack is failed\n");
    }
}


// 广度优先遍历求 解迷宫
void solveMazeBFS()
{
	int i;
	int isSolveBFS = 0;                         // BFS 是否能找到路径 1：能找到
    cycleQueue *pQ = create_queue();			// 创建队列 
    Node entrance = {entranceX, entranceY};     // 迷宫入口坐标     
	enQueue(pQ, entrance);                      // 将 入口进队 
    visited[entranceX][entranceY] = 1;			// 并将该点 置为1 表示访问过
    
	// 只要队列不为空 
    while (!isEmptyQueue(pQ))
    {
        Node curPos = outQueue(pQ);				//  curPos:当前所在点 
        // 如果当前所在位置 刚好时迷宫出口   
        if (curPos.rowNo == exitX && curPos.colNo == exitY)
        {
            isSolveBFS = 1;                     // 找到了走出迷宫的方法 
            printPath(curPos);
            break;
        }
        // 按照顺时针 从 上右下左 探测迷宫  这里我将按此顺序探测到的点 叫做 探测点 newPoint 
       
        for (i = 0; i < 4; ++i)
        {
        	// 探测点 的行标： curPos.rowNo + diretion[i][0]   列标：curPos.colNo + diretion[i][1]
            Node newPoint = {curPos.rowNo + diretion[i][0], curPos.colNo + diretion[i][1]};
            // 如果探测点  在迷宫范围内   &&  有路可走   &&   此点没有被访问过 
            if (inArea(newPoint.rowNo, newPoint.colNo) && maze[newPoint.rowNo][newPoint.colNo] == ROAD &&
                !visited[newPoint.rowNo][newPoint.colNo])
            {
                enQueue(pQ,newPoint);                             // 将该探测点进队 
                visited[newPoint.rowNo][newPoint.colNo] = 1;      // 并将该点置为访问过状态 
                path[newPoint.rowNo][newPoint.colNo] = curPos;    /* 打印路径的关键 用path[探测点的行标][探测点的列标]记录上一个点是谁 */ 
            }
        }
    }
    // 如果BFS方法没有找到找出迷宫的路径 
    if (!isSolveBFS)
    {
        printf("maze is no solve. solveMazeBFS is failed\n");
    }
}


// 深度优先遍历 
int solverMazeDFS(int x, int y, int step)
{
	int i;
    // 如果不再迷宫内
    if (!inArea(x, y))
    {
        return 0;
    }

    visited[x][y] = 1;                    // 将该点设为访问状态
    // printf("(%d, %d)\n", x, y);        // 打印出该点 

    // 如果该点是出口
    if (x == exitX && y == exitY)
    {
    	cnt = step;		                 // 用一个全局的变量 接收 step   
    	printDFS();						 // 打印 DFS 的最终路径 
        return 1;
    }

    // 探测上右下左四个方向  为了方便DFS BFS 我使用了directDFS[4][2]数组 来确定下一个点的位置
	for (i = 0; i < 4; ++i)
    {
        // 新点的坐标 (newX, newY)
        int newX = x + diretion[i][0];
        int newY = y + diretion[i][1];
        Node newPoint = {newX, newY};

        // 如果 在迷宫范围内 && 有路可走  && 此点没有被访问过
        if (inArea(newX, newY) && maze[newX][newY] == ROAD && !visited[newX][newY])
        {
        	pathDFS[step] = newPoint;      /*  step从1开始 0是入口位置  每成功的遍历一个点 再对应pathDFS[step]中记录此点 方便打印路径  */
            // 为了防止找到出口后还继续找 将方法的类型 void 改成 int  找到出口后 return
            if (solverMazeDFS(newX, newY, step + 1))	 // 递归调用 step+1 
            {
                return 1;
            }
        }
    }
    //  visited[x][y] = 0;     // 此处可以直接回溯将访问过的重置为0 但是BFS和栈方法不能向这样回溯 所以我统一设置了clearVisited()函数来清空 
    // printf("回溯的点：(%d, %d)\n", x, y);      // 打印 回溯的点 
    return 0;
}

// 递归调用 倒序 打印 BFS 和 栈方法的路径  
void printPath(Node desc)
{
	Node curPos = desc;  
	// 如果该点是入口位置 打印入口并结束  递归出口 
	if (curPos.rowNo == entranceX && curPos.colNo ==entranceY)
	{
		printf("(%d,%d)", curPos.rowNo,curPos.colNo);
		return;
	}
	// 打印当前点的坐标 
	printf("(%d,%d)->", curPos.rowNo,curPos.colNo);
	// 将当前点 置为 当前点在path里面记录的前一个点 
	curPos = path[curPos.rowNo][curPos.colNo];
	printPath(curPos);	 // 递归调用 

}

// 打印 DFS 最终的遍历路径 
void printDFS()
{
	int i;
	printf("(%d,%d)->", entranceX , entranceY);   // 入口路径 
	// 打印 不包括路口 到 出口之前的路径 
	for (i = 1; i < cnt-1; ++i )							  
	{
		printf("(%d,%d)->", pathDFS[i].rowNo, pathDFS[i].colNo);
	} 
	// 打印 出口 其实前面的for循环将cnt 改为cnt就已经可以将出口打印出来了 为了显示()-> 这样的效果 我将其分开了 
	printf("(%d,%d)\n", exitX, exitY);
}


// 在控制台打印迷宫 看读取内容是否正确
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

// 判断(x,y)是否在迷宫范围内
int inArea(int x, int y)
{
    return x >= 0 && x < MAXLEN && y >= 0 && y < MAXLEN;
}

// 将访问数组重新置为0
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


// 从maze_10_10.txt中读取10*10的迷宫文件
void readMaze()
{
	int i, j;
    FILE *fp;
    // 我使用的是相对路径 
    if ((fp = fopen("./maze_10_10.txt", "rt")) == NULL)
    {
        printf("\nCannot open file strike any key exit，please modify the path!");
        getchar();
        exit(1);
    }
    // 给迷宫 maze[][]赋值 
    for (i = 0; i < MAXLEN; ++i)
    {
        for (j = 0; j < MAXLEN; ++j)
        {
            fscanf(fp, "%c", &maze[i][j]);      /*每次读取一个数，fscanf函数遇到空格或者换行结束*/
            visited[i][j] = 0;                // 顺便初始化
        }
        fscanf(fp, "\n");
    }
    fclose(fp);
}




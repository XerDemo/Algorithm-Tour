#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10                                       // 迷宫的 行数 列数
/**缺点：不能计算所有能到终点的路线**/ 
// 定义在迷宫中的位置
typedef struct
{
    int row;                                            // 行
    int col;                                            // 列
    int direct;                                         // 方向 0：无  1：东  2：南  3：西  4：北
} path;


typedef struct stack
{
    path data[MAXSIZE * MAXSIZE];
    int top;
} seqStack;


seqStack *createSeqStack();                             // 初始化方式2：在堆中分配  (此处选用在“堆”中分配)
int emptySeqStack(seqStack *pS);                        // 判断顺序栈 是否为空
int fullSeqStack(seqStack *pS);                         // 判断顺序栈 是否满
int push(seqStack *pS, path data);                        // 入栈
path pop(seqStack *pS);                       // 出栈

void traverse(seqStack *pS);                            // 遍历
path nextPath(path * p);

int main(void)
{

    seqStack *pS = createSeqStack();
    int maze[MAXSIZE][MAXSIZE] = {             // -1：已经走过   0：此路不通   1：通
            {0},
            {0, 1, 1, 0, 1, 1, 1, 0, 1, 0},
            {0, 1, 1, 0, 1, 1, 1, 0, 1, 0},
            {0, 1, 1, 1, 1, 0, 0, 1, 1, 0},
            {0, 1, 0, 0, 0, 1, 1, 1, 0, 0},
            {0, 1, 1, 1, 0, 1, 1, 1, 0, 0},
            {0, 1, 0, 1, 1, 1, 0, 1, 1, 0},
            {0, 0, 0, 0, 0, 1, 0, 0, 1, 0},
            {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
            {0}
    };
    path begin = {1, 1, 0};                   // 迷宫入口
    path end = {8, 8, 0};                     // 迷宫出口

    path newCurrent, oldCurrent = begin;

    do
    {
        newCurrent = nextPath(&oldCurrent);
        // 当前方向可以走
        if (maze[newCurrent.row][newCurrent.col] == 1)
        {
            // 将上一步走过的点 入栈
            push(pS, oldCurrent);
            // 将上一步走过的点 置为-1  表示走过  (防止之后兜圈子)
            maze[oldCurrent.row][oldCurrent.col] = -1;
            // 如果 当前点已经到达出口  结束
            if (newCurrent.row == end.row && newCurrent.col == end.col)
            {
                break;
            }
            else
            {
                // 更新当前所在点
                oldCurrent = newCurrent;
            }
        }
        else    // 当前方向不通
        {
            // 探索剩余的几个方向  注意这里是<4 当oldCurrent.direct=3时 进入while循环 执行nextPath, direct++为4
            while (oldCurrent.direct < 4)
            {
                // 获取下一个点以及方向
                newCurrent = nextPath(&oldCurrent);
                // 如果此方向可以走
                if (maze[newCurrent.row][newCurrent.col] == 1)
                {
                    // 将上一步的点以及方向 入栈
                    push(pS, oldCurrent);
                    // 将上一步走过的点置为 -1  表示走过  防止兜圈
                    maze[oldCurrent.row][oldCurrent.col] = -1;
                    // 更新当前所在点
                    oldCurrent = newCurrent;
                    // 结束 寻找其他方向
                    break;
                }
            }   // 当前方向探索结束

            // 如果 当前所在点  已经是迷宫出口
            if (newCurrent.row == end.row && newCurrent.col == end.col)
            {
                break;
            }

            // 如果该点的东 南 西 北 都无路可走  退栈
            if (oldCurrent.direct >= 4)
            {
                // 就算该点四个方向都走不通 也要把该点-1 表示来过
                maze[oldCurrent.row][oldCurrent.col] = -1;
                // oldCurrent 赋值为 无路可走的点 的前一步所在点
                oldCurrent = pop(pS);
            }
        }
    } while (-1 != pS->top);

    if (-1 != pS->top)
    {
        traverse(pS);
    }


    return 0;
}

path nextPath(path * p)
{
    path newPath = *p;
    int flag = ++p->direct;
    printf("-----%d--\n", flag);
    newPath.direct = 0;
    switch (flag)
    {
        case 1:
            newPath.col = p->col + 1;
            break;
        case 2:
            newPath.row = p->row + 1;
            break;
        case 3:
            newPath.col = p->col - 1;
            break;
        case 4:
            newPath.row = p->row - 1;
            break;
        default: 
        printf("当前无此方向的探测！\n");
    }
    return newPath;

}
//创建堆栈 初始化 当top等于-1时 表示栈空    top等于MAXSIZE-1时 表示栈满
seqStack *createSeqStack()
{
    seqStack *pS = (seqStack *) malloc(sizeof(seqStack));
    if (!pS)
    {
        printf("malloc is failed!\n");
        exit(-1);
    }
    pS->top = -1;
    return pS;
}

int emptySeqStack(seqStack *pS)
{
    return -1 == pS->top;
}

int fullSeqStack(seqStack *pS)
{
    return MAXSIZE*MAXSIZE - 1 == pS->top;
}

//在执行push操作时，首先看栈是否满 ;若不满则top+1 ，并将新元素放入data数组的top位置
int push(seqStack *pS, path data)
{
    if (fullSeqStack(pS))
    {
        printf("seqStack is full! push is failed!\n");
        return -1;
    }
    pS->data[++pS->top] = data;
    printf("(%d %d %d)进栈\n", data.row, data.col, data.direct);
    return 1;
}

path pop(seqStack *pS)
{

    path p = pS->data[pS->top--];
    printf("(%d %d %d)出栈\n", p.row, p.col, p.direct);
    return p;
}


void traverse(seqStack *pS)
{
    int i = pS->top;
    if (emptySeqStack(pS))
    {
        printf("seqStack is empty! traverse is failed!\n");
        return;
    }
    printf("迷宫路径：\n");
    while (i != -1)
    {
        printf("( %d  %d  %d)\n ", pS->data[i].row, pS->data[i].col, pS->data[i].direct);
        i--;
    }
    printf("\n");
}

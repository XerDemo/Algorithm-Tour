#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10                                       // �Թ��� ���� ����
/**ȱ�㣺���ܼ��������ܵ��յ��·��**/ 
// �������Թ��е�λ��
typedef struct
{
    int row;                                            // ��
    int col;                                            // ��
    int direct;                                         // ���� 0����  1����  2����  3����  4����
} path;


typedef struct stack
{
    path data[MAXSIZE * MAXSIZE];
    int top;
} seqStack;


seqStack *createSeqStack();                             // ��ʼ����ʽ2���ڶ��з���  (�˴�ѡ���ڡ��ѡ��з���)
int emptySeqStack(seqStack *pS);                        // �ж�˳��ջ �Ƿ�Ϊ��
int fullSeqStack(seqStack *pS);                         // �ж�˳��ջ �Ƿ���
int push(seqStack *pS, path data);                        // ��ջ
path pop(seqStack *pS);                       // ��ջ

void traverse(seqStack *pS);                            // ����
path nextPath(path * p);

int main(void)
{

    seqStack *pS = createSeqStack();
    int maze[MAXSIZE][MAXSIZE] = {             // -1���Ѿ��߹�   0����·��ͨ   1��ͨ
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
    path begin = {1, 1, 0};                   // �Թ����
    path end = {8, 8, 0};                     // �Թ�����

    path newCurrent, oldCurrent = begin;

    do
    {
        newCurrent = nextPath(&oldCurrent);
        // ��ǰ���������
        if (maze[newCurrent.row][newCurrent.col] == 1)
        {
            // ����һ���߹��ĵ� ��ջ
            push(pS, oldCurrent);
            // ����һ���߹��ĵ� ��Ϊ-1  ��ʾ�߹�  (��ֹ֮��Ȧ��)
            maze[oldCurrent.row][oldCurrent.col] = -1;
            // ��� ��ǰ���Ѿ��������  ����
            if (newCurrent.row == end.row && newCurrent.col == end.col)
            {
                break;
            }
            else
            {
                // ���µ�ǰ���ڵ�
                oldCurrent = newCurrent;
            }
        }
        else    // ��ǰ����ͨ
        {
            // ̽��ʣ��ļ�������  ע��������<4 ��oldCurrent.direct=3ʱ ����whileѭ�� ִ��nextPath, direct++Ϊ4
            while (oldCurrent.direct < 4)
            {
                // ��ȡ��һ�����Լ�����
                newCurrent = nextPath(&oldCurrent);
                // ����˷��������
                if (maze[newCurrent.row][newCurrent.col] == 1)
                {
                    // ����һ���ĵ��Լ����� ��ջ
                    push(pS, oldCurrent);
                    // ����һ���߹��ĵ���Ϊ -1  ��ʾ�߹�  ��ֹ��Ȧ
                    maze[oldCurrent.row][oldCurrent.col] = -1;
                    // ���µ�ǰ���ڵ�
                    oldCurrent = newCurrent;
                    // ���� Ѱ����������
                    break;
                }
            }   // ��ǰ����̽������

            // ��� ��ǰ���ڵ�  �Ѿ����Թ�����
            if (newCurrent.row == end.row && newCurrent.col == end.col)
            {
                break;
            }

            // ����õ�Ķ� �� �� �� ����·����  ��ջ
            if (oldCurrent.direct >= 4)
            {
                // ����õ��ĸ������߲�ͨ ҲҪ�Ѹõ�-1 ��ʾ����
                maze[oldCurrent.row][oldCurrent.col] = -1;
                // oldCurrent ��ֵΪ ��·���ߵĵ� ��ǰһ�����ڵ�
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
        printf("��ǰ�޴˷����̽�⣡\n");
    }
    return newPath;

}
//������ջ ��ʼ�� ��top����-1ʱ ��ʾջ��    top����MAXSIZE-1ʱ ��ʾջ��
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

//��ִ��push����ʱ�����ȿ�ջ�Ƿ��� ;��������top+1 ��������Ԫ�ط���data�����topλ��
int push(seqStack *pS, path data)
{
    if (fullSeqStack(pS))
    {
        printf("seqStack is full! push is failed!\n");
        return -1;
    }
    pS->data[++pS->top] = data;
    printf("(%d %d %d)��ջ\n", data.row, data.col, data.direct);
    return 1;
}

path pop(seqStack *pS)
{

    path p = pS->data[pS->top--];
    printf("(%d %d %d)��ջ\n", p.row, p.col, p.direct);
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
    printf("�Թ�·����\n");
    while (i != -1)
    {
        printf("( %d  %d  %d)\n ", pS->data[i].row, pS->data[i].col, pS->data[i].direct);
        i--;
    }
    printf("\n");
}

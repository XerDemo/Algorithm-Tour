// 数组模拟顺序队列 实现 层次遍历
void levelOrderTraverse(BiTNode * pT)
{
    int front, rear;                // 队头  队尾
    BiTNode *arr[100];              // 数组模拟队列
    BiTNode *p = pT;
    // 只要树不空
    if (p)
    {
        front = 0;
        arr[front] = p;            // 根节点入队
        rear = 1;
    }
    // 只要队列不空
    while (front != rear)
    {
        p = arr[front];

        front++;                   // 跟结点出队
        printf("%c  ", p->data);    // 打印根节点

        if (p->pLChild)            // 如果左孩子不空 入队 rear后移
        {
            arr[rear++] = p->pLChild;
        }
        if (p->pRChild)            // 如果左孩子不空 入队 rear后移
        {
            arr[rear++] = p->pRChild;
        }
    }
}
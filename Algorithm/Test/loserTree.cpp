//#include <stdio.h>
//
//#define K 5// ?5路平衡归并
//#define MIN_KEY -32768// ?最小关键字值-∞
//
//typedef int key_type;
//typedef key_type loser_tree;
//key_type b[K];// ?b中存放所有的记录(关键字)
//int cnt = 1; // ?全局变量
//
///*-------------沿从叶子结点b[s]到根结点ls[0]的路径调整败者树---------------*/
//static void adjust(loser_tree ls[K], int s) {
//    int i, t;
//
//    t = (s + K) / 2; // ?ls[t]是b[s]的双亲结点
//    /*
//   ? ? * ? ls[4] = 5, b[4] = 15, b[ls[4]] = -∞
//   ? ? * ? ls[4] = 5, b[3] = 29, b[ls[4]] = -∞
//   ? ? * ? ls[3] = 5, b[2] = 10, b[ls[4]] = -∞
//   ? ? * ? ls[3] = 5, b[1] = 5, b[ls[4]] = -∞
//   ? ? * ? ls[2] = 5, b[0] = 17, b[ls[4]] = -∞
//   ? ? */
//    while (t > 0) {
//        if (b[s] > b[ls[t]]) // ?若双亲结点ls[t]比较小(胜者)
//        {
//            i = s; // ?i指向败者(大者)
//            s = ls[t]; // ?s指向新的胜者
//            ls[t] = i; // ?将败者(大者)放在双亲结点中
//        }
//        t = t / 2; // ?继续向上调整
//    }
//    ls[0] = s; // ?冠军结点存放最小者
//}
//
///*---------------------输出败者树----------------------*/
//static void disp_loser_tree(loser_tree ls[K]) {
//    int i;
//
//    printf("败者树:");
//    for (i = 0; i < K; i++) {
//        if (b[ls[i]] == MIN_KEY)
//            printf("%d(-∞) ", ls[i]);
//        else
//            printf("%d(%d) ", ls[i], b[ls[i]]);
//    }
//    printf("\n");
//}
//
///*---------------------创建败者树----------------------*/
//static void create_loser_tree(loser_tree ls[K]) {
//    int i;
//
//    b[K] = MIN_KEY; // ?b[K]置为最小关键字
//    for (i = 0; i < K; i++) // ?ls[0]~ls[4]设置为5
//        ls[i] = K;
//    for (i = K - 1; i >= 0; --i) // ?依次从b[K-1]=15,b[K-2]=29,...,b[0]=17出发调整败者
//    {
//        printf("第%d步,从b[%d]=%2d调整->", cnt++, i, b[i]);
//        adjust(ls, i);// 15, 29, 10, 5, 17
//        disp_loser_tree(ls);
//    }
//}
//
//int main(void) {
//    int n = 5;
//    loser_tree ls[K]; // ?定义败者树数组
//    key_type a[] = {17, 5, 10, 29, 15};
//
//    printf("%d路归并的关键字序列:", K);
//    for (int i = 0; i < n; i++) {
//        b[i] = a[i];
//        printf("%d ", b[i]);
//    }
//    printf("\n");
//    create_loser_tree(ls);
//    printf("最终结果\n");
//    disp_loser_tree(ls);
//
//    return 0;
//}

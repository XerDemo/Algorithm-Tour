//#include <stdio.h>
//
//#define K 5// ?5·ƽ��鲢
//#define MIN_KEY -32768// ?��С�ؼ���ֵ-��
//
//typedef int key_type;
//typedef key_type loser_tree;
//key_type b[K];// ?b�д�����еļ�¼(�ؼ���)
//int cnt = 1; // ?ȫ�ֱ���
//
///*-------------�ش�Ҷ�ӽ��b[s]�������ls[0]��·������������---------------*/
//static void adjust(loser_tree ls[K], int s) {
//    int i, t;
//
//    t = (s + K) / 2; // ?ls[t]��b[s]��˫�׽��
//    /*
//   ? ? * ? ls[4] = 5, b[4] = 15, b[ls[4]] = -��
//   ? ? * ? ls[4] = 5, b[3] = 29, b[ls[4]] = -��
//   ? ? * ? ls[3] = 5, b[2] = 10, b[ls[4]] = -��
//   ? ? * ? ls[3] = 5, b[1] = 5, b[ls[4]] = -��
//   ? ? * ? ls[2] = 5, b[0] = 17, b[ls[4]] = -��
//   ? ? */
//    while (t > 0) {
//        if (b[s] > b[ls[t]]) // ?��˫�׽��ls[t]�Ƚ�С(ʤ��)
//        {
//            i = s; // ?iָ�����(����)
//            s = ls[t]; // ?sָ���µ�ʤ��
//            ls[t] = i; // ?������(����)����˫�׽����
//        }
//        t = t / 2; // ?�������ϵ���
//    }
//    ls[0] = s; // ?�ھ��������С��
//}
//
///*---------------------���������----------------------*/
//static void disp_loser_tree(loser_tree ls[K]) {
//    int i;
//
//    printf("������:");
//    for (i = 0; i < K; i++) {
//        if (b[ls[i]] == MIN_KEY)
//            printf("%d(-��) ", ls[i]);
//        else
//            printf("%d(%d) ", ls[i], b[ls[i]]);
//    }
//    printf("\n");
//}
//
///*---------------------����������----------------------*/
//static void create_loser_tree(loser_tree ls[K]) {
//    int i;
//
//    b[K] = MIN_KEY; // ?b[K]��Ϊ��С�ؼ���
//    for (i = 0; i < K; i++) // ?ls[0]~ls[4]����Ϊ5
//        ls[i] = K;
//    for (i = K - 1; i >= 0; --i) // ?���δ�b[K-1]=15,b[K-2]=29,...,b[0]=17������������
//    {
//        printf("��%d��,��b[%d]=%2d����->", cnt++, i, b[i]);
//        adjust(ls, i);// 15, 29, 10, 5, 17
//        disp_loser_tree(ls);
//    }
//}
//
//int main(void) {
//    int n = 5;
//    loser_tree ls[K]; // ?�������������
//    key_type a[] = {17, 5, 10, 29, 15};
//
//    printf("%d·�鲢�Ĺؼ�������:", K);
//    for (int i = 0; i < n; i++) {
//        b[i] = a[i];
//        printf("%d ", b[i]);
//    }
//    printf("\n");
//    create_loser_tree(ls);
//    printf("���ս��\n");
//    disp_loser_tree(ls);
//
//    return 0;
//}

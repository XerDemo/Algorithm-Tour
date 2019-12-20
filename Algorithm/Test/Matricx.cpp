//#include <stdio.h>
//#include <iostream>
//using namespace std;
//#define N 6
//
//int m[N + 1][N + 1];//m是最优值
//int s[N + 1][N + 1];//s是最优值的断开点的索引
//int p[N + 1] = {30, 35, 15, 5, 10, 20, 25};
//
//void traceback(int i, int j) {
//    if (i == j) return;
//    traceback(i, s[i][j]);
//    traceback(s[i][j] + 1, j);
//    printf("A[%d][%d] and A[%d][%d]\n", i, s[i][j], s[i][j] + 1, j);
//}
//
//void dongtai() {
//    int i, j, k, r;
//    for (i = 1; i <= N; i++)//单一矩阵的最小乘次都置为0
//        m[i][i] = 0;
//    for (r = 2; r <= N; r++) {//r为连乘矩阵的个数
//            cout << "\nr: " << r;
//        for (i = 1; i <= N + 1 - r; i++) { //i表示连乘矩阵中的第一个
//            j = i + r - 1;  //j表示连乘矩阵中的最后一个
//            printf("    i: %d -> %d    j:%d\n", i, N - r + 1, j);
////            cout << " i: " << i << "  j: " << j << endl;
//            //所以，这两层循环是起始为Ai,结尾为Aj,长度为r的矩阵段Ai~Aj
//            m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
////            m[i][j] = 0x7fffffff;
//            s[i][j] = i;//记录断开点的索引
//            printf("1-> m[%d][%d] = %d \n", i, j, m[i][j]);
//
//
//            for (k = i + 1; k < j; k++) { //循环求出Ai~Aj中的最小数乘次数
//                //在第一个与最后一个之间寻找最合适的断开点,
//                //注意，应该从i开始，但是上面已经记录了i。
//                int temp = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
//                printf(" k:%d  2-> m[%d][%d] = %d \n", k, i, j, temp);
//                if (temp < m[i][j]) {
//                    m[i][j] = temp;
//                    s[i][j] = k;
//                }
//                printf("max:m[%d][%d] = %d \n", i, j, m[i][j]);
//            }
//        }
//    }
//}
//
//int main() {
//    dongtai();
//    printf("%d\n", m[1][N]);
//    traceback(1, N);
//    return 0;
//}

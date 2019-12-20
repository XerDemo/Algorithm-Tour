//#include<iostream>
//
//using namespace std;
//#define M 10
//#define N 10
//
//int main() {
//    int m = 2, n = 1;
//    int dp[M][N];
//    for (int i = 0; i <N; ++i) {
//        dp[0][i] = i + 1;
//    }
//    for (int i = 1; i < M ; ++i) {
//        for (int j = 0; j < N; ++j) {
//            if (j == 0){
//                dp[i][j] = dp[i - 1][1];
//            } else{
//                dp[i][j] = dp[i-1][dp[i][j - 1]];
//            }
//        }
//    }
//    cout << dp[2][1] << endl;
//
////    for (int i = 0; i <=m ; ++i) {
////        for (int j = 0; j <= n; ++j) {
////            cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
////        }
////    }
//    return 0;
//}
//#include <iostream>
//#include <vector>
//#include <memory.h>
//
//using namespace std;
//
//
//// cur������idx-1��Ԫ�ص�ȫ���У�������cur�м����idx��Ԫ��
//void DFS(int A[], int B[],int n, int idx, vector<int > &cur, int & min, int visit[]){
//    if (idx == n) { // �ҵ���һ��ȫ����
//        int sum = 0;
//        for (int i = 0; i < cur.size(); ++i) { // �����ʱA��B�ĵ��
//            sum = sum + cur[i] * B[i];
//        }
//        if (sum < min){
//            min = sum;  // `����
//        }
//        return;
//    }
//
//    for (int j = 0; j < n ; ++j) {
//        if (!visit[j]) {
//            if (j > 0 && A[j-1] == A[j] && !visit[j-1]) {
//                continue;
//            }
//            visit[j] = 1;
//            cur.push_back(A[j]);
//            DFS(A, B, n, idx + 1, cur, min, visit);
//            visit[j] = 0;
//            cur.pop_back();
//        }
//    }
//}
//
//int main() {
//
////    int n = 3;
////    int A[3] = {1, 3, -5};
////    int B[3] = {4, -2, -1};
////    int min = 9999999;
////    int visit[3];
////    memset(visit, 0, sizeof(visit));
////    vector<int > cur;
////    DFS(A, B, n, 0, cur, min, visit);
//////    DFS(A, B, n, 0, min, cur, visit);
////    cout << min << endl;
//    string s = "456";
//    s.pop_back();
//    cout << s << endl;
//    s = s + "789";
//    cout << s << endl;
//    return 0;
//}
//

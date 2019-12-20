//#include <stdio.h>
//#include <iostream>
//#include <stack>
//
//using namespace std;
//
//
//typedef struct {
//    int n;
//    int val;
//}Node;
//
//int p2(int x, int n){
//    stack<Node> s;
//    Node node[500];
//    int v1 = 1, v2 = 2 * x;
//    for (int i = n; i >= 2; --i) {
//        node[i].n = i;
//    }
//    s.push(node[n]);
//    while (s.size() != 0) {
//        Node top = s.top();
//        s.pop();
//
//    }
//}
//
//int p(int x, int n) {
//    if (n == 0){
//        return 1;
//    } else if (n == 1) {
//        return 2 * x;
//    } else{
//        return 2*x*p(x,n-1) - 2* (n-1)*p(x,n-2);
//    }
//}
//
//
//
//int main(){
//    cout << p(2, 3) << endl;
//    cout << p2(2, 3) << endl;
//    return 0;
//}
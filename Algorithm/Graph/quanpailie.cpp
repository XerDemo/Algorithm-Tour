//#include <stdlib.h>
//#include <iostream>
//
//using namespace std;
//
//int count = 0 ;
//void printArray(int * nums, int n){
//    for (int i = 0; i < n; ++i) {
//        cout << nums[i] << "  ";
//    }
//    cout << endl;
//}
//
//void f(int *nums, int n, int idx){  // 获取[idx,n-1]的全排列
//    if (idx == n - 1) {
//        count++;
//        printArray(nums, n);
//        return;
//    }
//
//    for (int i = idx; i < n; ++i) {
//        swap(nums[i], nums[idx]);
//        f(nums, n, idx + 1);
//        swap(nums[i], nums[idx]);  // 回溯
//    }
//}
//
//int main(void) {
//    int nums[5] = {1,2,3,4,5};
//    f(nums, 5,0);
//    return 0;
//}
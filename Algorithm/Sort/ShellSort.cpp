//#include <iostream>
//#include "SortHelp.h"
//
//using namespace std;
//
//void shellSort(int *nums, int n){
//    for (int d = n / 2; d >= 1; d = d / 2) {
//        cout << "d: " << d ;
//        for (int i = d; i < n; ++i) {
//            cout << "   "  << nums[i] ;
//            if (nums[i] < nums[i - d]) {
//                int temp = nums[i];
//                int j;
//                for (j = i; j >0 && nums[j-d] > temp; j = j - d ) {
//                    nums[j] = nums[j-d];
//                }
//                nums[j] = temp;
//            }
//        }
//        cout << endl;
//    }
//}
//
//int main(){
//    int nums[11] = {16, 25, 12, 30, 47, 11, 23, 36, 9, 18, 31};
//    printArray(nums, 11);
//    cout << "\nshell:" << endl;
//    shellSort(nums, 11);
//    printArray(nums, 11);
////    cout << "\nshell:" << endl;
//    return 0;
//}
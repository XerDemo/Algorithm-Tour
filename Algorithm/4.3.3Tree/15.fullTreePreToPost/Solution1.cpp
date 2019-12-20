//#include <iostream>
//
//using namespace std;
//
//
//void preToPost(int * pre, int preStart, int preEnd, int * post, int postStart, int postEnd){
//    if (preStart > preEnd || postStart > postEnd) {
//        return;
//    }
//    post[postEnd] = pre[preStart];
//    int mid = (preEnd - preStart) / 2;
//    // 不能先 mid = preStart + (preEnd - preStart) / 2; 这个偏移量只考虑了preStart并没有考虑到postStrat两者指向并不同步
//    preToPost(pre, preStart + 1, preStart + mid, post, postStart, postStart + mid - 1);
//    preToPost(pre, preStart + mid + 1, preEnd, post, postStart + mid, postEnd - 1);
//}
//
//int main(void) {
//    int pre[7] = {1, 2, 4, 5, 3, 6, 7};
//    int post[7];
//
//    preToPost(pre, 0, 6, post,0, 6);
//    for (int i:post) {
//        cout << i << "  ";
//    }
//    return 0;
//}
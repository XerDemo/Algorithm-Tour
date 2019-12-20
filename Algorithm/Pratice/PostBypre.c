//#include <stdio.h>
//#include <stdlib.h>
//
//#define E int
//#define MAXSIZE 7
//
////void preToPost(E * pre, int preStart, int preEnd, E * post, int postStart, int postEnd){
////    if (preStart > preEnd) {
////        return;
////    }
////    post[postEnd] = pre[preStart];
////    int mid = preStart + (preEnd - preStart) / 2;    // 此处的+preStart是左边的偏移量  但是也就是这里有问题 我算好了 pre的偏移  但是post的偏移没有算
////    printf("pre:[%d,%d]   post:[%d, %d]  mid:%d\n", preStart, preEnd, postStart, postEnd, mid);
////    preToPost(pre, preStart + 1, mid, post, postStart, mid - 1);
////    preToPost(pre,  mid + 1, preEnd, post,  mid, postEnd-1);
////}
//
//void preToPost(E * pre, int preStart, int preEnd, E * post, int postStart, int postEnd){
//    if (preStart > preEnd) {
//        return;
//    }
//    post[postEnd] = pre[preStart];
//    int mid = (preEnd - preStart) / 2;    // 此处的+preStart是左边的偏移量  但是也就是这里有问题 我算好了 pre的偏移  但是post的偏移没有算
//    printf("pre:[%d,%d]   post:[%d, %d]  mid:%d\n", preStart, preEnd, postStart, postEnd, mid);
//    // pre  [preStart + 1, mid + 左边的偏移preStart]    post [postStart, 左边的偏移 + mid - 1]
//    preToPost(pre, preStart + 1, mid + preStart, post, postStart, postStart + mid - 1);
//    preToPost(pre,  preStart + mid + 1, preEnd, post, postStart + mid, postEnd-1);
//}
//
//int main (void) {
//    E pre[MAXSIZE] = {1, 2, 4, 05.TreeHeight, 3, 6, 7};
//    E post[MAXSIZE];
//    preToPost(pre, 0, MAXSIZE - 1, post, 0, MAXSIZE - 1);
//    int i;
//    printf("post: ");
//    for (i = 0; i < MAXSIZE - 1; ++i) {
//        printf("%d ", post[i]);
//    }
//    return 0;
//}
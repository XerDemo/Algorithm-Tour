//#include "LinkedListHelper.h"
//
//int judgeBofA(LinkNode * headA, LinkNode * headB){
//    if (headA == NULL && headB != NULL) {
//        return 0;
//    }
//    if (headA == NULL || headB == NULL) {
//        return 1;
//    }
//    LinkNode *p1 = headA->next;
//    LinkNode *p2 = NULL;
//
//    while (p1 != NULL) {
//        LinkNode *temp = p1;
//        if (p1->val == headB->next->val) { // 发现headA中元素与HeadB中第一个元素相等
//            p2 = headB->next;
//            while (p2 != NULL) { // 看headB是否是HeadA的子序列
//                if (p1->val != p2->val) {
//                    break;
//                }
//                p1 = p1->next;
//                p2 = p2->next;
//            }
//            if (p2 == NULL) {
//                return 1;
//            }
//        }
//        p1 = temp->next;
//    }
//    return 0;
//}
//
//int main (void){
//    int n1 = 5;
//    int n2 = 3;
//    int data1[5] = {1, 2, 5, 7, 6};
//    int data2[3] = {2, 5,7};
//    LinkNode *headA = createLinkList_dummy(data1, n1);
//    LinkNode *headB = createLinkList_dummy(data2, n2);
//    printf("%d \n", judgeBofA(headA, headB));
////    judgeBofA(headA, headB);
//    return 0;
//}




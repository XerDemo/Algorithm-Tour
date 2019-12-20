//#include "LinkedListHelper.h"
//
//// 带有头节点 时间复杂度O(N) 空间O(1)
//LinkNode *removeMin(LinkNode *head) {
//    if (head == NULL) {
//        return head;
//    }
//    LinkNode *pre = head; // pre指向最小值节点的前驱
//    LinkNode *cur = head; // cur指向当前节点
//    int min = head->next->val; // 默认第一个节点为最小值
//    // 找最小值节点的前驱
//    while (cur !=NULL && cur->next != NULL) {
//        if (cur->next->val < min) { // 发现比当前最小值节点 还小的节点
//            min = cur->next->val; // 更新最小值
//            pre = cur; // 更新最小值前驱
//        }
//        cur = cur->next;
//    }
//    // 删除最小值节点
//    LinkNode * minNode = pre->next;
//    pre->next = minNode->next;
//    free(minNode);
//    return head;
//}

//
//int main(void) {
//    int n = 1;
//    int data[1] = {5};
//    LinkNode *head = createLinkList_dummy(data, n);
//    head = removeMin(head);
//    printLinkList(head->next);
//}

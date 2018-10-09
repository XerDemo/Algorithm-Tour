#include "ListHelper.h"

// 时间复杂度O(N)  空间复杂度O(1)
struct ListNode *swapPairs(struct ListNode *head) {
    // 建立头结点  为了统一操作 (交换第一个与第二个节点时)
    struct ListNode *dummyHead = (struct ListNode *) malloc(sizeof(struct ListNode));
    dummyHead->next = head;

    struct ListNode *pre = dummyHead;               // 交换的两个节点之前的节点
    while (pre->next != NULL && pre->next->next != NULL) {
        struct ListNode *node1 = pre->next;         // 需要交换的节点
        struct ListNode *node2 = node1->next;       // 需要交换的节点
        struct ListNode *nextNode = node2->next;    // 交换的两个节点之后的节点
        // 交换操作
        node2->next = node1;
        node1->next = nextNode;
        pre->next = node2;
        pre = node1;                                // 更新pre的位置
    }
    return dummyHead->next;
}

int main(void) {
    int list[4] = {1, 2, 3, 4};
    LinkNode *head = createList(list, 4);
    printList(swapPairs(head));
    return 0;
}
#include "ListHelper.h"


// 时间复杂度O(N)  空间复杂度O(1)
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *dummyHead = (struct ListNode *) malloc(sizeof(struct ListNode));
    dummyHead->next = head;
    struct ListNode*curNode = dummyHead->next, *pre = NULL, *nextNode = NULL;   // 注意*pre = NULL 方便将第一个有效节点的指针域置为NULL(新的表尾)
    while (curNode != NULL) {
        nextNode = curNode->next;
        curNode->next = pre;            // 反转指针
        pre = curNode;                  // 更新pre
        curNode = nextNode;             // 更新curNode
    }
    dummyHead->next = pre;              // 此时pre指向链表最后一个元素 将反转后的链表挂到头结点后面
    return dummyHead->next;
}
int main(void) {
    int list[5] = {1, 3, 3, 3, 5};
    struct ListNode *head = createList(list, 5);
    printList(reverseList(head));
    return 0;
}
#include "ListHelper.h"

// 时间复杂度O(N)   空间复杂度O(1)   带头结点
struct ListNode *removeElements(struct ListNode *head, int val) {
    struct ListNode  *dummyHead = (struct ListNode  *) malloc(sizeof(struct ListNode ));
    dummyHead->next = head;
    struct ListNode *curNode = dummyHead;
    while (curNode != NULL && curNode->next != NULL) {
        struct ListNode *nextNode = curNode->next;
        if (nextNode->val == val) {
            curNode->next = nextNode->next;
            free(nextNode);
        } else {
            curNode = curNode->next;
        }
    }
    return dummyHead->next;
}

int main(void) {
    int list[5] = {1, 3, 3, 3, 5};
    int val = 3;
    struct ListNode *head = createList(list, 5);
    printList(removeElements(head, val));
    return 0;
}
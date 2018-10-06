#include "ListHelper.h"

// 不带头结点  时间复杂度O(N)  空间复杂度O(1)
LinkNode *reverseList(struct ListNode *head) {
    LinkNode *preNode = NULL, *curNode = head, *nextNode = NULL;
    while (curNode) {
        nextNode = curNode->next;
        curNode->next = preNode;
        preNode = curNode;
        curNode = nextNode;
    }
    return preNode;
}

// 带头结点    时间复杂度O(N)  空间复杂度O(1)
LinkNode *reverseList2(struct ListNode *head) {
    LinkNode *dummy = (LinkNode *) malloc(sizeof(LinkNode));
    dummy->next = head;
    LinkNode *preNode = NULL, *curNode = head, *nextNode = NULL;
    while (curNode) {
        nextNode = curNode->next;
        curNode->next = preNode;
        preNode = curNode;
        curNode = nextNode;
    }
    dummy->next = preNode;
    return dummy->next;
}

int main(void) {
    int list[5] = {1, 2, 3, 4, 5};
    LinkNode *head = createList(list, 5);
    printList(reverseList(head));
    LinkNode *head2 = createList(list, 5);
    printList(reverseList(head2));
    return 0;
}
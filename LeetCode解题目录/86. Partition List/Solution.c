#include "ListHelper.h"

// 时间复杂度O(N)  空间复杂度O(1)
struct ListNode *partition(struct ListNode *head, int x) {
    LinkNode *dummy_1 = (LinkNode *) malloc(sizeof(LinkNode));      // 设立带头结点的链表 存放小于x的节点
    LinkNode *dummy_2 = (LinkNode *) malloc(sizeof(LinkNode));      // 设立带头结点的链表 存放大于等于x的节点
    LinkNode *curNode_1 = dummy_1, *curNode_2 = dummy_2;
    while (head) {
        if (head->val < x) {
            curNode_1->next = head;
            curNode_1 = head;
        } else {
            curNode_2->next = head;
            curNode_2 = head;
        }
        head = head->next;
    }
    curNode_2->next = NULL;           // dummy_2要接在dummy_1的后面，当然要将整体的最后一个元素的指针域置为NULL
    curNode_1->next = dummy_2->next;
    return dummy_1->next;
}

int main(void) {
    int list[6] = {1, 4, 3, 2, 5, 2};
    LinkNode *head = createList(list, 6);
    printList(head);
    LinkNode *newHead = partition(head, 3);
    printList(newHead);
}
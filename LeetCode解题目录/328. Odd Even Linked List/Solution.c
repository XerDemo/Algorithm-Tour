#include "ListHelper.h"

// 时间复杂度O(N)  空间复杂度O(1)
LinkNode * oddEvenList(struct ListNode* head) {
    LinkNode *dummy_1 = (LinkNode *) malloc(sizeof(LinkNode));     // 设立带头结点的链表 存放位置为奇数的节点
    LinkNode *dummy_2 = (LinkNode *) malloc(sizeof(LinkNode));     // 设立带头结点的链表 存放位置为偶数的节点
    LinkNode *curNode_1 = dummy_1, *curNode_2 = dummy_2;
    int count = 1;
    while (head) {
        if (0 != count % 2) {
            curNode_1->next = head;
            curNode_1 = head;
        }else{
            curNode_2->next = head;
            curNode_2 = head;
        }
        head = head->next;
        count++;
    }
    curNode_2->next = NULL;          // dummy_2要接在dummy_1的后面，当然要将整体的最后一个元素的指针域置为NULL
    curNode_1->next = dummy_2->next;
    return dummy_1->next;
}

int main(void) {
    int list[5] = {1, 2, 3, 4, 5};
    LinkNode *head = createList(list, 5);
    printList(head);
    LinkNode *newHead = oddEvenList(head);
    printList(newHead);
}
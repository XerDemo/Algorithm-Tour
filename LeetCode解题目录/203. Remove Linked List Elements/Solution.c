#include "ListHelper.h"

// 时间复杂度O(N)
struct ListNode* removeElements(struct ListNode* head, int val) {
    // 创造虚拟头结点
    struct ListNode *dummy = (struct ListNode *) malloc(sizeof(struct ListNode));
    dummy->next = head;

    struct ListNode *curNode = dummy;
    while (curNode->next) {
        if (val != curNode->next->val) {
            curNode = curNode->next;
        }else{
            curNode->next = curNode->next->next;
        }
    }
    return dummy->next;
}

int main(void){
    int list[7] = {1, 2, 6, 3, 4, 5, 6};
    int val = 6;
    LinkNode *head = createList(list, 7);
    printList(removeElements(head, val));
    return 0;
}
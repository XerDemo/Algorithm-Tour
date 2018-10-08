#include "ListHelper.h"

// 时间复杂度O(N)  空间复杂度O(1)   双指针
struct ListNode *deleteDuplicates(struct ListNode *head) {
    struct ListNode *dummy = (struct ListNode *) malloc(sizeof(struct ListNode));
    dummy->next = head;
    // fast : 最后一个重复元素的最后一个元素
    // slow : 链接重复元素之前的元素
    struct ListNode *fast = head, *slow = dummy;
    while (fast){
        while (fast->next != NULL && fast->next->val == fast->val) {
            fast = fast->next;
        }
        if (slow->next != fast) {
            slow->next = fast;
            slow = fast;
        }else{
            slow = slow->next;
        }
        fast = fast->next;
    }
    return dummy->next;
}

int main(void) {
    int list[5] = {1, 1, 2, 3, 3};
    LinkNode *head = createList(list, 5);
    printList(head);
    LinkNode *newHead = deleteDuplicates(head);
    printList(newHead);
}
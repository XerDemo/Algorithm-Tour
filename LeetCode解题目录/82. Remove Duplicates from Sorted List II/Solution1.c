//#include "ListHelper.h"
//
//// 时间复杂度O(N)  空间复杂度O(1)  双指针
//struct ListNode *deleteDuplicates(struct ListNode *head) {
//    struct ListNode *dummy = (struct ListNode *) malloc(sizeof(struct ListNode));
//    dummy->next = head;
//    // fast : 用来找到重复元素中 的最后一个元素
//    // slow : 指向重复元素之前的元素
//    struct ListNode *fast = head, *slow = dummy;
//    while (fast) {
//        while (fast->next != NULL && fast->val == fast->next->val) {
//            fast = fast->next;
//        }
//        if (slow->next != fast) {
//            slow->next = fast->next;
//            fast = slow->next;
//        } else {
//            slow = slow->next;
//            fast = fast->next;
//        }
//    }
//    return dummy->next;
//}
//
//int main(void) {
//    int list[7] = {1, 2, 3, 3, 4, 4, 5};
//    LinkNode *head = createList(list, 7);
//    printList(deleteDuplicates(head));
//    return 0;
//}
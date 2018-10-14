#include "ListHelper.h"

// 时间复杂度O(N)   空间复杂度O(N)   递归求解
// 返回从head开始去除val的链表
struct ListNode *removeElements(struct ListNode *head, int val) {
    if (NULL == head){      // 递归出口
        return NULL;
    }
    head->next = removeElements(head->next, val);
    return head->val == val ? head->next : head;
}

int main(void) {
    int list[5] = {1, 3, 3, 3, 5};
    int val = 3;
    struct ListNode *head = createList(list, 5);
    printList(removeElements(head, val));
    return 0;
}
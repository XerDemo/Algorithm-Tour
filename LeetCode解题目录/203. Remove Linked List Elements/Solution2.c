#include "ListHelper.h"

// 时间复杂度O(N)   空间复杂度O(1)   不带头结点
struct ListNode *removeElements(struct ListNode *head, int val) {
    if (head==NULL){
        return NULL;
    }
    while (head != NULL && head->val == val){           // 注意这里是while  比如 1  1 这种情况
        head = head->next;
    }
    struct ListNode *curNode = head;
    while (curNode != NULL && curNode->next != NULL) {
        struct ListNode *nextNode = curNode->next;
        if (nextNode->val == val) {
            curNode->next = nextNode->next;
            free(nextNode);
        } else {
            curNode = curNode->next;
        }
    }
    return head;
}

int main(void) {
    int list[5] = {1, 3, 3, 3, 5};
    int val = 3;
    struct ListNode *head = createList(list, 5);
    printList(removeElements(head, val));
    return 0;
}
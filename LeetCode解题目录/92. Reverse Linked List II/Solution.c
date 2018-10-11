#include "ListHelper.h"

// 时间复杂度O(N)   空间复杂度O(1)
struct ListNode *reverseBetween(struct ListNode *head, int m, int n) {
    // 假设：1 -> 2  -> 3  -> 4  -> 5    m = 1, n = 2  不设头结点 要找到1的前驱 pre只能从head开始
    // 不能等于null否则pre->next无效，无法后移  即 pre = 1 、start = 1 、 end = 2
    // 为了在m=1时统一操作就跟单链表的插入删除一样  加上头结点
    struct ListNode *dummyHead = (struct ListNode *) malloc(sizeof(struct ListNode));
    dummyHead->next = head;
    if(m == n){
        return head;
    }
    struct ListNode *pre = dummyHead, *curNode = NULL, *nextNode = NULL;
    int i = 0;
    while (pre != NULL && i < m - 1) {                // 找到pre的位置
        pre = pre->next;
        i++;
    }
    if (NULL == pre) {
        return NULL;
    }
    curNode = pre->next;                              // 确定curNode的位置
    for (i = 0; i < n - m && curNode != NULL; ++i) {  // 开始reverse
        printf("aaaa\n");
        nextNode = curNode->next;
        curNode->next = nextNode->next;
        nextNode->next = pre->next;                   // 注意这里不要写成了nextNode>next = curNode
        pre->next = nextNode;
    }
    return dummyHead->next;
}

int main(void) {
    int list[5] = {1, 2, 3, 4, 5};
    struct ListNode *head = createList(list, 5);
    printList(reverseBetween(head, 2, 4));
    return 0;
}
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (!list1 && !list2) return NULL;
    struct ListNode* head = NULL, **current = &head, **node = NULL;
    while (list1 && list2) {
        node = list1 -> val <= list2 -> val ? &list1 : &list2;
        *current = *node;
        *node = (*node) -> next;
        current = &(*current) -> next;
    }
    *current = !list1 ? list2 : list1;
    return head;
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (!listsSize) return NULL;
    else if (listsSize == 1) return lists[0];
    int mid = listsSize >> 1;
    return mergeTwoLists(mergeKLists(lists, mid), mergeKLists(lists + mid, listsSize - mid));
}
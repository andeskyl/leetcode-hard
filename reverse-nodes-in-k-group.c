struct ListNode* reverseSublist(struct ListNode* head, int k) {
    struct ListNode* newHead, *nextNode;
    for (newHead = NULL, nextNode = NULL; k > 0; k--) {
        nextNode = head -> next;
        head -> next = newHead;
        newHead = head;
        head = nextNode;
    }
    return newHead;
}
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (k == 1) return head;
    struct ListNode* newHead = NULL, *lastSublistEnd = NULL, *sublistHead = head, *newSublistHead = NULL;
    for (int count = k - 1; head != NULL; count--) {
        head = head -> next;
        if (!count) {
            newSublistHead = reverseSublist(sublistHead, k);
            if (!newHead) newHead = newSublistHead;
            if (lastSublistEnd) lastSublistEnd -> next = newSublistHead;
            lastSublistEnd = sublistHead;
            sublistHead = head;
            count = k;
        }
    }
    lastSublistEnd -> next = sublistHead;
    return newHead;
}
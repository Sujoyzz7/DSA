class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) {
            return head;
        }

        ListNode dummy(0);
        dummy.next = head;

        ListNode* groupPrev = &dummy;

        while (true) {
            // Find the kth node
            ListNode* kth = groupPrev;

            for (int i = 0; i < k; i++) {
                kth = kth->next;

                if (kth == nullptr) {
                    return dummy.next;
                }
            }

            ListNode* groupNext = kth->next;

            // Reverse the group
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            while (curr != groupNext) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            // Connect reversed group
            ListNode* oldGroupStart = groupPrev->next;
            groupPrev->next = kth;

            // Move to next group
            groupPrev = oldGroupStart;
        }
    }
};
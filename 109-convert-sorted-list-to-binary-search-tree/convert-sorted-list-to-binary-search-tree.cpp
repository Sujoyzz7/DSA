class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (prev) prev->next = nullptr;

        TreeNode* root = new TreeNode(slow->val);

        if (slow != head) {
            root->left = sortedListToBST(head);
        }

        root->right = sortedListToBST(slow->next);

        return root;
    }
};
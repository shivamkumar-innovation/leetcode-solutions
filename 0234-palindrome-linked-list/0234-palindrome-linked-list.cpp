class Solution {
public:
    bool isPalindrome(ListNode* h) {
        ListNode* slow = h;
        ListNode* fast = h;

        // Find middle
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast != nullptr) {
            slow = slow->next;
        }

        ListNode* prev = nullptr;

        while (slow != nullptr) {
            ListNode* x = slow->next;
            slow->next = prev;
            prev = slow;
            slow = x;
        }

        while (prev != nullptr) {
            if (h->val != prev->val) {
                return false;
            }

            h = h->next;
            prev = prev->next;
        }

        return true;
    }
};
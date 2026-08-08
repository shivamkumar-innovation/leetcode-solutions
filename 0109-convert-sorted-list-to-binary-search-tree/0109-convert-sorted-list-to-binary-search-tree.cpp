/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(ListNode* h) {
        if (!h)
            return NULL;

        if (!h->next)
            return new TreeNode(h->val);

        ListNode *s = h, *f = h, *p = NULL;

        while (f && f->next) {
            p = s;
            s = s->next;
            f = f->next->next;
        }

        p->next = NULL;

        TreeNode* a = new TreeNode(s->val);

        a->left = solve(h);
        a->right = solve(s->next);

        return a;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        return solve(head);
    }
};
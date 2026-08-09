/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    void f(TreeNode* r, int c, int t) {
        if (t) {
            if (r->left) {
                f(r->left, c + 1, 0);
                ans = max(ans, c + 1);
            }
            if (r->right) {
                f(r->right, 1, 1);
            }
        } else {
            if (r->left) {
                f(r->left, 1, 0);
            }
            if (r->right) {
                f(r->right, c + 1, 1);
                ans = max(ans, c + 1);
            }
        }
    }
    int longestZigZag(TreeNode* r) {
        f(r, 0, 1);
        //f(r, 0, 0);
        return ans;
    }
};
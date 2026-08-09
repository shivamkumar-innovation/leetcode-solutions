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
int ans = INT_MAX;
    TreeNode* prev = nullptr;

    void f(TreeNode* root) {
        if (!root) return;

        f(root->left);

        if (prev) {
            ans = min(ans, root->val - prev->val);
        }
        prev = root;

        f(root->right);
    }
    int minDiffInBST(TreeNode* root) {
         f(root);
        return ans;
    }
};
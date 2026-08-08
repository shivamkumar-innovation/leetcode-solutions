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
    int ans = 0;

    void f(TreeNode* root, long long t) {
        if (!root)
            return;

        t -= root->val;

        if (t == 0)
            ans++;

        f(root->left, t);
        f(root->right, t);
        t += root->val;
    }

    int pathSum(TreeNode* root, int t) {
        if (!root)
            return 0;

        f(root, t);

        pathSum(root->left, t);
        pathSum(root->right, t);

        return ans;
    }
};
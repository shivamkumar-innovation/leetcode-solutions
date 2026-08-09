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

    int getMinimumDifference(TreeNode* root) {
        f(root);
        return ans;
    }
};
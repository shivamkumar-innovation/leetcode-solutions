class Solution {
public:
    int ans = 0;

    int f(TreeNode* root) {
        if (!root)
            return 0;

        int l = f(root->left);
        int r = f(root->right);

        int u = 0;
        int v = 0;

        if (root->left && root->val == root->left->val)
            u = l + 1;

        if (root->right && root->val == root->right->val)
            v = r + 1;

        ans = max(ans, u + v);

        return max(u, v);
    }

    int longestUnivaluePath(TreeNode* r) {
        if (!r)
            return 0;

        f(r);
        return ans;
    }
};
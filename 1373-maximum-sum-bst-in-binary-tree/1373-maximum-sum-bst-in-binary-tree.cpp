class Info {
    public:
        int mn, mx, sz;

        Info(int mn, int mx, int sz) {
            this->mn = mn;
            this->mx = mx;
            this->sz = sz;
        }
    };
class Solution {
public:
int ans =0;
    Info f(TreeNode *root) {
        if (!root)
            return Info(INT_MAX, INT_MIN, 0);

        Info l = f(root->left);
        Info r = f(root->right);

        if (l.mx < root->val && root->val < r.mn) {
            ans=max(ans,l.sz + r.sz + root->val);
            return Info(
                min(root->val, l.mn),
                max(root->val, r.mx),
                l.sz + r.sz + root->val
            );
        }

        return Info(
            INT_MIN,
            INT_MAX,
            0
        );
    }

    int maxSumBST(TreeNode* root) {
        Info x = f(root);
        return ans;
    }
};
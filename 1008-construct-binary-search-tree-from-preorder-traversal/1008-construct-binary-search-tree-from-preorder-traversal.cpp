class Solution {
public:
    int i = 0;

    TreeNode* f(vector<int>& p, long long low, long long high) {
        if (i == p.size() || p[i] < low || p[i] > high)
            return NULL;

        TreeNode* r = new TreeNode(p[i++]);

        r->left = f(p, low, r->val);
        r->right = f(p, r->val, high);

        return r;
    }

    TreeNode* bstFromPreorder(vector<int>& p) {
        return f(p, LLONG_MIN, LLONG_MAX);
    }
};
class Info {
public:
    int i;
    int j;

    Info(int i, int j) {
        this->i = i;
        this->j = j;
    }
};

class Solution {
public:
    int ans = 0;

    Info f(TreeNode* r) {
        if (!r)
            return Info(INT_MAX, INT_MIN);

        Info l = f(r->left);
        Info ri = f(r->right);

        if (l.i != INT_MAX) {
            ans = max(ans, abs(r->val - l.i));
            ans = max(ans, abs(r->val - l.j));
        }

        if (ri.i != INT_MAX) {
            ans = max(ans, abs(r->val - ri.i));
            ans = max(ans, abs(r->val - ri.j));
        }

        return Info(
            min({r->val, l.i, ri.i}),
            max({r->val, l.j, ri.j})
        );
    }

    int maxAncestorDiff(TreeNode* r) {
        f(r);
        return ans;
    }
};
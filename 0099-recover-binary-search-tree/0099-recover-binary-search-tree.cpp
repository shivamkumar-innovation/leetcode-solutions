class Solution {
public:
    TreeNode *f = NULL, *m = NULL, *l = NULL, *p = NULL;

    void h(TreeNode* root) {
        if (!root)
            return;

        h(root->left);

        if (p && p->val > root->val) {
            if (!f) {
                f = p;
                m = root;
            } else {
                l = root;
            }
        }

        p = root;

        h(root->right);
    }

    void recoverTree(TreeNode* root) {
        h(root);

        if (f && l)
            swap(f->val, l->val);
        else
            swap(f->val, m->val);
    }
};
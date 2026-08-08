class BSTIterator {
    stack<TreeNode*> st;
    bool rev;

public:
    BSTIterator(TreeNode* root, bool rev) {
        this->rev = rev;

        while (root) {
            st.push(root);
            if (rev)
                root = root->right;
            else
                root = root->left;
        }
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();

        TreeNode* cur;
        if (rev)
            cur = node->left;
        else
            cur = node->right;

        while (cur) {
            st.push(cur);
            if (rev)
                cur = cur->right;
            else
                cur = cur->left;
        }

        return node->val;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int i = l.next();
        int j = r.next();

        while (i < j) {
            if (i + j == k)
                return true;
            else if (i + j < k)
                i = l.next();
            else
                j = r.next();
        }

        return false;
    }
};
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

    TreeNode* build(vector<int>& p, vector<int>& po, int i, int j, int& c) {
        if (i > j)
            return NULL;

        TreeNode* root = new TreeNode(p[c++]);

        if (i == j)
            return root;

        int k = i;

        while (po[k] != p[c])
            k++;

        root->left = build(p, po, i, k, c);
        root->right = build(p, po, k + 1, j - 1, c);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& p, vector<int>& po) {
        int c = 0;
        return build(p, po, 0, po.size() - 1, c);
    }
};
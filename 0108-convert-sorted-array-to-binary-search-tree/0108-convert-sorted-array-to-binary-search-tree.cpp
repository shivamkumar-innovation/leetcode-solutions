/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* f(vector<int>&v, int i, int j) {
        if (i > j) {
            return nullptr;
        }
        int m = i+(j- i) / 2;
        TreeNode* r = new TreeNode(v[m]);
        r->left = f(v, i, m - 1);
        r->right = f(v, m + 1, j);
        return r;
    }
    TreeNode* sortedArrayToBST(vector<int>& v) { return f(v, 0, v.size() - 1); }
};
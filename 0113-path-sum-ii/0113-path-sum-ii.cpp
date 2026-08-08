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
    vector<vector<int>> ans;
    void f(TreeNode* root, int t, vector<int>&v) {
        v.push_back(root->val);
        t = t - root->val;
        if (t == 0 && !root->left && !root->right) {
            ans.push_back(v);
            v.pop_back();
            t += root->val;
            return;
        }
        if (!root->left && !root->right) {
            v.pop_back();
            t += root->val;
            return;
        }
        if(root->left)
        f(root->left, t, v);
        if(root->right)
        f(root->right, t, v);
        v.pop_back();
        t += root->val;
    }
    vector<vector<int>> pathSum(TreeNode* root, int t) {
        if (!root) return ans;
        vector<int>v;
        f(root,t,v);
        return ans;
    }
};
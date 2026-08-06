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
int ans=INT_MIN;
int f(TreeNode* &r){
    if(!r){
        return 0;
    }
    int l=max(0,f(r->left));
    int ri=max(0,f(r->right));
    ans=max(ans,l+ri+r->val);
    return r->val+max(l,ri);
}
    int maxPathSum(TreeNode* root) {
        f(root);
        return ans;
    }
};
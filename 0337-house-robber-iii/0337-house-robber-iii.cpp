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
pair<int,int> f(TreeNode* r ){
    if(!r) return {0,0};
    auto l=f(r->left);
    auto ro=f(r->right);
    int t=r->val+l.second+ro.second;
    int n=max(l.second,l.first)+max(ro.second,ro.first);
    return {t,n};

}
    int rob(TreeNode* r) {
        auto x=f(r);
        return max(x.first,x.second);
    }
};
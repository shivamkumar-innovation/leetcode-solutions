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
int ans=0;
    void f(TreeNode* r, int t) {
        if(!r){
            return ;
        }
        if (t <= r->val) {
            ans++;
        }
        f(r->left,max(t,r->val));
        f(r->right,max(t,r->val));
    }
        int goodNodes(TreeNode * root) {
            f(root,root->val);
            return ans;
        }
    };
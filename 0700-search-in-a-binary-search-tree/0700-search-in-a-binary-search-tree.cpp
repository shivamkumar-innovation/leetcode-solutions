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
    TreeNode* searchBST(TreeNode* r, int v) {

        if (r == nullptr) {
            return nullptr;
        }
        if (r->val==v){
            return r;
        }
        if(r->val>v){
            return searchBST(r->left,v);
        }
        return searchBST(r->right,v);
    }
};
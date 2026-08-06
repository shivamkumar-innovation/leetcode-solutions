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
int ans=0;
void f(TreeNode* r, string &s){
    
     s += (r->val + '0');
    if(!r->left && !r->right){
        int z = stoi(s);
        ans+=z;
        s.pop_back();
        return;
    }
    if(r->left){
        f(r->left,s);
    }
    if(r->right){
        f(r->right,s);
    }
     s.pop_back();
}
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) return 0;
        string s = "";
        f(root, s);
        return ans;
    }
};
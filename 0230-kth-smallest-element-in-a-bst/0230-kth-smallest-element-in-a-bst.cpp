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
     int k;
     void tree(TreeNode* root){
        if(root==nullptr){
            return ;
        }
        
        tree(root->left);
        k--;
        if(k==0){
            ans=root->val;
            return ;
        }
        if(k>0)
        tree(root->right);
       

     }
    int kthSmallest(TreeNode* root, int K) {
        k=K;
        if(k==1 && !root->left){
            return root->val;
        }
        tree(root);
        return ans;
    }
};
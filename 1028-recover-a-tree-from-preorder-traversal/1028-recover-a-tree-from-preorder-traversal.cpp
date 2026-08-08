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
int b=0;
TreeNode* f(string &s,int& i,int c){
    if(i>=s.size()){
        return nullptr;
    }
    int k=0;
    
    
    while(i<s.size() && s[i]!='-'){
         k=k*10+(s[i]-'0');
        i++;
    }
    
    TreeNode* root=new TreeNode(k);
    b=0;
    while(i<s.size() && s[i]=='-'){
        b++;
        i++;
    }
    if(b<=c){
        return root;
    }
    root->left=f(s,i,b);
    if(root->left && b==c+1)
    root->right=f(s,i,c+1);
    return root;
}
    TreeNode* recoverFromPreorder(string s) {
        int i=0;
        return f(s,i,0);
    }
};
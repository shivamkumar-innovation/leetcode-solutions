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
int g(TreeNode* r){
    if(r==nullptr) return 0;
    return 1 + g(r->left);
}

int h(TreeNode* r){
    if(r==nullptr) return 0;
    return 1 + h(r->right);
}

int f(TreeNode* r){
    if(r==nullptr) return 0;

    int x = g(r);
    int y = h(r);

    if(x==y)
        return pow(2, x) - 1;

    return 1 + f(r->left) + f(r->right);
}

int countNodes(TreeNode* root) {
    return f(root);
    }
};
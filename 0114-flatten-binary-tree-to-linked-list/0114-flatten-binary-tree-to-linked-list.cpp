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
//   TreeNode* l=nullptr;
//   TreeNode* h=nullptr;
// void tree(TreeNode* root){
//   if(root==nullptr){
//             return ;
//         }
//         TreeNode* node = new TreeNode(root->val);
//         node->right = nullptr;
//         node->left = nullptr;
//         if(l==nullptr){
//         l=node;
//         h=l;
// }
//         else{
//             l->right=node;
//             l=node;
//         }
//         //l=node->next;
//         flatten(root->left);
//         flatten(root->right);
// }
void h(TreeNode* left, TreeNode* right) {
        while (left->right) {
            left = left->right;
        }
        left->right = right;
    }


    void flatten(TreeNode* root) {
        if(root==nullptr) return;
        
        flatten(root->left);
        flatten(root->right);

        if (root->left) {

            if (root->right) {
                h(root->left, root->right);
            }

            swap(root->right,root->left);
            root->left = nullptr;
        }
    //    // root=h;
    //    flatten(root->left);
    //    flatten(root->right);
    //    TreeNode* node=root->right;
    //    root->right=root->left;
    //    root->left=nullptr;
    //    TreeNode* curr=root;
    //    //if(root)
    //    while(curr->right!=nullptr)
    //    curr=curr->right;
    //    curr->right=node;
       
    }
};
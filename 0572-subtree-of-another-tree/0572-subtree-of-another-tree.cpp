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
bool sameTree(TreeNode* root1, TreeNode* root2) {
    queue<pair<TreeNode*, TreeNode*>> q;

    q.push({root1, root2});

    while (!q.empty()) {
        TreeNode* r1 = q.front().first;
        TreeNode* r2 = q.front().second;
        q.pop();

        if (r1 == NULL && r2 == NULL)
            continue;

        if (r1 == NULL || r2 == NULL)
            return false;

        if (r1->val != r2->val)
            return false;

        q.push({r1->left, r2->left});
        q.push({r1->right, r2->right});
    }

    return true;
}
    bool isSubtree(TreeNode* r, TreeNode* s) {
        queue<TreeNode*> q;
       q.push(r);

    while (!q.empty()) {
        TreeNode* r = q.front();
        q.pop();

        if (r->val == s->val){
            if(sameTree(r,s))
            return true;
        }

        if (r->left)
            q.push(r->left);

        if (r->right)
            q.push(r->right);
    }
    return false;
    }
};
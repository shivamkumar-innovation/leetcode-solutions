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
    vector<vector<int>> ans;

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        if (root == nullptr)
            return ans;

        unordered_map<int, vector<int>> m;
        queue<pair<TreeNode*, int>> q;

        q.push({root, 0});

        int left = 0, right = 0;

        while (!q.empty()) {

            int sz = q.size();

            unordered_map<int, vector<int>> temp;

            while (sz--) {

                auto [node, hd] = q.front();
                q.pop();

                temp[hd].push_back(node->val);

                left = min(left, hd);
                right = max(right, hd);

                if (node->left)
                    q.push({node->left, hd - 1});

                if (node->right)
                    q.push({node->right, hd + 1});
            }

            for (auto &it : temp) {
                sort(it.second.begin(), it.second.end());

                for (int x : it.second)
                    m[it.first].push_back(x);
            }
        }

        for (int i = left; i <= right; i++)
            ans.push_back(m[i]);

        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> ans(n, vector<int>(m, -1));
        queue<pair<int,int>> q;

        int i = 0;
        while (i < n) {
            int j = 0;
            while (j < m) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
                j++;
            }
            i++;
        }

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (y + 1 < m && ans[x][y + 1] == -1) {
                ans[x][y + 1] = ans[x][y] + 1;
                q.push({x, y + 1});
            }

            if (y - 1 >= 0 && ans[x][y - 1] == -1) {
                ans[x][y - 1] = ans[x][y] + 1;
                q.push({x, y - 1});
            }

            if (x + 1 < n && ans[x + 1][y] == -1) {
                ans[x + 1][y] = ans[x][y] + 1;
                q.push({x + 1, y});
            }

            if (x - 1 >= 0 && ans[x - 1][y] == -1) {
                ans[x - 1][y] = ans[x][y] + 1;
                q.push({x - 1, y});
            }
        }

        return ans;
    }
};
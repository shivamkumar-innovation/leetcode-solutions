class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& a) {
        int n = a.size();
        int m = n;

        if (a[0][0] == 1 || a[n - 1][n - 1] == 1)
            return -1;

        vector<vector<int>> d(n, vector<int>(n, INT_MAX));

        queue<vector<int>> q;
        q.push({0, 0});
        d[0][0] = 1;

        while (!q.empty()) {
            auto t = q.front();
            q.pop();

            int i = t[0];
            int j = t[1];
            int k = d[i][j];

            if (i == n - 1 && j == n - 1)
                return d[i][j];

            if (j + 1 < m) {
                if (a[i][j + 1] == 0 && d[i][j + 1] > k + 1) {
                    d[i][j + 1] = k + 1;
                    q.push({i, j + 1});
                }
            }

            if (j - 1 >= 0) {
                if (a[i][j - 1] == 0 && d[i][j - 1] > k + 1) {
                    d[i][j - 1] = k + 1;
                    q.push({i, j - 1});
                }
            }

            if (i + 1 < n) {
                if (a[i + 1][j] == 0 && d[i + 1][j] > k + 1) {
                    d[i + 1][j] = k + 1;
                    q.push({i + 1, j});
                }
            }

            if (i - 1 >= 0) {
                if (a[i - 1][j] == 0 && d[i - 1][j] > k + 1) {
                    d[i - 1][j] = k + 1;
                    q.push({i - 1, j});
                }
            }

            if (i - 1 >= 0 && j - 1 >= 0) {
                if (a[i - 1][j - 1] == 0 && d[i - 1][j - 1] > k + 1) {
                    d[i - 1][j - 1] = k + 1;
                    q.push({i - 1, j - 1});
                }
            }

            if (i - 1 >= 0 && j + 1 < m) {
                if (a[i - 1][j + 1] == 0 && d[i - 1][j + 1] > k + 1) {
                    d[i - 1][j + 1] = k + 1;
                    q.push({i - 1, j + 1});
                }
            }

            if (i + 1 < n && j - 1 >= 0) {
                if (a[i + 1][j - 1] == 0 && d[i + 1][j - 1] > k + 1) {
                    d[i + 1][j - 1] = k + 1;
                    q.push({i + 1, j - 1});
                }
            }

            if (i + 1 < n && j + 1 < m) {
                if (a[i + 1][j + 1] == 0 && d[i + 1][j + 1] > k + 1) {
                    d[i + 1][j + 1] = k + 1;
                    q.push({i + 1, j + 1});
                }
            }
        }

        return -1;
    }
};
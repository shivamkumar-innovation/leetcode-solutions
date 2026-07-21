class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();

        vector<vector<int>> d(n, vector<int>(m, -1));

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        q.push({0, 0, 0});
        d[0][0] = 0;
        int s = INT_MAX;

        while (!q.empty()) {
            auto t = q.top();
            q.pop();

            int l = t[0];
            int i = t[1];
            int j = t[2];

            if (l > d[i][j]) continue;

            if (i == n - 1 && j == m - 1)
                return d[i][j];

            if (j + 1 < m) {
                int nd = max(abs(a[i][j] - a[i][j + 1]), l);
                if (d[i][j + 1] == -1 || nd < d[i][j + 1]) {
                    d[i][j + 1] = nd;
                    q.push({nd, i, j + 1});
                }
            }

            if (j - 1 >= 0) {
                int nd = max(abs(a[i][j] - a[i][j - 1]), l);
                if (d[i][j - 1] == -1 || nd < d[i][j - 1]) {
                    d[i][j - 1] = nd;
                    q.push({nd, i, j - 1});
                }
            }

            if (i + 1 < n) {
                int nd = max(abs(a[i][j] - a[i + 1][j]), l);
                if (d[i + 1][j] == -1 || nd < d[i + 1][j]) {
                    d[i + 1][j] = nd;
                    q.push({nd, i + 1, j});
                }
            }

            if (i - 1 >= 0) {
                int nd = max(abs(a[i][j] - a[i - 1][j]), l);
                if (d[i - 1][j] == -1 || nd < d[i - 1][j]) {
                    d[i - 1][j] = nd;
                    q.push({nd, i - 1, j});
                }
            }
        }

        return s;
    }
};
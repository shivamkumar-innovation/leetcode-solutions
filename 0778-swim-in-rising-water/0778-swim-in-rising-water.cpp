class Solution {
public:
    int swimInWater(vector<vector<int>>& a) {

        int n = a.size();

        vector<vector<int>> d(n, vector<int>(n, INT_MAX));

        priority_queue<vector<int>, vector<vector<int>>,
                       greater<vector<int>>> p;

        d[0][0] = a[0][0];
        p.push({a[0][0], 0, 0});

        while (!p.empty()) {

            auto b = p.top();
            p.pop();

            int s = b[0];
            int i = b[1];
            int j = b[2];

            if (s > d[i][j])
                continue;

            if (i == n - 1 && j == n - 1)
                return s;

            if (j + 1 < n) {

                int x = max(s, a[i][j + 1]);

                if (x < d[i][j + 1]) {
                    d[i][j + 1] = x;
                    p.push({x, i, j + 1});
                }
            }

            if (j - 1 >= 0) {

                int x = max(s, a[i][j - 1]);

                if (x < d[i][j - 1]) {
                    d[i][j - 1] = x;
                    p.push({x, i, j - 1});
                }
            }

            if (i + 1 < n) {

                int x = max(s, a[i + 1][j]);

                if (x < d[i + 1][j]) {
                    d[i + 1][j] = x;
                    p.push({x, i + 1, j});
                }
            }

            if (i - 1 >= 0) {

                int x = max(s, a[i - 1][j]);

                if (x < d[i - 1][j]) {
                    d[i - 1][j] = x;
                    p.push({x, i - 1, j});
                }
            }
        }

        return -1;
    }
};
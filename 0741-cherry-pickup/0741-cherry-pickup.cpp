class Solution {
public:
    int f(vector<vector<int>>& a, vector<vector<vector<vector<int>>>>& d, int m,
          int n, int i, int j) {

        if (m < 0 || n < 0 || i < 0 || j < 0)
            return -1e8;

        if (a[m][n] == -1 || a[i][j] == -1)
            return -1e8;
        if (m == i && n == j && m == 0 && n == 0) {
            return a[m][n];
        }

        if (d[m][n][i][j] != -1)
            return d[m][n][i][j];

        int s = 0;
        int x = a[m][n];
        int y = a[i][j];
        if (m == i && n == j) {
            s = a[m][n];
            a[m][n] = 0;
        } else {
            s = a[m][n] + a[i][j];
            a[m][n] = 0;
            a[i][j] = 0;
        }

        int l = f(a, d, m - 1, n, i - 1, j);
        int r = f(a, d, m - 1, n, i, j - 1);
        int p = f(a, d, m, n - 1, i - 1, j);
        int q = f(a, d, m, n - 1, i, j - 1);

        a[m][n] = x;
        a[i][j] = y;

        return d[m][n][i][j] = s + max({l, r, p, q});
    }

    int cherryPickup(vector<vector<int>>& a) {
        int m = a.size();
        int n = a[0].size();

        vector<vector<vector<vector<int>>>> d(
            m, vector<vector<vector<int>>>(
                   n, vector<vector<int>>(m, vector<int>(n, -1))));

        int ans = f(a, d, m - 1, n - 1, m - 1, n - 1);

        return max(0, ans);
    }
};
class Solution {
public:
    int f(vector<vector<int>>& a, vector<vector<int>>& d, int m, int n) {

        if (m >= a.size() || n >= a[0].size())
            return INT_MAX;

        if (m == a.size() - 1 && n == a[0].size() - 1)
            return max(1, 1 - a[m][n]);

        if (d[m][n] != -1)
            return d[m][n];

        int l = f(a, d, m + 1, n);
        int r = f(a, d, m, n + 1);

        int need = min(l, r);

        if (need == INT_MAX)
            return d[m][n] = INT_MAX;

        need -= a[m][n];

        return d[m][n] = max(1, need);
    }

    int calculateMinimumHP(vector<vector<int>>& a) {

        int m = a.size();
        int n = a[0].size();

        vector<vector<int>> d(m, vector<int>(n, -1));

        return f(a, d, 0, 0);
    }
};
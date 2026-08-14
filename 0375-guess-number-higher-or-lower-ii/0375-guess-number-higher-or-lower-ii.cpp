class Solution {
public:
    int f(vector<vector<int>>& d, int i, int j) {
        if (i >= j) return 0;

        if (d[i][j] != -1) return d[i][j];

        int ans = INT_MAX;

        for (int x = i; x <= j; x++) {
            int cost = x + max(f(d, i, x - 1),
                               f(d, x + 1, j));
            ans = min(ans, cost);
        }

        return d[i][j] = ans;
    }

    int getMoneyAmount(int n) {
        vector<vector<int>> d(n + 1, vector<int>(n + 1, -1));
        return f(d, 1, n);
    }
};
class Solution {
public:
    vector<vector<int>> dp;

    int f(int i, int j) {
        if (i >= j)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;

        for (int k = i; k <= j; k++) {
            ans += f(i, k - 1) * f(k + 1, j);
        }

        return dp[i][j] = ans;
    }

    int numTrees(int n) {
        dp.assign(n + 1, vector<int>(n + 1, -1));
        return f(1, n);
    }
};
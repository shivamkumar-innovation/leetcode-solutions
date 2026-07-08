class Solution {
public:
    int f(vector<int>& a, vector<vector<int>>& dp, int la, int fi) {

        if (la + 1 == fi)
            return 0;

        if (dp[la][fi] != -1)
            return dp[la][fi];

        int l = INT_MAX;

        for (int k = la + 1; k < fi; k++) {
            l = min(l,
                    a[fi] - a[la] +
                    f(a, dp, la, k) +
                    f(a, dp, k, fi));
        }

        return dp[la][fi] = l;
    }

    int minCost(int n, vector<int>& a) {

        a.push_back(0);
        a.push_back(n);
        sort(a.begin(), a.end());

        int m = a.size();

        vector<vector<int>> dp(m, vector<int>(m, -1));

        return f(a, dp, 0, m - 1);
    }
};
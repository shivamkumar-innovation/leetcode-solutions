class Solution {
public:
    int f(vector<int>& a, vector<vector<int>>& d, int i, int b, int t) {
        if (b == t) return 0;
        if (i == a.size()) return INT_MAX;

        if (d[i][t] != -1) return d[i][t];

        int l = INT_MAX;
        if (t + a[i] <= b) {
            int x = f(a, d, i, b, t + a[i]);
            if (x != INT_MAX)
                l = 1 + x;
        }

        int r = INT_MAX;
        int x = f(a, d, i + 1, b, t);
        if (x != INT_MAX)
            r = x;

        return d[i][t] = min(l, r);
    }

    int coinChange(vector<int>& a, int b) {
        sort(a.begin(), a.end(), greater<int>());

        int n = a.size();
        vector<vector<int>> d(n, vector<int>(b + 1, -1));

        int ans = f(a, d, 0, b, 0);

        return (ans == INT_MAX) ? -1 : ans;
    }
};
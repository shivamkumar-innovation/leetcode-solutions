
class Solution {
public:
    int f(int n,vector<vector<int>>& d, int i, int b, int t) {
        if (b == t) return 0;
        if (i == n+1) return INT_MAX;

        if (d[i][t] != -1) return d[i][t];

        int l = INT_MAX;
        if (t + i*i <= b) {
            int x = f(n, d, i, b, t + i*i);
            if (x != INT_MAX)
                l = 1 + x;
        }

        int r = INT_MAX;
        int x = f(n, d, i + 1, b, t);
        if (x != INT_MAX)
            r = x;

        return d[i][t] = min(l, r);
    }

    int numSquares(int b) {
        //sort(a.begin(), a.end(), greater<int>());

        int n = sqrt(b);
        vector<vector<int>> d(n+1, vector<int>(b + 1, -1));

        int ans = f( n,d, 1, b, 0);

        return ans;
    }
};
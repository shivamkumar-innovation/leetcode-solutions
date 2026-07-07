class Solution {
public:
    int f(vector<int>& a, vector<vector<vector<int>>>& d, int i, int buy, int k) {
        if (i >= a.size() || k == -1)
            return 0;

        if (d[i][k][buy] != -1)
            return d[i][k][buy];

        int x = 0;

        if (buy) {
            int le = -a[i] + f(a, d, i + 1, 0, k - 1);
            int r = f(a, d, i + 1, 1, k);
            x = max(le, r);
        } else {
            int le = a[i] + f(a, d, i + 1, 1, k);
            int r = f(a, d, i + 1, 0, k);
            x = max(le, r);
        }

        return d[i][k][buy] = x;
    }

    int maxProfit(vector<int>& a) {
        vector<vector<vector<int>>> d(
            a.size(), vector<vector<int>>(2+1, vector<int>(2, -1)));
        return f(a, d, 0, 1, 2);
    }
};
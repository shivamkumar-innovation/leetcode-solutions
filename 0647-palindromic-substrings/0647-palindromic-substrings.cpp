class Solution {
public:
    int ans = 0;

    bool f(string &a, vector<vector<int>> &d, int i, int j) {

        if (i >= j)
            return true;

        if (d[i][j] != -1)
            return d[i][j];

        if (a[i] != a[j])
            return d[i][j] = false;

        bool ok = f(a, d, i + 1, j - 1);

        if (ok) {
            ans ++;
        }

        return d[i][j] = ok;
    }

    int countSubstrings(string a) {

        int n = a.size();

        vector<vector<int>> d(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++) {
            for (int j = n-1; j >i; j--) {
                f(a, d, i, j);
            }
        }

        return ans+n;
    }
};
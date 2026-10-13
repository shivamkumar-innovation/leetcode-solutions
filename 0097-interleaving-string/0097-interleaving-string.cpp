
class Solution {
public:
    bool f(vector<vector<vector<int>>>& d, string &a,
           string &b, string &s, int x, int i, int j) {

        if (x == -1 && i == -1) {
            return j == -1;
        }

        if (j == -1) {
            return 0;
        }

        if (x == -1) {
            if (b[i] != s[j]) return 0;
            return f(d, a, b, s, x, i - 1, j - 1);
        }

        if (i == -1) {
            if (a[x] != s[j]) return 0;
            return f(d, a, b, s, x - 1, i, j - 1);
        }

        if (d[x][i][j] != -1) {
            return d[x][i][j];
        }

        bool l = 0;
        bool r = 0;

        if (a[x] == s[j]) {
            l = f(d, a, b, s, x - 1, i, j - 1);
        }

        if (b[i] == s[j]) {
            r = f(d, a, b, s, x, i - 1, j - 1);
        }

        return d[x][i][j] = (l || r);
    }

    bool isInterleave(string a, string b, string s) {
        if (a.size() + b.size() != s.size()) {
            return 0;
        }

        int n = a.size(), m = b.size();

        // if (n == 0) return b == s;
        // if (m == 0) return a == s;

        vector<vector<vector<int>>> d(n, vector<vector<int>>(m, vector<int>(s.size(), -1)));

        return f(d, a, b, s, n - 1, m - 1, s.size() - 1);
    }
};

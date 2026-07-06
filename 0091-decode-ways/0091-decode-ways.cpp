class Solution {
public:
    long long f(string a, vector<long long>& d, int i) {
        if (i < 0)
            return 1;

        if (a[i] == '0' && (i == 0 || a[i - 1] == '0' || a[i - 1] >= '3'))
            return INT_MAX;

        if (d[i] != -1)
            return d[i];

        long long l = 0, r = 0;

        if (a[i] == '0') {
            l = f(a, d, i - 2);
        } else {
            l = f(a, d, i - 1);
        }

        if (a[i] != '0'&&i > 0 &&
            (a[i - 1] == '1' ||
             (a[i - 1] == '2' && a[i] <= '6'))) {
            r = f(a, d, i - 2);
        }

        // if (l == INT_MAX) l = 0;
        // if (r == INT_MAX) r = 0;

        return d[i] = l + r;
    }

    int numDecodings(string s) {
        vector<long long> d(s.size(), -1);
        long long ans = f(s, d, s.size() - 1);
        return ans >= INT_MAX ? 0 : ans;
    }
};
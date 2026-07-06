
class Solution {
public:
    int f(vector<int>& d, int i, int j) {

        int ans = 0;
        ans = 1 + d[j];

        d[i] = max(ans, d[i]);
        return d[i];
    }
    int longestStrChain(vector<string>& a) {
        sort(a.begin(), a.end(),[](string& c, string& d) { return c.size() < d.size(); });
        vector<int> d(a.size(), 1);
        int n = a.size();
        int ans = 1;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < i; j++) {
                int c = 0;
                if (a[i].size() - a[j].size() == 1) {
                    int p = 0;
                    int q = 0;
                    while (q < a[i].size()) {
                        if (a[i][q] != a[j][p]) {
                            c++;
                            if (c > 1)
                                break;
                        } else {
                            p++;
                        }
                        q++;
                    }
                }
                if (c == 1)
                    ans = max(ans, f(d, i, j));
            }
        }

        return ans;
    }
};
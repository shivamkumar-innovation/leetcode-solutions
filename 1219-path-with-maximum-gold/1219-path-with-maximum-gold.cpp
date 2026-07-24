class Solution {
public:
    int f(vector<vector<int>>& a, int i, int j) {
        int n = a.size();
        int m = a[0].size();

        int k = a[i][j];
        a[i][j] = 0;

        int p = 0;
        int q = 0;
        int r = 0;
        int s = 0;

        if (j + 1 < m) {
            if (a[i][j + 1] > 0) {
                p = f(a, i, j + 1);
            }
        }

        if (j - 1 >= 0) {
            if (a[i][j - 1] > 0) {
                q = f(a, i, j - 1);
            }
        }

        if (i + 1 < n) {
            if (a[i + 1][j] > 0) {
                r = f(a, i + 1, j);
            }
        }

        if (i - 1 >= 0) {
            if (a[i - 1][j] > 0) {
                s = f(a, i - 1, j);
            }
        }

        a[i][j] = k;

        return k + max({p, q, r, s});
    }

    int getMaximumGold(vector<vector<int>>& a) {
        int m = a.size();
        int n = a[0].size();

        int ans = 0;

        int i = 0;
        while (i < m) {
            int j = 0;
            while (j < n) {
                if (a[i][j] > 0) {
                    ans = max(ans, f(a, i, j));
                }
                j++;
            }
            i++;
        }

        return ans;
    }
};
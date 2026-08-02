class Solution {
public:
    int f(vector<vector<int>> &a, int i, int j, int x) {
        int n = a.size();
        int m = a[0].size();

        a[i][j] = x;
        int k = 1;

        if (j + 1 < m && a[i][j + 1] == 1) {
            k += f(a, i, j + 1, x);
        }

        if (j - 1 >= 0 && a[i][j - 1] == 1) {
            k += f(a, i, j - 1, x);
        }

        if (i + 1 < n && a[i + 1][j] == 1) {
            k += f(a, i + 1, j, x);
        }

        if (i - 1 >= 0 && a[i - 1][j] == 1) {
            k += f(a, i - 1, j, x);
        }

        return k;
    }

    int largestIsland(vector<vector<int>> &a) {

        int n = a.size();
        int m = a[0].size();

        unordered_map<int, int> mp;

        int x = 2;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 1) {
                    int y = f(a, i, j, x);
                    mp[x] = y;
                    x++;
                }
            }
        }

        int ans = 0;

        for (auto it : mp) {
            ans = max(ans, it.second);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (a[i][j] == 0) {

                    int w = -1;
                    int x = -1;
                    int y = -1;
                    int z = -1;

                    if (j + 1 < m && a[i][j + 1] > 1) {
                        w = a[i][j + 1];
                    }

                    if (j - 1 >= 0 && a[i][j - 1] > 1) {
                        x = a[i][j - 1];
                    }

                    if (i + 1 < n && a[i + 1][j] > 1) {
                        y = a[i + 1][j];
                    }

                    if (i - 1 >= 0 && a[i - 1][j] > 1) {
                        z = a[i - 1][j];
                    }

                    int cur = 1;

                    if (w != -1)
                        cur += mp[w];

                    if (x != -1 && x != w)
                        cur += mp[x];

                    if (y != -1 && y != w && y != x)
                        cur += mp[y];

                    if (z != -1 && z != w && z != x && z != y)
                        cur += mp[z];

                    ans = max(ans, cur);
                }
            }
        }

        return ans;
    }
};
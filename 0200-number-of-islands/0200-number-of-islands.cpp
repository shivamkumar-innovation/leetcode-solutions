
class Solution {
public:
    void f(vector<vector<char>> &a, int i, int j) {
        int n = a.size();
        int m = a[0].size();

        a[i][j] = '#';

        if (j + 1 < m && a[i][j + 1] == '1')
            f(a, i, j + 1);

        if (j - 1 >= 0 && a[i][j - 1] == '1')
            f(a, i, j - 1);

        if (i + 1 < n && a[i + 1][j] == '1')
            f(a, i + 1, j);

        if (i - 1 >= 0 && a[i - 1][j] == '1')
            f(a, i - 1, j);
    }

    int numIslands(vector<vector<char>>& a) {
        int n = a.size();
        int m = a[0].size();

        int c = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '1') {
                    c++;
                    f(a, i, j);
                }
            }
        }

        return c;
    }
};
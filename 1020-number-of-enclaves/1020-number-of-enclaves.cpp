class Solution {
public:
    void f(vector<vector<int>>& a, int i, int j) {
        int n = a.size();
        int m = a[0].size();
        a[i][j] = 0;
        if (j + 1 < m) {
            if (a[i][j + 1] == 1) {
                f(a, i, j + 1);
            }
        }
        if (j - 1 >= 0) {
            if (a[i][j - 1] == 1) {

                f(a, i, j - 1);
            }
        }
        if (i + 1 < n) {
            if (a[i + 1][j] == 1) {

                f(a, i + 1, j);
            }
        }
        if (i - 1 >= 0) {
            if (a[i - 1][j] == 1) {

                f(a, i - 1, j);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& a) {
        // Code here
        int n = a.size();
        int m = a[0].size();
        int j = 0;
        int i = 0;
        while (j < m) {
            if (a[0][j] == 1) {
                f(a, 0, j);
            }
            j++;
        }
        j = 0;
        while (j < m) {
            if (a[n - 1][j] == 1) {
                f(a, n - 1, j);
            }
            j++;
        }
        i = 0;
        while (i < n) {
            if (a[i][0] == 1) {
                f(a, i, 0);
            }
            i++;
        }
        i = 0;
        while (i < n) {
            if (a[i][m - 1] == 1) {
                f(a, i, m - 1);
            }
            i++;
        }
        i = 0;
        int c=0;
        while (i < n) {
            j = 0;
            while (j < m) {
                if (a[i][j] == 1){
                    c++;
                }
                j++;
            }
            i++;
        }
        return c;
    }
};

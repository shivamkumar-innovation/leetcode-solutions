class Solution {
public:
    int countSquares(vector<vector<int>>& a) {

        int n = a.size();
        int m = a[0].size();

        vector<vector<int>> d(n, vector<int>(m, 0));

        int ans = 0;

        for (int i = 0; i < n; i++) {
            d[i][0] = a[i][0];
            ans += d[i][0];
        }

        for (int j = 1; j < m; j++) {
            d[0][j] = a[0][j];
            ans += d[0][j];
        }
        int i = 1;
        while (i < a.size()) {
            int j = 1;
            while (j < a[0].size()) {
                if (a[i][j] == 1) {
                    d[i][j] =  min({d[i][j - 1], d[i - 1][j - 1], d[i - 1][j]}) + 1;
                    ans += d[i][j];
                }
                j++;
            }
            i++;
        }
        return ans;
    }
};
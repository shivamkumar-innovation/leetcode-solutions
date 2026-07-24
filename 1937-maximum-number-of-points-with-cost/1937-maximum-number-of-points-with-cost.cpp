// class Solution {
// public:
//     long long f(vector<vector<long long>>& d, vector<vector<int>>& a, int i, int j) {

//         if (i == a.size() - 1) {
//             return a[i][j];
//         }

//         if (d[i][j] != -1) {
//             return d[i][j];
//         }

//         long long ans = LLONG_MIN;

//         for (int x = 0; x < a[0].size(); x++) {
//             ans = max(ans,1LL * a[i][j] - abs(j - x) + f(d, a, i + 1, x));
//         }

//         return d[i][j] = ans;
//     }

//     long long maxPoints(vector<vector<int>>& a) {

//         int n = a.size();
//         int m = a[0].size();

//         vector<vector<long long>> d(n, vector<long long>(m, -1));

//         long long mx = LLONG_MIN;

//         for (int j = 0; j < m; j++) {
//             mx = max(mx, f(d, a, 0, j));
//         }

//         return mx;
//     }
// };


class Solution {
public:
    long long maxPoints(vector<vector<int>>& a) {

        int n = a.size();
        int m = a[0].size();

        vector<long long> dp(m);

        for (int j = 0; j < m; j++) {
            dp[j] = a[n - 1][j];
        }

        for (int i = n - 2; i >= 0; i--) {

            vector<long long> left(m), right(m), ndp(m);

            left[0] = dp[0];
            for (int j = 1; j < m; j++) {
                left[j] = max(left[j - 1] - 1, dp[j]);
            }

            right[m - 1] = dp[m - 1];
            for (int j = m - 2; j >= 0; j--) {
                right[j] = max(right[j + 1] - 1, dp[j]);
            }

            for (int j = 0; j < m; j++) {
                ndp[j] = a[i][j] + max(left[j], right[j]);
            }

            dp = ndp;
        }

        return *max_element(dp.begin(), dp.end());
    }
};
class Solution {
public:
int ans=0;
    bool f(vector<vector<int>>& a,string &s, vector<int>& vi, vector<int>& var,vector<vector<int>>& dp, int i) {

        vi[i] = 1;
        var[i] = 1;
        int j = 0;

        while (j < a[i].size()) {

            if (vi[a[i][j]] == 0) {
                if (f(a, s,vi, var,dp, a[i][j]))
                    return true;
            } else if (var[a[i][j]] == 1) {
                return true;
            }

            j++;
        }
        j = 0;
        while (j < a[i].size()) {
            int k = 0;
            while (k < 26) {
                dp[i][k] = max(dp[i][k], dp[a[i][j]][k]);
                k++;
            }
            j++;
        }
        dp[i][s[i] - 'a']++;

        ans = max(ans, dp[i][s[i] - 'a']);
        var[i] = 0;
        return false;
    }
    int largestPathValue(string s, vector<vector<int>>& v) {
        int n=s.size();
        vector<vector<int>> a(n);

        for (auto &edge : v) {
            int u = edge[0];
            int w = edge[1];
            a[u].push_back(w);
        }

        vector<int> vi(n, 0);
        vector<int> var(n, 0);

         vector<vector<int>> dp(n, vector<int>(26, 0));
        int i = 0;
        while (i < n) {
            if (vi[i] == 0) {
                if (f(a,s, vi, var,dp, i)) {
                    return -1;
                }
            }
            i++;
        }
        return ans;
    }
};
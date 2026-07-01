class Solution {
public:
    vector<pair<int, int>> v;

    int f(int i, vector<int>& dp) {
        if (i >= v.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int next = i + 1;

        if (i + 1 < v.size() && v[i + 1].first == v[i].first + 1)
            next = i + 2;

        int take = v[i].second*v[i].first+ f(next, dp);
        int skip = f(i + 1, dp);

        return dp[i] = max(take, skip);
    }

    int deleteAndEarn(vector<int>& nums) {
        map<int, int> m;

        for (int x : nums)
            m[x] ++;         

        for (auto it : m)
            v.push_back(it);

        vector<int> dp(v.size(), -1);

        return f(0, dp);
    }
};
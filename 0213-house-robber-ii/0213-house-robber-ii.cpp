class Solution {
public:
    int h(vector<int>& nums, int i, int end, vector<int>& dp) {
        if (i >=end)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int take = nums[i] + h(nums, i + 2, end, dp);
        int skip = h(nums, i + 1, end, dp);

        return dp[i] = max(take, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        int ans1 = h(nums, 0, n - 1, dp1); // Exclude last house
        int ans2 = h(nums, 1, n , dp2); // Exclude first house

        return max(ans1, ans2);
    }
};
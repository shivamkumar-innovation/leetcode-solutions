class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, long long> mp;

        long long sum = 0;
        long long ans = LLONG_MIN;

        for (int x : nums) {

            if (mp.count(x - k))
                ans = max(ans, sum + x - mp[x - k]);

            if (mp.count(x + k))
                ans = max(ans, sum + x - mp[x + k]);

            if (!mp.count(x))
                mp[x] = sum;
            else
                mp[x] = min(mp[x], sum);

            sum += x;
        }

        return ans == LLONG_MIN ? 0 : ans;
    }
};
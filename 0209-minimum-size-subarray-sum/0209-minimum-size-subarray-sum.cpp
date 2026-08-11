class Solution {
public:
    int minSubArrayLen(int t, vector<int>& n) {
        int i = 0;
        int j = 0;
        int sum = 0;
        int ans = INT_MAX;

        while (j < n.size()) {
            sum += n[j];

            while (sum >= t && i <= j) {
                ans = min(ans, j - i + 1);
                sum -= n[i];
                i++;
            }

            j++;
        }

        return ans == INT_MAX ? 0 : ans;
    }
};
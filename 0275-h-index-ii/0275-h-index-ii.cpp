class Solution {
public:
    int hIndex(vector<int>& v) {
        int l = 0;
        int ans = 0;
        int r = v.size() - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;

            int x = v.size() - m;

            if (v[m] < x) {
                
                l = m + 1;
            }
            else {
                ans = max(ans, x);
                r = m - 1;
            }
        }

        return ans;
    }
};
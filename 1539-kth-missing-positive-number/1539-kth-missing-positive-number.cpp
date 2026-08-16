class Solution {
public:
    int findKthPositive(vector<int>& v, int k) {
        int l = 0;
        int r = v.size() - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;

            int missing = v[m] - (m + 1);

            if (missing < k)
                l = m + 1;
            else
                r = m - 1;
        }

        return l + k;
    }
};
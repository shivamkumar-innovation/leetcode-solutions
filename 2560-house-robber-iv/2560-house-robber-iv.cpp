class Solution {
public:
    int minCapability(vector<int>& a, int k) {
        int l = *min_element(a.begin(), a.end());
        int r = *max_element(a.begin(), a.end());

        while (l < r) {
            int m = l + (r - l) / 2;
            int i = 0, c = 0;

            while (i < a.size()) {
                if (a[i] <= m) {
                    c++;
                    i += 2;
                } else {
                    i++;
                }
            }

            if (c >= k) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        return l;
    }
};
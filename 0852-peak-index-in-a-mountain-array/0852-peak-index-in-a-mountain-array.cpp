class Solution {
public:
    int peakIndexInMountainArray(vector<int>& v) {
        int l = 0;
        int r = v.size() - 1;

        while (l < r) {
            int m = l + (r - l) / 2;

            if (v[m] < v[m + 1])
                l = m + 1;
            else
                r = m;
        }

        return l;
    }
};
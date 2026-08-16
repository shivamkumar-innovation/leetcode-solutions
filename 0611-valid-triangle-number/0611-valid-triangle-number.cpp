class Solution {
public:
    int triangleNumber(vector<int>& v) {
        sort(v.begin(), v.end());

        int c = 0;
        int i = v.size() - 1;

        while (i >= 2) {
            int l = 0;
            int r = i - 1;

            while (l < r) {
                if (v[l] + v[r] > v[i]) {
                    c += r - l;
                    r--;
                }
                else {
                    l++;
                }
            }

            i--;
        }

        return c;
    }
};
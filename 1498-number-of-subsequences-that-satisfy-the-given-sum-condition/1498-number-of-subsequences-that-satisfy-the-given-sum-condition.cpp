class Solution {
public:
    int numSubseq(vector<int>& v, int t) {
        sort(v.begin(), v.end());
        vector<int> p(v.size());
        p[0] = 1;

        int j = 1;
        while (j < v.size()) {
            p[j] = (p[j - 1] * 2) % 1000000007;
            j++;
        }
        int i = 0;
        int c = 0;
         while (i < v.size()) {
            int l = i;
            int r = v.size() - 1;
            while (l <= r) {
                int m = l + (r - l) / 2;
                if (v[m] > t - v[i]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
            if (r >= i) {
                c =(c+p[r-i])%1000000007 ;
            }
            i++;
        }
        return c;
    }
};
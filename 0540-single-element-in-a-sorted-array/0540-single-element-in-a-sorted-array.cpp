class Solution {
public:
int ans;
    void f(vector<int>& v, int l, int r) {
        if (l == r) {
            ans = v[l];
            return;
        }
        if (l > r)
            return;
            int m=(r-l)/2+l;
        if (m > l && v[m] == v[m-1]) {
            f(v, l, m - 2);
            f(v, m + 1, r);
        } else if (r > m && v[m+1] == v[m]) {
            f(v, m + 2, r);
            f(v, l, m - 1);
        } else {
            ans = v[m];
            return;
        }
    }
    int singleNonDuplicate(vector<int>& v) {
        f(v, 0, v.size() - 1);
        return ans;
    }
};
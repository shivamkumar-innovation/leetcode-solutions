class Solution {
public:
    int kthFactor(int n, int k) {
        int x = sqrt(n);
        int i = 1;
        vector<int> v;
        while (i <= x) {
            if (n % i == 0) {
                if (k == 1) {
                    return i;
                }
                k--;
            }
            i++;
        }
        i--;
        if (x * x == n)
            i--;
        while (i > 0) {
            if (n % i == 0) {
                if (k == 1) {
                    return n / i;
                }
                k--;
            }
            i--;
        }
        return -1;
        // sort(v.begin(),v.end());
        // return v.size()<k?-1:v[k-1];
    }
};
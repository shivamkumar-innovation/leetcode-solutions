class Solution {
public:
    int maxProduct(vector<int>& a) {
        int n = a.size();

        int l = 1, r = 1;
        int ans = INT_MIN;

        for(int i = 0; i < n; i++) {
            l *= a[i];
            r *= a[n - i - 1];

            ans = max(ans, max(l, r));

            if(l == 0)
                l = 1;

            if(r == 0)
                r = 1;
        }

        return ans;
    }
};
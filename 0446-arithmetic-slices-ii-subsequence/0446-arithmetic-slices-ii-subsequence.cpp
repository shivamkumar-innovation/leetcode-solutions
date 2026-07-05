class Solution {
public:
    vector<unordered_map<long long, long long>> d;

    long long f(vector<int>& a, int i, long long diff) {

        if (d[i].count(diff))
            return d[i][diff];

        long long ans = 0;

        for (int j = 0; j < i; j++) {

            if (1LL * a[i] - a[j] == diff) {
                ans += 1 + f(a, j, diff);
            }
        }

        return d[i][diff] = ans;
    }

    int numberOfArithmeticSlices(vector<int>& a) {

        int n = a.size();

        d.assign(n, {});

        long long ans = 0;  

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < i; j++) {

                long long diff = 1LL * a[i] - a[j];

                ans +=   f(a, j, diff);
            }
        }

        return ans;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& i, int o) {
        const int mod = 1e9 + 7;

        sort(i.begin(), i.end(), greater<int>());
        i.push_back(0);

        long long ans = 0;
        long long c = 1;

        int j = 0;

        while (j < i.size() - 1 && o > 0) {

            long long d = 1LL * i[j] - i[j + 1];
            long long k = d * c;

            if (o >= k) {

                ans = (ans + c * (1LL * i[j] + i[j + 1] + 1) * d / 2) % mod;
                o -= k;

            } else {

                long long x = o / c;
                long long y = o % c;

                ans = (ans + c * (2LL * i[j] - x + 1) * x / 2) % mod;
                ans = (ans + y * (i[j] - x)) % mod;

                break;
            }

            c++;
            j++;
        }

        return ans;
    }
};
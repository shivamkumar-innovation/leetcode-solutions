class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& a) {
        sort(a.begin(), a.end(), [](vector<int>& x, vector<int>& y) {
            if (x[0] == y[0])
                return x[1] > y[1];

            return x[0] < y[0];
        });

        vector<int> v;
        v.push_back(a[0][1]);

        int i = 1;

        while (i < a.size()) {
            int x = a[i][1];

            if (x > v.back()) {
                v.push_back(x);
            }
            else {
                int l = 0;
                int r = v.size() - 1;

                while (l < r) {
                    int m = l + (r - l) / 2;

                    if (v[m] < x)
                        l = m + 1;
                    else
                        r = m;
                }

                v[l] = x;
            }

            i++;
        }

        return v.size();
    }
};
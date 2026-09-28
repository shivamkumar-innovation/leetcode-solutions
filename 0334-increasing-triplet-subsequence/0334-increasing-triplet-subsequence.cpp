class Solution {
public:
    bool increasingTriplet(vector<int>& a) {
        vector<int> v;
        v.push_back(a[0]);

        int i = 1;

        while (i < a.size()) {
            if (a[i] > v.back()) {
                v.push_back(a[i]);
            }
            else {
                int l = 0;
                int r = v.size() - 1;

                while (l < r) {
                    int m = l + (r - l) / 2;

                    if (v[m] < a[i])
                        l = m + 1;
                    else
                        r = m;
                }

                v[l] = a[i];
            }

            i++;
        }

        return v.size()>=3?1:0;
        }
};
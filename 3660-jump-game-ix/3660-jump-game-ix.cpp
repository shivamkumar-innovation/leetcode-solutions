class Solution {
public:
    vector<int> maxValue(vector<int>& a) {
        int n = a.size();

        vector<int> p(n);
        p[0] = a[0];

        int i = 1;
        while (i < n) {
            p[i] = max(p[i - 1], a[i]);
            i++;
        }

        vector<int> v(n);

        int m = INT_MAX;
        i = n - 1;

        while (i >= 0) {
            if (p[i] > m) {
                if (i == n - 1)
                    v[i] = p[i];
                else
                    v[i] = v[i + 1];
            } else {
                v[i] = p[i];
            }

            m = min(m, a[i]);
            i--;
        }

        return v;
    }
};
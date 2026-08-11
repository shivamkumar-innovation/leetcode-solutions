class Solution {
public:
    double findMaxAverage(vector<int>& v, int k) {
        int i = 0;
        int j = 0;
        int s = 0;
        int mx = INT_MIN;

        while (j < v.size()) {
            s += v[j];

            if (j - i + 1 == k) {
                mx = max(mx, s);
                s -= v[i];
                i++;
            }

            j++;
        }

        return (double)mx / k;
    }
};
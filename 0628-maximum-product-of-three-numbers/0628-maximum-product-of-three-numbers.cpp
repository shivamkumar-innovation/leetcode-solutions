class Solution {
public:
    int maximumProduct(vector<int>& a) {
        int x = INT_MIN;
        int y = INT_MIN;
        int z = INT_MIN;

        int p = INT_MAX;
        int q = INT_MAX;

        int i = 0;

        while (i < a.size()) {
            if (x <= a[i]) {
                if (z < y)
                    z = y;

                if (x > y)
                    y = x;

                x = a[i];
            }
            else if (y <= a[i]) {
                if (z < y)
                    z = y;

                y = a[i];
            }
            else if (z <= a[i]) {
                z = a[i];
            }

            if (a[i] <= p) {
                q = p;
                p = a[i];
            }
            else if (a[i] <= q) {
                q = a[i];
            }

            i++;
        }

        return max(x * y * z, x * p * q);
    }
};
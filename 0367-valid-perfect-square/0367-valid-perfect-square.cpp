class Solution {
public:
    bool isPerfectSquare(int x) {
        long long l = 0;
        long long r = x;

        while (l <= r) {
            long long m = l + (r - l) / 2;
            if (m * m == x) return 1;
            if (m * m < x)
                l = m+1;
            else
                r = m - 1;
        }

        return 0;
    }
};
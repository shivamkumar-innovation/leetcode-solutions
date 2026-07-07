class Solution {
public:
    long long sumAndMultiply(int n) {

        long long c = 0;
        long long x = 1;
        int sum = 0;

        while (n) {

            int d = n % 10;

            if (d) {
                c = d * x + c;
                sum += d;
                x *= 10;
            }

            n /= 10;
        }

        return c * sum;
    }
};
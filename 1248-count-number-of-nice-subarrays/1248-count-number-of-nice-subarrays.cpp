class Solution {
public:
    int f(vector<int>& v, int k) {
        int count=0;

        int i = 0;
        int ans = 0;

        for (int j = 0; j < v.size(); j++) {
            if (v[j] & 1)
                count++;

            while (count > k) {
                if (v[i] & 1)
                    count--;

                i++;
            }

            ans += j - i + 1;
        }

        return ans;
    }
    int numberOfSubarrays(vector<int>& v, int k) {
        return f(v, k) - f(v, k - 1);
    }
};
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int t) {
        int i = 0;
        int j = 0;
        int s = 0;
        int ans = 0;

        while (j < arr.size()) {
            s += arr[j];

            if (j - i + 1 > k) {
                s -= arr[i];
                i++;
            }

            if (j - i + 1 == k) {
                if (s >= k * t) {
                    ans++;
                }
            }

            j++;
        }

        return ans;
    }
};
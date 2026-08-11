class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> v(26, 0);

        int i = 0;
        int ans = 0;
        int mx = 0;

        for (int j = 0; j < n; j++) {
            v[s[j] - 'A']++;
            mx = max(mx, v[s[j] - 'A']);

            while (j - i + 1 - mx > k) {
                v[s[i] - 'A']--;
                i++;
            }

            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};
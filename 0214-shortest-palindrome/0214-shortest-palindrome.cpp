class Solution {
public:
    string shortestPalindrome(string s) {
        string t = s;
        int m = s.size();

        vector<int> v(m, 0);

        int i = 1, j = 0;

        while (i < m) {
            if (s[i] == s[j]) {
                v[i] = j + 1;
                i++;
                j++;
            }
            else if (j != 0) {
                j = v[j - 1];
            }
            else {
                i++;
            }
        }

        reverse(t.begin(), t.end());

        i = 0;
        j = 0;
        while (j < m && i < m) {
            if (t[j] == s[i]) {
                i++;
                j++;
            }
            else if (i != 0) {
                i = v[i - 1];
            }
            else {
                j++;
            }
        }

        return t.substr(0, m - i) + s;
    }
};
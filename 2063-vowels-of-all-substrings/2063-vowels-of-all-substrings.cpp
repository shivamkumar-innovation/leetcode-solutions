class Solution {
public:
    long long vowels(string& s) {
        long long ans = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
                s[i] == 'o' || s[i] == 'u') {

                ans += 1LL * (i + 1) * (n - i);
            }
        }

        return ans;
    }

    long long countVowels(string word) {
        return vowels(word);
    }
};
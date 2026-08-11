class Solution {
public:
    string minWindow(string s, string a) {
        if (s.size() < a.size())
            return "";

        unordered_map<char, int> m;

        int x = 0;
        while (x < a.size()) {
            m[a[x]]++;
            x++;
        }

        int i = 0;
        int j = 0;

        int cnt = a.size();
        int ans = INT_MAX;
        int z = 0;

        while (j < s.size()) {

            if (m[s[j]] > 0)
                cnt--;

            m[s[j]]--;

            while (cnt == 0) {

                if (j - i + 1 < ans) {
                    ans = j - i + 1;
                    z = i;
                }

                m[s[i]]++;

                if (m[s[i]] > 0)
                    cnt++;

                i++;
            }

            j++;
        }
        return ans == INT_MAX?"":s.substr(z, ans);
    }
};
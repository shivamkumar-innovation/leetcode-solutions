class Solution {
public:
    vector<int> findAnagrams(string a, string b) {
        vector<int> v;
        if (b.size() > a.size()) {
            return v;
        }
        vector<int> d(26, 0);
        vector<int> x(26, 0);
        unordered_set<char> s;

        int j = 0;
        while (j < b.size()) {
            d[b[j] - 'a'] ++;
            j++;
        }

        j = 0;
        int i = 0;
        while (j < a.size()) {
            x[a[j] - 'a']++;
            while(j-i+1>b.size()){
                x[a[i] - 'a']--;
                i++;
            }
            if (d == x) {
                v.push_back(i);
                x[a[i] - 'a']--;
                i++;
            }
            j++;
        }

        return v;
    }
};
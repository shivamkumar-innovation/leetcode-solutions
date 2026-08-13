class Solution {
public:
    int strStr(string h, string n) {
        if (h.size() < n.size())
            return -1;
        vector<int> v(n.size(), 0);

        int i = 1;
        int j = 0;
        while (i < n.size()) {
            if (n[i] == n[j]) {
                v[i] = ++j;
                i++;
            } else {
                if (j != 0) {
                    j = v[j - 1];
                } else {
                    i++;
                }
            }
        }
        i=0;
        j=0;
        while (i < h.size()) {
            if (j == n.size())
                return i - j;
            if (h[i] == n[j]) {
                i++;
                j++;
            } else {
                if (j != 0) {
                    j = v[j - 1];
                } else {
                    i++;
                }
            }
        }
        if (j == n.size())
            return i - j;
        return -1;
    
    }
};
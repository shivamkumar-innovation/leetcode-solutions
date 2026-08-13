class Solution {
public:
    bool repeatedSubstringPattern(string h) {
        vector<int> v(h.size(), 0);
        int i=1;
        int j=0;
        while (i < h.size()) {
            if (h[i] == h[j]) {
                v[i]=j+1;
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
        int x=v.back();
        if( x>0 && x%(h.size()-x)==0) return 1;
        return 0;
    }
};
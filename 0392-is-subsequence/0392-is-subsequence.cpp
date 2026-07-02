class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size()>t.size()) return 0;
        int i=0;
        int j=0;
        while(i<s.size() && j<t.size()){
            if(s[i]==t[j]){
                i++;
            }
            j++;
        }
        if(i==s.size()) return 1;
       return 0;
    }
};
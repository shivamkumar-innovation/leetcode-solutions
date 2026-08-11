class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>m;
        int i=0;
        int j=0;
        int st=0;
        while(j<s.size()){
            if(m[s[j]]==0){
                st=max(st,j-i+1);
                m[s[j]]++;
            }
            else{
               while(m[s[j]]!=0){
                m[s[i]]--;
                i++;
               }
                m[s[j]]++;
            }
            j++;
        }
        return st;
    }
};
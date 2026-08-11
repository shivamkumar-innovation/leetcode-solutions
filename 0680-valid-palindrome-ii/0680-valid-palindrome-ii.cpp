class Solution {
public:
bool f(string s, int i, int j){
    while(i<j){
        if(s[i]!=s[j]){
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}
    bool validPalindrome(string s) {
        int i=0;
        int l=s.size()-1;
        while(i<l){
            if(s[i]!=s[l]){
                return f(s,i+1,l)||f(s,i,l-1);
            }
            i++;
            l--;
        }
        return true;
    }
};
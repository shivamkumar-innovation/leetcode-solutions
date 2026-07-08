// class Solution {
// public:
//     int longestPalindromeSubseq(string s) {
        
//     }
// };


class Solution {
public:
    int f(string& a,  vector<vector<int>>& d, int i,int j) {
        if(i>j){
            return 0;
        }
        if(d[i][j]!=-1) return d[i][j];
        int l=0;
        if(a[i]==a[j]){
            if(i!=j)
            l=2+f(a,d,i+1,j-1);
            else
            l=1+f(a,d,i+1,j-1);
        }
        else{
            l=max(f(a,d,i,j-1),f(a,d,i+1,j));
        }
       return  d[i][j]=l;
    }
    int longestPalindromeSubseq(string a) {
         vector<vector<int>> d(a.size(),vector<int>(a.size(),-1));
        return f(a,d,0,a.size()-1);
    }
};
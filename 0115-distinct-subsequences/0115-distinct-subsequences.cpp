class Solution {
public:
    int f(string& a, string& s, vector<vector<int>>& d, int i,int j,int x) {
        if(i==-1 || j==-1){
            if(x==s.size())
            return 1;
            return 0;
        }
        if(d[i][j]!=-1) return d[i][j];
        int l=0;
        if(a[i]==s[j]){
            l=f(a,s,d,i-1,j-1,x+1);
        }
        int r=f(a,s,d,i-1,j,x);
       return  d[i][j]=l+r;
    }
    int numDistinct(string a, string s) {
         vector<vector<int>> d(a.size(),vector<int>(s.size(),-1));
         return f(a,s,d,a.size()-1,s.size()-1,0);
         
    }
};
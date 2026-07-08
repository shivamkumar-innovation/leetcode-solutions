class Solution {
public:
    int f(string& a, string& s, vector<vector<int>>& d, int i,int j) {
        if(i==-1 || j==-1){
            return 0;
        }
        if(d[i][j]!=-1) return d[i][j];
        int l=0;
        if(a[i]==s[j]){
            l=1+f(a,s,d,i-1,j-1);
        }
        else{
            l=max(f(a,s,d,i,j-1),f(a,s,d,i-1,j));
        }
       return  d[i][j]=l;
    }
    int minDistance(string a, string s) {
         vector<vector<int>> d(a.size(),vector<int>(s.size(),-1));
        int u= f(a,s,d,a.size()-1,s.size()-1);
        return a.size()+s.size()-2*u;
    }
};
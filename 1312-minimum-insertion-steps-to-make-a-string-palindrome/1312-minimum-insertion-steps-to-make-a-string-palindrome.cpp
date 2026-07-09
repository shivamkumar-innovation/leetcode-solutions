// class Solution {
// public:
//     int minInsertions(string s) {
        
//     }
// };


class Solution {
public:
    int f(string& a,vector<vector<int>>& d, int i,int j) {
        if(i>j){
            return 0;
        }
        if(d[i][j]!=-1) return d[i][j];
        int l=0;
        if(a[i]!=a[j]){
            l=1+min(f(a,d,i,j-1),f(a,d,i+1,j));
        }
        else{
            l=f(a,d,i+1,j-1);
        }
       return  d[i][j]=l;
    }
    int minInsertions( string s) {
         vector<vector<int>> d(s.size(),vector<int>(s.size(),-1));
        return f(s,d,0,s.size()-1);
    }
};

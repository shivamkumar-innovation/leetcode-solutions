

class Solution {
public:
   bool f(string &a, string &s,vector<vector<int>>&d,int i,int j){
    if(i==-1 && j==-1) return true;
    if(j==-1 ) return 0;
    if(i==-1){
        while(j>=0 && s[j]=='*'){
            j-=2;
        }
        if(j==-1) return 1;
        else return 0;
    }
    if(d[i][j]!=-1){
        return d[i][j];
    }
    bool l=0;
    bool r=0;
    if(s[j]=='.' || a[i]==s[j]){
        l=f(a,s,d,i-1,j-1);
    }
    else if(s[j]=='*'){
        int p=1;
                if(f(a,s,d,i,j-2)){
                    return 1;
                }
            
        while(i-p+1>=0 && (s[j - 1] == '.' || a[i - p + 1] == s[j - 1]) ){
             if(f(a,s,d,i-p,j-2)){
               return 1;
            }
            p++;
        }
    }
    return d[i][j]=l||r;
  }
    bool isMatch(string a, string s) {
        vector<vector<int>>d(a.size(),vector<int>(s.size(),-1));
        return f(a,s,d,a.size()-1,s.size()-1);
    }
};
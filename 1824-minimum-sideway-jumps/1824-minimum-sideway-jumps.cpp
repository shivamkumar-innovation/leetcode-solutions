class Solution {
public:
int f(vector<int>& a,vector<vector<int>>&d,int p,int i){
    if(i==a.size()-1) return 0;
    if(d[i][p]!=-1) return d[i][p];
    int l=INT_MAX;
    int r=INT_MAX;
    if(a[i+1]==p){
        if(p==1){
            if(a[i]!=2)
        l=1+f(a,d,2,i+1);
        if(a[i]!=3)
        r=1+f(a,d,3,i+1);
        }
        if(p==2){
            if(a[i]!=1)
        l=1+f(a,d,1,i+1);
        if(a[i]!=3)
        r=1+f(a,d,3,i+1);
        }
        if(p==3){
            if(a[i]!=2)
        l=1+f(a,d,2,i+1);
        if(a[i]!=1)
        r=1+f(a,d,1,i+1);
        }
    }
    else{
        l=f(a,d,p,i+1);
    }
        return d[i][p]=min(l,r);
}
    int minSideJumps(vector<int>& a) {
        vector<vector<int>>d(a.size(),vector<int>(4,-1));
        return f(a,d,2,0);
    }
};
class Solution {
public:
int f(vector<int>& a,vector<vector<int>>& d,int i,int l){
    if(i>=a.size()) return 0;
    if(d[i][l]!=-1) return d[i][l];
    int le=0;
    if(a[i]>l){
        int x=0;
        if(i+2<a.size())
        x=f(a,d,i+2,a[i+2]);
        le=a[i]-l+x;
    }
    else if(a[i]<l){
        le=f(a,d,i+1,a[i]);
    }
    int r=f(a,d,i+1,l);
    return d[i][l]=max(le,r);
}
    int maxProfit(vector<int>& a) {
        vector<vector<int>>d(a.size(),vector<int>(*max_element(a.begin(),a.end())+1,-1));
        return f(a,d,0,a[0]);
    }
};
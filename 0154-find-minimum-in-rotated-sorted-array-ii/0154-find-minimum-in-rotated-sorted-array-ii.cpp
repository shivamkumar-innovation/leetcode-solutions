class Solution {
public:
int ans=INT_MAX;
void f(vector<int>& n,int l, int r){
    ans=min(ans,n[l]);
    if(l>=r) return ;
    int m = l + (r - l) / 2;
    if(n[m]==n[r] && n[l]<n[m]){
     return;
    }
    else if(n[m]==n[r] && n[l]==n[m]){
        f(n,l,m);
        f(n,m+1,r);
    }
    else if(n[m]>n[r]){
        f(n,m+1,r);
    }
    else if(n[m]<=n[r]){
        f(n,l,m);
    }


}
    int findMin(vector<int>& n) {
        f(n,0,n.size()-1);
        return ans;
    }
};
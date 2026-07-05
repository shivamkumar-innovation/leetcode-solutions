class Solution {
public:
int k=0;
//int s=0;
int f(vector<int>& a,vector<unordered_map<int, int>> &d, int t,int i,int s){
    if(i==a.size()){
        if(s==t){
            return 1;
        }
        return 0;
    }
    //int x=-a[i];
    if(d[i].count(s))
    return d[i][s];
    int l=0;
    if(s-2*a[i]>=t){
       l= f(a,d,t,i+1,s-2*a[i]);
    }
    int r=f(a,d,t,i+1,s);
    return d[i][s]=l+r;
}
    int findTargetSumWays(vector<int>& a, int t) {
        int s=accumulate(a.begin(),a.end(),0);
        vector<unordered_map<int, int>> d;
        d.assign(a.size(),{});
        return f(a,d,t,0,s);
      //  return k;
    }
};
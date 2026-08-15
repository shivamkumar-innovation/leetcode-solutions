class Solution {
public:
long long f(vector<long long>&d,vector<int>& a, vector<int>& b,int i){
    if(i>=a.size()){
        return 0LL;
    }
    if(d[i]!=-1){
        return d[i];
    }
    int x=1;
    if(i<a.size()-1 && b[i]==b[i+1]){
        x++;
    }
    long long  l=a[i]+f(d,a,b,i+x);
    long long r=f(d,a,b,i+1);
    return d[i]=max(l,r);
}
    long long rob(vector<int>& a, vector<int>& b) {
        int n=a.size();
        vector<long long>d(n,-1);
        return f(d,a,b,0);
    }
};
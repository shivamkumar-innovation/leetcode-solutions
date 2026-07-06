class Solution {
public:
    int f(int t, vector<unordered_map<int,int>>& d,int k,int e) {
        if(k==0){
            if(t==e) return 1;
            return 0;
        }
        if(d[k].count(t)){
            return d[k][t];
        }
        int l= f(t+1, d,k-1,e);
        int r= f(t-1, d,k-1,e);
        return d[k][t] = (l + r)%1000000007;
    }

    int numberOfWays(int t, int e, int k) {
        vector<unordered_map<int,int>> d;
        d.assign(k+1,{});
        int ans = f(t, d,k,e);
        return ans;
    }
};
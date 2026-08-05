class Solution {
public:
vector<vector<int>>ans;
void f(int i, int p,vector<vector<int>>& a,vector<int>&vi,vector<int>&d,vector<int>&l,int time){
    vi[i]=1;
    d[i]=time;
    l[i]=time++;
    int j=0;
    while(j<a[i].size()){
        if(a[i][j]==p){
        }
        else if(!vi[a[i][j]]){
            f(a[i][j],i,a,vi,d,l,time);
            l[i] = min(l[i], l[a[i][j]]);
            if(d[i]<l[a[i][j]]){
                ans.push_back({i,a[i][j]});
            }
        }
        else{
            l[i]=min(d[a[i][j]],l[i]);
        }
        j++;
    }
}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& v) {
        int i=0;
         vector<vector<int>>a(n);
         vector<int>vi(n,0);
         vector<int>d(n,-1);
         vector<int>l(n,-1);
        while(i<v.size()){
            a[v[i][0]].push_back(v[i][1]);
            a[v[i][1]].push_back(v[i][0]);
            i++;
        }
        f(0,-1,a,vi,d,l,0);
        return ans;
    }
};
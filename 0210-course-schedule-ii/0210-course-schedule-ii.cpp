class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& v) {
         vector<vector<int>> a(n);
        vector<int> b(n, 0);
        for (auto &edge : v) {
            int u = edge[0];
            int w = edge[1];
            b[u]++;
            a[w].push_back(u);
        }
        vector<int> vi(n, 0);
        int i=0;
        queue<int>q;
        while(i<n){
            if(b[i]==0){
                q.push(i);
            }
            i++;
        }
        vector<int>c;
        int y=0;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            c.push_back(x);
            y++;
            int j=0;
            while(j<a[x].size()){
                if(b[a[x][j]]!=0){
                   b[a[x][j]]--;
                   if(b[a[x][j]]==0){
                       q.push(a[x][j]);
                   }
                }
                j++;
            }
        }
        if(y==n){
            return c;
        }
        return {};
    }
};
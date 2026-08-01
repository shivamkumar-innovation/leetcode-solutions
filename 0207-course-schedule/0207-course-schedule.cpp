class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& v) {
         vector<vector<int>> a(n);
        vector<int> b(n, 0);
        for (auto &edge : v) {
            int u = edge[0];
            int w = edge[1];
            b[w]++;
            a[u].push_back(w);
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
        int c=0;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            c++;
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
        if(c==n){
            return 1;
        }
        return 0;
    }
};
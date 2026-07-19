class Solution {
public:
    int maximumDetonation(vector<vector<int>>& b) {
        vector<vector<int>> v(b.size());
        int i = 0;
        while (i < b.size()) {
            int j = 0;
            while (j < b.size()) {
                if(j==i){
                    j++;
                    continue;
                }
                long long x = ((long long)b[i][2])*((long long)b[i][2]);
                long long z = ((long long)b[i][0] - (long long)b[j][0]) * ((long long)b[i][0] - (long long)b[j][0]) +
                        ((long long)b[i][1] - (long long)b[j][1]) * ((long long)b[i][1] - (long long)b[j][1]);
                if (x >= z) {
                    v[i].push_back(j);
                }
                j++;
            }
            i++;
        }

        queue<int> q;
         i = 0;
        int p = 0;
        while (i < v.size()) {
            vector<int> a(v.size());
            q.push(i);
            int s = 1;
            a[i]=1;
            while (!q.empty()) {
                int g = q.front();
                q.pop();
                 int j = 0;
                    while (j < v[g].size()) {
                        if (!a[v[g][j]]){
                            s++;
                            a[v[g][j]]=1;
                            q.push(v[g][j]);
                        }
                        j++;
                    }
            }
            p=max(p,s);
            i++;
        }
        return p;
    }
};
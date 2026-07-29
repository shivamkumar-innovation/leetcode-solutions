class Solution {
public:
    bool isBipartite(vector<vector<int>>& a) {
        vector<int> vi(a.size(), -1);
        int i=0;
        while (i < a.size()) {
            queue<int> q;
            q.push(i);
            vi[i] = 0;
            while (!q.empty()) {
                int b = q.front();
                q.pop();
                int j = 0;
                while (j < a[b].size()) {
                    if (vi[a[b][j]] == -1) {
                        vi[a[b][j]] = !vi[b];
                        q.push(a[b][j]);
                    } else if (vi[a[b][j]] == vi[b]) {
                        return false;
                    }
                    j++;
                }
            }
            while (i < a.size()) {
                if (vi[i] == -1) {
                    break;
                }
                i++;
            }
        }
        return true;
    }
};

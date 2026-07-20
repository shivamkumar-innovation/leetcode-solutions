class Solution {
public:
    int orangesRotting(vector<vector<int>>& a) {
        // Code here
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>> v(n, vector<int>(m, 0));
        queue<vector<int>> q;
        int i = 0;
        while (i < n) {
            int j = 0;
            while (j < m) {
                if (a[i][j] == 2) {
                    vector<int> k;
                    k.push_back(i);
                    k.push_back(j);
                    k.push_back(0);
                    q.push(k);
                     v[i][j] = 2;
                }
                j++;
            }
            i++;
        }
        int s = 0;
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            i=t[0];
            int j=t[1];
            if (j + 1 < m) {
                if (a[i][j + 1] == 1 && v[i][j+1]!=2) {
                    vector<int> k;
                    k.push_back(i);
                    k.push_back(j+1);
                    k.push_back(t[2]+1);
                    q.push(k);
                    v[i][j+1]=2;
                    s=max(s,k[2]);
                }
            }
            if (j - 1 >= 0) {
                if (a[i][j - 1] == 1 && v[i][j-1]!=2) {
                    vector<int> k;
                    k.push_back(i);
                    k.push_back(j-1);
                    k.push_back(t[2]+1);
                    q.push(k);
                    v[i][j-1]=2;
                    s=max(s,k[2]);
                }
            }
            if (i + 1 < n) {
                if (a[i + 1][j] == 1 && v[i+1][j]!=2) {
                    vector<int> k;
                    k.push_back(i+1);
                    k.push_back(j);
                    k.push_back(t[2]+1);
                    q.push(k);
                    v[i+1][j]=2;
                    s=max(s,k[2]);
                }
            }
            if (i - 1 >= 0) {
                if (a[i - 1][j] == 1 && v[i-1][j]!=2) {
                    vector<int> k;
                    k.push_back(i-1);
                    k.push_back(j);
                    k.push_back(t[2]+1);
                    q.push(k);
                    v[i-1][j]=2;
                    s=max(s,k[2]);
                }
            }
        }


         i = 0;
        while (i < n) {
            int j = 0;
            while (j < m) {
                if(a[i][j]==1 && v[i][j]!=2){
                    return -1;
                }
                j++;
            }
            i++;
        }
        return s;
    }
};

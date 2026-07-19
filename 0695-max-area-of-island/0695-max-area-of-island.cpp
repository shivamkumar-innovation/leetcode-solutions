class Solution {
public:
int ans=0;
    int f(vector<vector<int>> &a, int i, int j) {
        int n = a.size();
        int m = a[0].size();
        a[i][j] = -1;
        int k=1;
        if (j + 1 < m && a[i][j + 1] == 1){
        
            k+=f(a, i, j + 1);
        }

        if (j - 1 >= 0 && a[i][j - 1] == 1){
            
            k+=f(a, i, j - 1);
        }

        if (i + 1 < n && a[i + 1][j] == 1){
            
            k+=f(a, i + 1, j);
        }

        if (i - 1 >= 0 && a[i - 1][j] == 1){
            
            k+=f(a, i - 1, j);
        }
        return k;
    }

    int maxAreaOfIsland(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 1) {
                   ans=max(ans,f(a, i, j));
                }
            }
        }

        return ans;
    }
};
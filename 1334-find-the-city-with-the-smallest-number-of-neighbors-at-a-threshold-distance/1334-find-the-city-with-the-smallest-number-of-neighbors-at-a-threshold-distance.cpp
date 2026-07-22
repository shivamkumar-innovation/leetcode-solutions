class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& a, int dis) {
        vector<vector<int>> d(n, vector<int>(n, 1e8));

        for (int i = 0; i < n; i++) {
            d[i][i] = 0;
        }

        for (int i = 0; i < a.size(); i++) {
            int u = a[i][0];
            int v = a[i][1];
            int wt = a[i][2];

            d[u][v] = wt;
            d[v][u] = wt;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (j!=k && d[j][i] != 1e8 && d[i][k] != 1e8 &&
                        d[j][i] + d[i][k] < d[j][k]) {

                        d[j][k] = d[j][i] + d[i][k];
                    }
                }
            }
        }

        int i=0;
        int s=-1;
        int y=INT_MAX;
        while(i<n){
            int j=0;
            int x=0;
            while(j<n){
                if(j!=i && d[i][j]<=dis){
                    x++;
                }
                j++;
            }
            if(x<y){
                y=x;
                s=i;
            }
            else if(x==y){
                s=max(s,i);
            }
            i++;
        }
        return s;
    }
};
// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
//     }
// };
class Solution {
public:
    int f(vector<vector<int>>& a,vector<vector<int>>& d, int m, int n) {
        // if (m - 1 == -1) {
        //     return 0;
        // }
        // if (n - 1 == -1) {
        //     return 0;
        // }
        if(a[m][n]==1){
            return 0;
        }
        if (m == 0 && n == 0) {
            return 1;
        }
        if(d[m][n]!=-1){
            return d[m][n];
        }
        int l=0;
        if (m - 1 >=0 ) {
           l= f(a,d,m-1,n);
        }
        int r=0;
        if (n - 1>=0 ) {
            r=f(a,d,m,n-1);
        }

        return d[m][n]=l+r;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        //if(m==n && n==0) return 0;
        int m=a.size();
        int n=a[0].size();
        vector<vector<int>> v(m, vector<int>(n, -1));
        return f(a,v, m - 1, n - 1);
    }
};
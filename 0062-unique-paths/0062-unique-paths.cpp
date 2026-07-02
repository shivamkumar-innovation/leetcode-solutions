class Solution {
public:
    int f(vector<vector<int>>& d, int m, int n) {
        // if (m - 1 == -1) {
        //     return 0;
        // }
        // if (n - 1 == -1) {
        //     return 0;
        // }
        if (m == 0 && n == 0) {
            return 1;
        }
        if(d[m][n]!=-1){
            return d[m][n];
        }
        int l=0;
        if (m - 1 >=0) {
           l= f(d,m-1,n);
        }
        int r=0;
        if (n - 1>=0) {
            r=f(d,m,n-1);
        }

        return d[m][n]=l+r;
    }
    int uniquePaths(int m, int n) {
        if(m==n && n==0) return 0;
        vector<vector<int>> v(m, vector<int>(n, -1));
        return f(v, m - 1, n - 1);
    }
};
class Solution {
public:
    int f(vector<vector<int>>& a, vector<vector<int>>& d, int i, int x) {
        if (a.size() == x) {
            return 0;
        }
        if (d[x][i] != -100000) {
            return d[x][i];
        }
        int r = INT_MAX;
            r = f(a, d, i, x+1) + a[x][i];
        int fi = INT_MAX;
            fi = f(a, d, i + 1, x+1) + a[x][i];
        
        return d[x][i] =  min(r, fi);
    }

    int minimumTotal(vector<vector<int>>& a) {
        // if (a.size() == 1)
        //     return a[0][0];
        vector<vector<int>> v(a.size(), vector<int>(a.size(), -100000));
        return f(a, v, 0, 0);
        
    }
};
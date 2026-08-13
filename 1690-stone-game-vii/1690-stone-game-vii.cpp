class Solution {
public:
    int f(vector<vector<int>>& d, vector<int>& v,
          int i, int j, int t) {

        if(i >= j) {
            return 0;
        }

        if(d[i][j] != -1)
            return d[i][j];

        int x;

            int l = t - v[i] - f(d, v, i+1, j, t-v[i]);
            int r = t - v[j] - f(d, v, i, j-1, t-v[j]);

            x = max(l, r);
        

        return d[i][j]=x;
    }

    int stoneGameVII(vector<int>& v) {
        int n = v.size();

        vector<vector<int>> d(n, vector<int>(n, -1));

        int t = accumulate(v.begin(), v.end(), 0);

        return f(d, v, 0, n-1, t);
    }
};
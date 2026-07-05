class Solution {
public:
    int f(vector<int>& a, vector<vector<int>>& d, int i, int b, int t) {
        if (b == t) return 1;
        if (i == a.size() || t>b) return 0;

        if (d[i][t] != -1) return d[i][t];

        int l = 0;
        if (t + a[i] <= b) {
            l = f(a, d, i, b, t + a[i]);
        }

       
       int r = f(a, d, i + 1, b, t);


        return d[i][t] = l+r;
    }

    int change(int b,vector<int>& a) {
        int n = a.size();
        vector<vector<int>> d(n, vector<int>(b + 1, -1));

        return f(a, d, 0, b, 0);

       // return (ans == INT_MAX) ? -1 : ans;
    }
};
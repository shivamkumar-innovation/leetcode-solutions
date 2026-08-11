class Solution {
public:
    int f(vector<vector<int>>& d, vector<int>& v, int i, int j, int t) {
        if (i >= j) {
            return 0;
        }
        if (d[i][j] != -1) {
            return d[i][j];
        }
        int l = 0;
        int s = 0;
        int x = i;
        while (x < j) {
            s = s + v[x];
            t -= v[x];
            if (s > t) {
                l = max(l, t + f(d, v, x + 1, j, t));
            } else if (s < t) {
                l = max(l, s + f(d, v, i, x, s));
            } else {
                l = max(l, s + max(f(d, v, x + 1, j, t), f(d, v, i, x, s)));
            }
            x++;
        }
        return d[i][j] = l;
    }

    int stoneGameV(vector<int>& v) {
        vector<vector<int>> d(v.size(), vector<int>(v.size(), -1));

            return f(d, v, 0, v.size() - 1, accumulate(v.begin(), v.end(), 0));
    }
};
class Solution {
public:
    int f(vector<vector<int>>& d, vector<int>& v, int i, int j) {
        if (i == j)
            return v[i];

        if (d[i][j] != -1)
            return d[i][j];

        return d[i][j] = max(v[i] - f(d, v, i + 1, j),v[j] - f(d, v, i, j - 1));
    }

    bool predictTheWinner(vector<int>& v) {
        int n = v.size();

        vector<vector<int>> d(n, vector<int>(n, -1));

        return f(d, v, 0, n - 1) >= 0;
    }
};
class Solution {
public:
    bool f(vector<vector<int>>& d, vector<int>& v, int i, int de) {
        if (i == de)
            return true;

        v[i] = 1;

        for (int j : d[i]) {
            if (!v[j]) {
                if (f(d, v, j, de))
                    return true;
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& a, int s, int de) {

        vector<vector<int>> d(n);

        for (auto &e : a) {
            int u = e[0];
            int v = e[1];

            d[u].push_back(v);
            d[v].push_back(u);
        }

        vector<int> v(n, 0);

        return f(d, v, s, de);
    }
};
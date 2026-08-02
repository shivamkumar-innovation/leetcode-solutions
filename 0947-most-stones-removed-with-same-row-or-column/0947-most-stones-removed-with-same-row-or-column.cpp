class Solution {
public:
    vector<int> p, r;

    int f(int x) {
        if (p[x] == x)
            return x;

        return p[x] = f(p[x]);
    }

    int removeStones(vector<vector<int>>& s) {

        int mr = 0, mc = 0;

        int i = 0;
        while (i < s.size()) {
            mr = max(mr, s[i][0]);
            mc = max(mc, s[i][1]);
            i++;
        }

        int m = mr + 1;
        int n = m + mc + 1;

        p.resize(n);
        r.assign(n, 0);

        i = 0;
        while (i < n) {
            p[i] = i;
            i++;
        }

        unordered_set<int> st;
        int comp = 0;

        i = 0;
        while (i < s.size()) {

            int row = s[i][0];
            int col = s[i][1] + m;

            if (st.find(row) == st.end()) {
                st.insert(row);
                comp++;
            }

            if (st.find(col) == st.end()) {
                st.insert(col);
                comp++;
            }

            int u = f(row);
            int v = f(col);

            if (u != v) {

                if (r[u] < r[v])
                    p[u] = v;
                else if (r[u] > r[v])
                    p[v] = u;
                else {
                    p[v] = u;
                    r[u]++;
                }

                comp--;
            }

            i++;
        }

        return s.size() - comp;
    }
};
class Solution {
public:
    int f(vector<int>& p, int x) {
        if (p[x] == x)
            return x;
        return p[x] = f(p, p[x]);
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& d) {
        int n = d.size();

        vector<int> p(n), r(n, 0);

        for (int i = 0; i < n; i++)
            p[i] = i;

        unordered_map<string, int> mp;

        for (int i = 0; i < n; i++) {

            for (int j = 1; j < d[i].size(); j++) {

                string s = d[i][j];

                if (mp.find(s) == mp.end()) {
                    mp[s] = i;
                } else {

                    int u = f(p, i);
                    int v = f(p, mp[s]);

                    if (u != v) {

                        if (r[u] < r[v])
                            p[u] = v;
                        else if (r[u] > r[v])
                            p[v] = u;
                        else {

                            if (u < v) {
                                p[v] = u;
                                r[u]++;
                            } else {
                                p[u] = v;
                                r[v]++;
                            }
                        }
                    }
                }
            }
        }

        unordered_map<int, set<string>> m;

        for (int i = 0; i < n; i++) {

            int u = f(p, i);

            for (int j = 1; j < d[i].size(); j++)
                m[u].insert(d[i][j]);
        }

        vector<vector<string>> ans;

        for (auto& x : m) {

            vector<string> t;

            t.push_back(d[x.first][0]);

            for (auto& y : x.second)
                t.push_back(y);

            ans.push_back(t);
        }

        return ans;
    }
};
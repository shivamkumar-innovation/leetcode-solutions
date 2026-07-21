class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& a, int s, int d, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            p;

        vector<vector<pair<int, int>>> v(n);
        k++;
        vector<vector<int>> vi(n, vector<int>(k + 1, INT_MAX));

        int i = 0;
        while (i < a.size()) {
            int u = a[i][0];
            int x = a[i][1];
            int wt = a[i][2];

            v[u].push_back({x, wt});
            i++;
        }

        p.push({0, s, k});
        vi[s][k] = 0;

        while (!p.empty()) {

            auto b = p.top();
            p.pop();
            if (d == b[1]) {
                continue;
            }

            if (b[0] > vi[b[1]][b[2]] || b[2] <= 0)
                continue;

            for (auto j : v[b[1]]) {

                int node = j.first;
                int wt = j.second;

                int c = b[0] + wt;

                if (c < vi[node][b[2] - 1]) {
                    vi[node][b[2] - 1] = c;
                    p.push({c, node, b[2] - 1});
                }
            }
        }

        int sa = INT_MAX;
        for (int i = 0; i < vi[d].size(); i++)
            sa = min(sa, vi[d][i]);
        return sa==INT_MAX ? -1 : sa;
    }
};
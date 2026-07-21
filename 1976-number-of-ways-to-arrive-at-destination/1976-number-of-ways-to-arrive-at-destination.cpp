class Solution {
public:
    int countPaths(int n, vector<vector<int>>& a) {
        priority_queue<vector<long long>, vector<vector<long long>>,
                       greater<vector<long long>>> p;

        vector<vector<pair<int,int>>> v(n);

        vector<pair<long long,int>> vi(n, {LLONG_MAX,0});

        int i = 0;
        while (i < a.size()) {
            int u = a[i][0];
            int x = a[i][1];
            int wt = a[i][2];

            v[u].push_back({x, wt});
            v[x].push_back({u, wt});

            i++;
        }

        p.push({0,0});
        vi[0] = {0LL,1};
        while (!p.empty()) {

            auto b = p.top();
            p.pop();

            if(b[1]==n-1){
                continue;
            }

            if (b[0] > vi[b[1]].first)
                continue;

            for (auto j : v[b[1]]) {

                int node = j.first;
                int wt = j.second;

                long long c = b[0] + wt;

                if (c < vi[node].first) {
                    vi[node].first = c;
                    vi[node].second = vi[b[1]].second;
                    p.push({c,node});
                }
                else if(c == vi[node].first){
                    vi[node].second =(vi[node].second + vi[b[1]].second) % (1000000007);
                }
            }
        }
        return vi[n-1].second;
    }
};
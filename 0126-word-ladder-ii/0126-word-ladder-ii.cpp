class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> par;
    unordered_map<string, int> dis;

    void dfs(string s, string &b, vector<string> &v) {

        if (s == b) {
            vector<string> t = v;
            reverse(t.begin(), t.end());
            ans.push_back(t);
            return;
        }

        for (auto &x : par[s]) {
            v.push_back(x);
            dfs(x, b, v);
            v.pop_back();
        }
    }

    vector<vector<string>> findLadders(string b, string e, vector<string>& w) {

        unordered_set<string> st;

        for (auto &x : w)
            st.insert(x);

        if (!st.count(e))
            return {};

        queue<string> q;
        q.push(b);

        dis[b] = 0;

        while (!q.empty()) {

            string cur = q.front();
            q.pop();

            string s = cur;

            for (int i = 0; i < s.size(); i++) {

                char c = s[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {

                    s[i] = ch;

                    if (!st.count(s))
                        continue;

                    if (!dis.count(s)) {

                        dis[s] = dis[cur] + 1;
                        par[s].push_back(cur);
                        q.push(s);
                    }
                    else if (dis[s] == dis[cur] + 1) {

                        par[s].push_back(cur);
                    }
                }

                s[i] = c;
            }
        }

        if (!dis.count(e))
            return {};

        vector<string> v;
        v.push_back(e);

        dfs(e, b, v);

        return ans;
    }
};
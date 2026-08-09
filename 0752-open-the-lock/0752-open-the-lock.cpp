class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        unordered_set<string> st(deadends.begin(), deadends.end());

        if (st.count("0000") || st.count(target))
            return -1;

        q.push("0000");
        st.insert("0000");

        int t = 0;

        while (!q.empty()) {
            int n = q.size();

            while (n--) {
                string s = q.front();
                q.pop();

                if (s == target)
                    return t;

                for (int i = 0; i < 4; i++) {
                    string d = s;

                    d[i]++;
                    if (d[i] > '9')
                        d[i] = '0';

                    if (!st.count(d)) {
                        q.push(d);
                        st.insert(d);
                    }

                    d = s;

                    d[i]--;
                    if (d[i] < '0')
                        d[i] = '9';

                    if (!st.count(d)) {
                        q.push(d);
                        st.insert(d);
                    }
                }
            }

            t++;
        }

        return -1;
    }
};
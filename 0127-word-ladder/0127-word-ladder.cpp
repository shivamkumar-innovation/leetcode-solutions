class Solution {
public:
    int ladderLength(string b, string e, vector<string>& w) {

        unordered_set<string> st;

        int i = 0;
        while (i < w.size()) {
            st.insert(w[i]);
            i++;
        }

        if (st.find(e) == st.end())
            return 0;

        queue<pair<string, int>> q;

        q.push({b, 1});
        st.erase(b);

        while (!q.empty()) {

            auto x = q.front();
            q.pop();

            string s = x.first;
            int l = x.second;

            if (s == e)
                return l;

            i = 0;

            while (i < s.size()) {

                char c = s[i];

                char ch = 'a';

                while (ch <= 'z') {

                    s[i] = ch;

                    if (st.find(s) != st.end()) {

                        q.push({s, l + 1});
                        st.erase(s);
                    }

                    ch++;
                }

                s[i] = c;
                i++;
            }
        }

        return 0;
    }
};
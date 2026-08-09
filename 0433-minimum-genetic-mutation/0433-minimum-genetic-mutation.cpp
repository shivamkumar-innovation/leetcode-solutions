class Solution {
public:
    int minMutation(string a, string b, vector<string>& bank) {
        queue<string> q;
        q.push(a);

        unordered_set<string> st(bank.begin(), bank.end());

        int t = 0;

        while (!q.empty()) {
            t++;
            int n = q.size();
            int j = 0;

            while (j < n) {
                string s = q.front();
                q.pop();

                int i = 0;

                if (s == b) {
                    return t - 1;
                }

                while (i < 8) {
                    string d = s;
                    char c = d[i];

                    if (c != 'A') {
                        d[i] = 'A';
                        if (st.count(d)) {
                            q.push(d);
                            st.erase(d);
                        }
                    }

                    if (c != 'C') {
                        d[i] = 'C';
                        if (st.count(d)) {
                            q.push(d);
                            st.erase(d);
                        }
                    }

                    if (c != 'T') {
                        d[i] = 'T';
                        if (st.count(d)) {
                            q.push(d);
                            st.erase(d);
                        }
                    }

                    if (c != 'G') {
                        d[i] = 'G';
                        if (st.count(d)) {
                            q.push(d);
                            st.erase(d);
                        }
                    }

                    i++;
                }

                j++;
            }
        }

        return -1;
    }
};
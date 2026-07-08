class Solution {
public:
    int x = 0;

    int f(vector<vector<int>>& a, int i) {

        int n = a[i].size();

        vector<int> ans(n);
        stack<int> st;

        // Next Smaller
        for (int j = n - 1; j >= 0; j--) {

            while (!st.empty() && a[i][st.top()] >= a[i][j])
                st.pop();

            if (st.empty())
                ans[j] = n;
            else
                ans[j] = st.top();

            st.push(j);
        }

        while (!st.empty())
            st.pop();

        vector<int> an(n);

        // Previous Smaller
        for (int j = 0; j < n; j++) {

            while (!st.empty() && a[i][st.top()] >= a[i][j])
                st.pop();

            if (st.empty())
                an[j] = -1;
            else
                an[j] = st.top();

            st.push(j);
        }

        int m = 0;

        for (int j = 0; j < n; j++) {

            int width = ans[j] - an[j] - 1;
            int s = min(width , a[i][j]);

            m = max(m, s*s);
        }

        return m;
    }
    int maximalSquare(vector<vector<char>>& b) {

        int r = b.size();
        int c = b[0].size();

        vector<vector<int>> a(r, vector<int>(c));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if(b[i][j]=='1'){
                    x=1;
                }
                a[i][j] = b[i][j] - '0';
            }
        }

        x=max(x,f(a, 0));

        int i = 1;

        while (i < r) {

            int j = 0;

            while (j < c) {

                if (a[i][j] != 0)
                    a[i][j] += a[i - 1][j];
                else
                    a[i][j] = 0;

                j++;
            }

             x=max(x,f(a, i));

            i++;
        }

        return x;
    }
};
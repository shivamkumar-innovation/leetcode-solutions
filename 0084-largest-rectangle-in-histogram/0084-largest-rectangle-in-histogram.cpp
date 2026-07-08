class Solution {
public:
    int largestRectangleArea(vector<int>& a) {

        int n = a.size();

        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && a[st.top()] >= a[i])
                st.pop();

            if (st.empty())
                ans[i] = n-1;
            else
                ans[i] = st.top()-1 ;

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        vector<int> an(n);

        for (int i = 0; i < n; i++) {

            while (!st.empty() && a[st.top()] >= a[i])
                st.pop();

            if (st.empty())
                an[i] = 0;
            else
                an[i] = st.top()+1;

            st.push(i);
        }

        int m = 0;

        for (int i = 0; i < n; i++) {

            int width = ans[i] - an[i] + 1;
            int area = width * a[i];

            m = max(m, area);
        }

        return m;
    }
};
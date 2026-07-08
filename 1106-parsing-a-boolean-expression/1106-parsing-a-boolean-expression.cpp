class Solution {
public:
    bool parseBoolExpr(string a) {
        stack<char> st;

        for (int i = a.size() - 1; i >= 0; i--) {

            if (a[i] == ',' || a[i] == '(')
                continue;

            if (a[i] == 't')
                st.push('1');
            else if (a[i] == 'f')
                st.push('0');
            else if (a[i] == ')')
                st.push(')');
            else {

                char op = a[i];
                char x = st.top();
                st.pop();

                if (op == '&') {

                    while (st.top() != ')') {
                        char y = st.top();
                        st.pop();

                        x = ((x - '0') & (y - '0')) + '0';
                    }

                    st.pop();
                    st.push(x);
                }
                else if (op == '|') {

                    while (st.top() != ')') {
                        char y = st.top();
                        st.pop();

                        x = ((x - '0') | (y - '0')) + '0';
                    }

                    st.pop();
                    st.push(x);
                }
                else {

                    x = (x == '1') ? '0' : '1';

                    st.pop();
                    st.push(x);
                }
            }
        }

        return st.top() == '1';
    }
};
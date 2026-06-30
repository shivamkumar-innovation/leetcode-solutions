class Solution {
public:
    bool checkValidString(string s) {
        int i=0;
        stack<int>st;
        stack<int>a;
        int k=0;
        // int a=0;
        while(i<s.size()){
            if(st.empty() && a.empty() && s[i]==')') return 0;

            else if(!st.empty() && s[i]==')'){
                st.pop();
            }
            else if(!a.empty() && s[i]==')'){
                a.pop();
            }
            else if(s[i]=='('){
                st.push(i);
            }
            else{
                a.push(i);
                //k++;
            }
            i++;
        }
        if(st.size()>a.size()){
                return 0;
            }
        while(!st.empty()){
            if(st.top()<a.top()){
                st.pop();
                a.pop();
            }
            else{
               return 0;
            }
        }
            // if(st.size()>a.size()){
            //     return 0;
            // }
        return 1;
    }
};
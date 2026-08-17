class Solution {
public:
    string robotWithString(string s) {
        int i=s.size()-1;
        stack<char>t;
        string e;
        vector<char>v(s.size());
        v[i]=s[i];
        i--;
        while(i>=0){
            v[i]=min(s[i],v[i+1]);
            i--;
        }
        i=0;
        while(i<s.size()){
            t.push(s[i]);
          i++;
            while(!t.empty() && i<s.size() && t.top()<=v[i]){
                e.push_back(t.top());
                t.pop();
            }
              
        }
        while(!t.empty()){
            e.push_back(t.top());
                t.pop();
        }
        return e;
    }
};
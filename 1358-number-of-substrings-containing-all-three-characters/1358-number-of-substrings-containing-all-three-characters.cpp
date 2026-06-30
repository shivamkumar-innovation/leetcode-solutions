class Solution {
public:
    int numberOfSubstrings(string v) {
        int i=0;
        int j=0;
        int t=0;
        unordered_map<char,int>m;
        while(j<v.size()){
            m[v[j]]++;
            if(m['a']>=1 && m['b']>=1 && m['c']>=1){
                t++;
                int k=v.size()-j-1;
                t=t+k;
                m[v[i]]--;
                i++;
                while(m['a']>=1 && m['b']>=1 && m['c']>=1){
                    t=t+k+1;
                    m[v[i]]--;
                    i++;
                }
            }
            j++;
        }
        return t;
    }
};
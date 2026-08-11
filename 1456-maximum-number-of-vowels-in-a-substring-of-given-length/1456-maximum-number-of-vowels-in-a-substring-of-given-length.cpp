class Solution {
public:
    int maxVowels(string n, int k) {
        unordered_set<char>st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        int i=0;
        int j=0;
        int s=0;
        int ans=0;

       while(j<n.size()){
        
        if(j-i+1>k){
            if(st.count(n[i])){
                s--;
            }
            i++;
        }
        if(st.count(n[j])){
                s++;
                ans=max(ans,s);
            }
        j++;
       }
        return ans;
    }
};
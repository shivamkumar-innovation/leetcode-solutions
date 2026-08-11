class Solution {
public:
    int totalFruit(vector<int>& n) {
        int i=0;
        int j=0;
        unordered_map<int,int>m;
        int ans=0;
        while(j<n.size()){
            if(m.size()<2 || (m.size()==2 && m.count(n[j]))){
                m[n[j]]=j;
            }
            else{
                auto it=m.begin();
                auto kt=it++;
                i=min(kt->second,it->second);
                if(it->second==i){
                    m.erase(it->first);
                }
                else{
                    m.erase(kt->first);
                }
                m[n[j]]=j;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
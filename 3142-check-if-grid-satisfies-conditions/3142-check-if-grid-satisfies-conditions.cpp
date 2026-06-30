class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& g) {
        int i=0;
        while(i<g[0].size()){
            int j=0;
            while(j<g.size()){
                if(i<g[0].size()-1 && g[j][i]==g[j][i+1]){
                    return 0;
                }
                if(j<g.size()-1 && g[j][i]!=g[j+1][i]){
                    return 0;
                }
                j++;
            }
            i++;
        }
        return true;
    }
};
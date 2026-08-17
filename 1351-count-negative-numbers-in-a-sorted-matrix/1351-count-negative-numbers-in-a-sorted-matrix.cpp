class Solution {
public:
    int countNegatives(vector<vector<int>>& v) {
        int i=0;
        int c=0;
        while(i<v.size()){
            int l=0;
            int r=v[0].size()-1;
            while(l<=r){
                int m=l+(r-l)/2;
                if(v[i][m]>-1){
                    l=m+1;
                }
                else{
                    r=m-1;
                }
            }
            c=c+v[0].size()-l;
            i++;
        }
        return c;
    }
};
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& a) {
        sort(a.begin(), a.end(), [](vector<int>& x, vector<int>& y) {
            if (x[0] == y[0])
                return x[1] > y[1];
            return x[0] < y[0];
        });
        int ans=0;
        int i=0;
        int j=1;
        while(j<a.size()){
            if(a[i][0]<=a[j][0] && a[i][1]>=a[j][1]){
                j++;
                ans++;
            }
            else{
                i=j;
                j++;
            }
        }
        return a.size()-ans;
    }
};
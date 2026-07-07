

class Solution {
public:
    int f(vector<int>& a, vector<vector<int>>& d, int i, int buy,
          int fee) {
        if (i >= a.size())
            return 0;
        if (d[i][buy] != -1)
            return d[i][buy];
        int x = 0;
         if (buy) {
            int le = -a[i] + f(a, d, i + 1, 0,fee); 
            int r = f(a, d, i + 1, 1,fee);         
            x = max(le, r);
        } else {
            int le = a[i]-fee + f(a, d, i + 1, 1,fee); 
            int r = f(a, d, i + 1, 0,fee);         
            x = max(le, r);
        }
        return d[i][buy] = x;
    }
    int maxProfit(vector<int>& a, int fee) {
        vector<vector<int>> d(a.size(), vector<int>(2, -1));
        return f(a, d, 0,1, fee);
    }
};
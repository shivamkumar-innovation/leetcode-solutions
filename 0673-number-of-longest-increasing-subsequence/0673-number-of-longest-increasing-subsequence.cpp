
class Solution {
public:
    void f(vector<pair<int,int>>& d, int i, int j) {

        int ans = 1 + d[j].first;

        if (ans > d[i].first) {
            d[i].first = ans;
            d[i].second = d[j].second;
        } 
        else if (ans == d[i].first) {
            d[i].second += d[j].second;
        }
    }

    int findNumberOfLIS(vector<int>& a) {

        int n = a.size();

        vector<pair<int,int>> d(n, {1,1});

        int mx = 0;
        // int k=0;

        for (int i = 0; i < n; i++) {

            for (int j = i - 1; j >= 0; j--) {

                if (a[j] < a[i])
                    f(d, i, j);
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {

            if (d[i].first > mx){
                mx=d[i].first;
                ans = d[i].second;
            }
            else if(d[i].first == mx){
                 ans += d[i].second;
            }
        }

        return ans;
    }
};
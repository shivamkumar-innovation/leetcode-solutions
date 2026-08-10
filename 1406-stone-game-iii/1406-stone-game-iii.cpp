class Solution {
public:
    int f(vector<vector<int>>& d, vector<int>& v, int i, int k) {

        if (i >= v.size()) {
            return 0;
        }

        if (d[i][k] != -1) {
            return d[i][k];
        }

        int l;

        if (k) {
            l = INT_MIN;
            int x = 0;
            int u = 0;

            while ((x + i) < v.size() && x < 3) {

                u = u + v[x + i];

                l = max(l, u + f(d, v, x + i + 1, 0));

                x++;
            }
        } else {
            l = INT_MAX;
            int x = 0;

            while ((x + i) < v.size() && x <3) {

                l = min(l, f(d, v, x + i + 1, 1));
                x++;
            }
        }

        return d[i][k] = l;
    }

    string stoneGameIII(vector<int>& v) {

        vector<vector<int>> d(v.size(),vector<int>(2, -1));
        int t=accumulate(v.begin(),v.end(),0);
        int x= f(d, v, 0, 1);
        if (x > t - x) {
            return "Alice";
        }
        else if (x < t - x) {
            return "Bob";
        }
        return "Tie";
    }
};

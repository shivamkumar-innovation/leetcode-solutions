class Solution {
public:

    int f(vector<int>& p, int j) {
        if (j == p[j]) {
            return j;
        }
        return p[j] = f(p, p[j]);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& a) {

        int n = a.size();

        vector<int> p(n + 1);
        vector<int> r(n + 1, 0);
        int t=-1;
        int q=-1;
        int i = 0;
        while (i <= n) {
            p[i] = i;
            i++;
        }

        i = 0;
        while (i < n) {

            int x = f(p, a[i][0]);
            int y = f(p, a[i][1]);

            if (x == y) {
                t=a[i][0];
                q=a[i][1];
            }

            if (r[x] < r[y]) {
                p[x] = y;
            }
            else if (r[x] > r[y]) {
                p[y] = x;
            }
            else {
                p[y] = x;
                r[x]++;
            }

            i++;
        }

        return {t,q};
    }
};
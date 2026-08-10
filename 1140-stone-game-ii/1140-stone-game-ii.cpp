class Solution {
public:

    int f(vector<vector<vector<int>>>&d, vector<int>& v, int i, int m, int k) {

        if (i >= v.size()) {
            return 0;
        }

        if (d[i][m][k] != -1) {
            return d[i][m][k];
        }

        int l;

        if (k) {  
            l = 0;
            int x = 0;
            int u = 0;

            while ((x + i) < v.size() && x < (2 * m)) {

                u = u + v[x + i];

                l = max(l,u + f(d, v, x + i + 1,max(m, x + 1), 0));

                x++;
            }
        }
        else { 
            l = INT_MAX;
            int x = 0;

            while ((x + i) < v.size() && x < (2 * m)) {

                l = min(l,f(d, v, x + i + 1,max(m, x + 1), 1));
                x++;
            }
        }

        return d[i][m][k] = l;
    }

    int stoneGameII(vector<int>& v) {

        vector<vector<vector<int>>> d(
            v.size() ,
            vector<vector<int>>(
                v.size()+1,
                vector<int>(2, -1)
            )
        );

        return f(d, v, 0, 1, 1);
    }
};
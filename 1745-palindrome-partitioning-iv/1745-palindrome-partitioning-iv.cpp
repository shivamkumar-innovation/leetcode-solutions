class Solution {
public:
bool c = false;
int z=0;
    int f(string& a, vector<vector<int>>& d, vector<vector<int>>& p, int i) {

        if (c)
            return 0;

        if (i == a.size()) {
            if (z == 3)
                c = true;
            return -1;
        }

        if (z > 3)
            return 0;

        if (d[i][z] != -1)
            return d[i][z];

        int l = INT_MAX;

        for (int k = i; k < a.size(); k++) {

            if (p[i][k]){
                z++;
                l = min(l, 1 + f(a, d, p, k + 1));
                z--;
            }
        }

        return d[i][z] = l;
    }

    bool checkPartitioning(string s) {

        int n = s.size();

        vector<vector<int>> p(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {

                if (s[i] == s[j]) {

                    if (j - i <= 1)
                        p[i][j] = 1;
                    else
                        p[i][j] = p[i + 1][j - 1];
                }
            }
        }

        vector<vector<int>> d(n, vector<int>(n,-1));

         f(s, d, p, 0);
         return c;
    }
};
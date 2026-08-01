class Solution {
public:
    vector<int> g;

    bool f(vector<vector<int>> &a, vector<int> &vi,
           vector<int> &var, vector<int> &safe, int i) {

        vi[i] = 1;
        var[i] = 1;

        bool x = 1;
        int j = 0;

        while (j < a[i].size()) {

            if (vi[a[i][j]] == 0) {
                x = f(a, vi, var, safe, a[i][j]);
            }
            else if (var[a[i][j]] == 1) {
                x = 0;
            }
            else if (safe[a[i][j]] == 0) {
                x = 0;
            }

            if (!x)
                break;

            j++;
        }

        var[i] = 0;

        if (x) {
            safe[i] = 1;
            g.push_back(i);
        }
        else {
            safe[i] = 0;
        }

        return x;
    }

    vector<int> eventualSafeNodes(vector<vector<int>> &a) {
        int n=a.size();
        vector<int> vi(n, 0);
        vector<int> var(n, 0);
        vector<int> safe(n, -1);

        int i = 0;

        while (i < n) {
            if (vi[i] == 0) {
                f(a, vi, var, safe, i);
            }
            i++;
        }

        sort(g.begin(), g.end());

        return g;
    }
};
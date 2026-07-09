class Solution {
public:
    int f(vector<int>& a, vector<int>& s, vector<vector<int>>& d, int i, int j) {
        if (j == -1 || i==-1) {
            return 0;
        }
        
        if (d[i][j] != -1)
            return d[i][j];
        int l = 0;
        if (a[i] == s[j]) {
            l =1+ f(a, s, d, i - 1, j - 1);
        } else {
            l = max({f(a, s, d, i, j - 1), f(a, s, d, i - 1, j)});
        }
        return d[i][j] = l;
    }
    int maxUncrossedLines(vector<int>& a, vector<int>& s) {
        vector<vector<int>> d(a.size(), vector<int>(s.size(), -1));
        return f(a, s, d, a.size() - 1, s.size() - 1);
       
    }
};
class Solution {
public:
    int f(string& a, string& s, vector<vector<int>>& d, int i, int j) {
        if (j == -1 && i==-1) {
            return 0;
        }
        if(j==-1){
            return i+1;
        }
        if(i==-1){
            return j+1;
        }
        if (d[i][j] != -1)
            return d[i][j];
        int l = 0;
        if (a[i] == s[j]) {
            l = f(a, s, d, i - 1, j - 1);
        } else {
            l = 1+min({f(a, s, d, i, j - 1), f(a, s, d, i - 1, j),f(a, s, d, i - 1, j - 1)});
        }
        return d[i][j] = l;
    }
    int minDistance(string a, string s) {
        if(a.size()==0 && s.size()==0 || a==s) return 0;
        vector<vector<int>> d(a.size(), vector<int>(s.size(), -1));
        return f(a, s, d, a.size() - 1, s.size() - 1);
       
    }
};
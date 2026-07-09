class Solution {
public:
    int f(string& a, string& s, vector<vector<int>>& d, int i, int j) {
        if (i == -1 || j == -1) {
            return 0;
        }
        if (d[i][j] != -1)
            return d[i][j];
        int l = 0;
        if (a[i] == s[j]) {
            l = 1 + f(a, s, d, i - 1, j - 1);
        } else {
            l = max(f(a, s, d, i, j - 1), f(a, s, d, i - 1, j));
        }
        return d[i][j] = l;
    }
    string shortestCommonSupersequence(string a, string s) {
        if (a == s)
            return s;
        vector<vector<int>> d(a.size(),vector<int>(s.size(),-1));
        f(a,s,d,a.size()-1,s.size()-1);

        vector<pair<int,int>> v;

        int i = a.size() - 1;
        int j = s.size() - 1;

        while (i >= 0 && j >= 0) {
            if (a[i] == s[j]) {
                v.push_back({i, j});
                i--;
                j--;
            } else {

                int up = (i > 0) ? d[i - 1][j] : 0;
                int left = (j > 0) ? d[i][j - 1] : 0;

                if (up >= left)
                    i--;
                else
                    j--;
            }
        }

         reverse(v.begin(), v.end());

        i = 0;
        j = 0;

        string b;

        int k = 0;

        while (k < v.size()) {

            while (i < v[k].first) {
                b += a[i];
                i++;
            }

            while (j < v[k].second) {
                b += s[j];
                j++;
            }

            b += a[i];   

            i++;
            j++;
            k++;
        }

        while (i < a.size()) {
            b += a[i];
            i++;
        }

        while (j < s.size()) {
            b += s[j];
            j++;
        }
        return b;
    }
};
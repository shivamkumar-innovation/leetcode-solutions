class Solution {
public:
    int f(string& a, vector<int>& d, int i) {
        if (i == a.size())
            return -1;

        if (d[i] != -1)
            return d[i];

        int l = INT_MAX;

        for (int k = i; k < a.size(); k++) {

            int x = i, y = k;
            bool b = 1;

            while (x < y) {
                if (a[x] != a[y]) {
                    b = 0;
                    break;
                }
                x++;
                y--;
            }

            if (b)
                l = min(l, 1 + f(a, d, k + 1));
        }

        return d[i] = l;
    }

    int minCut(string s) {
        vector<int> d(s.size(), -1);
        return f(s, d, 0);
    }
};
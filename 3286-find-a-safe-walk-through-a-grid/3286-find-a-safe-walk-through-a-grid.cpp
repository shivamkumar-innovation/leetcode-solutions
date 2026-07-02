class Solution {
public:
    bool b = false;

    void f(vector<vector<int>>& a, vector<vector<unordered_set<int>>>& d, int i,int j, int h) {
        // if(b) return ;
        // if(h==0){
        //     return;
        // }
        if (i == -1 || j == -1 || i == a.size() || j == a[0].size() || h == 0 || b)
            return;
        if (d[i][j].count(h))
            return;
        d[i][j].insert(h);
        if (i == 0 && j == 0) {
            if (a[0][0] == 1 && h == 1) {
                return;
            } else {
                b = true;
                return;
            }
        }
        // if(d[i][j]) return ;
        int e = h;
        if (a[i][j] == 1) {
            e = h - 1;
        }

            f(a, d, i - 1, j, e);
            f(a, d, i, j - 1, e);
            f(a, d, i + 1, j, e);
            f(a, d, i, j + 1, e);
    
        
        return;
    }
    bool findSafeWalk(vector<vector<int>>& a, int h) {
        vector<vector<unordered_set<int>>> v(a.size(), vector<unordered_set<int>>(a[0].size()));
        f(a, v, a.size()-1, a[0].size()-1, h);
        return b;
    }
};
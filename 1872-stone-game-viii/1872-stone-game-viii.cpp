class Solution {
public:
    int stoneGameVIII(vector<int>& v) {

        int n = v.size();

        for(int i=1; i<n; i++){
            v[i] += v[i-1];
        }

        int x = v[n - 1];
        int i = n - 2;
        while (i >= 1) {
            x = max(x, v[i] - x);
            i--;
        }

        return x;
    }
};
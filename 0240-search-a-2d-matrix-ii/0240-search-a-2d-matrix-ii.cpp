class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int t) {
        int i = 0;
        int j = v[0].size() - 1;

        while (i < v.size() && j >= 0) {
            if (v[i][j] == t)
                return true;

            if (v[i][j] > t)
                j--;
            else
                i++;
        }

        return false;
    }
};
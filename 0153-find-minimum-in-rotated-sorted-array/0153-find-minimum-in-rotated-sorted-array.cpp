class Solution {
public:
    int findMin(vector<int>& n) {
        int l = 0;
        int r = n.size() - 1;

        while (l < r) {
            int m = l + (r - l) / 2;

            if (n[m] > n[r])
                l = m + 1;
            else
                r = m;
        }

        return n[l];
    }
};
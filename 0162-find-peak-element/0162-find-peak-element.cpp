class Solution {
public:
    int findPeakElement(vector<int>& n) {
        int l = 0;
        int r = n.size() - 1;

        while (l < r) {
            int m = l + (r - l) / 2;

            if (n[m] > n[m+1])
                r = m;
            else
                l = m+1 ;
        }

        return l;

    }
};
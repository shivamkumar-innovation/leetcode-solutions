class Solution {
public:
    int searchInsert(vector<int>& n, int t) {
        int l = 0;
        int r = n.size() - 1;

        while (l <= r) {
            int mid = (r + l) / 2;
            if (n[mid] == t) {
                return mid;
            }

            else if (n[mid] < t) {
                l = mid + 1;
            }

            else {
                r = mid - 1;
            }
        }

        return l;
    }
};
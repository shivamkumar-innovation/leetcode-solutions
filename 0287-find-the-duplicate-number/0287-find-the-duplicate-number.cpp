class Solution {
public:
    int findDuplicate(vector<int>& n) {
        int i = 0;

        while (i < n.size()) {
            if (i + 1 == n[i]) {
                i++;
                continue;
            }
            else if (n[i] == n[n[i] - 1]) {
                return n[i];
            }

            swap(n[i], n[n[i] - 1]);
        }

        return 0;
    }
};
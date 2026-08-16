class Solution {
public:
    vector<int> v;

    Solution(vector<int>& w) {
        int sum = 0;

        for (int x : w) {
            sum += x;
            v.push_back(sum);
        }
    }

    int pickIndex() {
        int x = rand() % v.back() + 1;

        int l = 0;
        int r = v.size() - 1;

        while (l < r) {
            int m = l + (r - l) / 2;

            if (v[m] >= x)
                r = m;
            else
                l = m + 1;
        }

        return l;
    }
};
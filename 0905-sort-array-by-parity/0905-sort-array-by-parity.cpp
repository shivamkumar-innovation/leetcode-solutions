class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& v) {
        int x = 0;
        int i = 0;
        while (i < v.size()) {
            if (v[i] % 2 != 0) {
                x = i;
                break;
            }
            i++;
        }

        while (i < v.size()) {
            if (v[i] % 2 == 0) {
                if (v[x] & 1) {
                    swap(v[x], v[i]);
                    x++;
                }
            }
            i++;
        }
        return v;
    }
};
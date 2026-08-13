class Solution {
public:

    int f(vector<int>& v, int k) {
        if (k == 0)
            return 0;

        unordered_map<int, int> m;

        int i = 0;
        int ans = 0;

        for (int j = 0; j < v.size(); j++) {

            m[v[j]]++;

            while (m.size() > k) {
                m[v[i]]--;

                if (m[v[i]] == 0)
                    m.erase(v[i]);

                i++;
            }

            ans += j - i + 1;
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int>& v, int k) {
        return f(v, k) - f(v, k - 1);
    }
};
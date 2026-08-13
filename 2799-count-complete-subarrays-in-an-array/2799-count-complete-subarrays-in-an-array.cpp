class Solution {
public:
    int f(vector<int>& v, int k) {
        if (k == 0)
            return 0;

        unordered_map<int, int> m;

        int i = 0;
        int j = 0;
        int ans = 0;

        while (j < v.size()) {
            m[v[j]]++;

            while (m.size() > k) {
                m[v[i]]--;

                if (m[v[i]] == 0)
                    m.erase(v[i]);

                i++;
            }

            ans = ans + j - i + 1;
            j++;
        }

        return ans;
    }

    int countCompleteSubarrays(vector<int>& v) {
        unordered_set<int> s;

        for (int x : v)
            s.insert(x);

        int k = s.size();

        return f(v, k) - f(v, k - 1);
    }
};
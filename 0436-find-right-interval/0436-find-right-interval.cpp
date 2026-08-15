class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& v) {
        int n = v.size();

        vector<pair<int, int>> a;

        for (int i = 0; i < n; i++)
            a.push_back({v[i][0], i});

        sort(a.begin(), a.end());

        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {
            int l = 0;
            int r = n - 1;

            while (l <= r) {
                int mid = l + (r - l) / 2;

                if (a[mid].first < v[i][1])
                    l = mid + 1;
                else
                    r = mid - 1;
            }

            if (l < n)
                ans[i] = a[l].second;
        }

        return ans;
    }
};
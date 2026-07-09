class Solution {
public:
    string frequencySort(string a) {
        vector<pair<int, char>> v(62, make_pair(0, 'a'));
        int i = 0;
        while (i < a.size()) {
            if (a[i] >= 97) {
                v[a[i] - 'a'].first++;
                v[a[i] - 'a'].second = a[i];
            } 
            else if (a[i] >= 'A' && a[i] <= 'Z') {
                v[a[i] - 'A' + 26].first++;
                v[a[i] - 'A' + 26].second = a[i];
            } 
            else {
                v[a[i] - '0' + 52].first++;
                v[a[i] - '0' + 52].second = a[i];
            }
            i++;
        }

        sort(v.begin(), v.end(), greater<pair<int, char>>());

        i = 0;
        int x = 0;
        while (i < v.size()) {
            int j = 0;
            char c = v[i].second;
            while (j < v[i].first) {
                a[x] = c;
                x++;
                j++;
            }
            i++;
        }

        return a;
    }
};
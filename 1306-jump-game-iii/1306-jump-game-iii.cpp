class Solution {
public:
    bool b = 0;
    unordered_set<int> m;
    void f(vector<int>&a, int i) {
        if (b) return;
        if (m.find(i) != m.end()) {
            return;
        }
        if (a[i] == 0) {
            b = 1;
            return;
        }
        m.insert(i);
        if(i + a[i] < a.size())
        f(a,i+a[i]);
        if(i - a[i] >=0)
        //\m.erase(i);
        f(a,i-a[i]);
        m.erase(i);

        return;
    }
    bool canReach(vector<int>& a, int s) {
        if (a[s] == 0)
            return 1;
            f(a,s);
        // unordered_map<int, int> m;
        // int i = 0;
        // while (i < a.size()) {
        //     if (i + a[i] < a.size()) {
        //         if (0 == a[i + a[i]]) {
        //             m[i];
        //             // a[i] = -1;
        //         }
        //         // a[i]=-1;
        //     }
        //     if (i - a[i] > -1) {
        //         if (0 == a[i - a[i]]) {
        //             m[i];
        //             // a[i] = -1;
        //         }
        //         // a[i]=-1
        //     }
        //     i++;
        // }
        // i = 0;
        // if (m.size() == 0)
        //     return 0;
        // while (i < a.size()) {
        //     if (a[i] != -1) {
        //         if (m.find(i + a[i]) != m.end()) {
        //             m[i];
        //             // a[i] = -1;
        //         }
        //         if (m.find(i - a[i]) != m.end()) {
        //             m[i];
        //             // a[i] = -1;
        //         }
        //     }
        //     i++;
        // }
        // i--;
        // while (i >= 0) {
        //     if (a[i] != -1) {
        //         if (m.find(i + a[i]) != m.end()) {
        //             m[i];
        //             // a[i] = -1;
        //         }
        //         if (m.find(i - a[i]) != m.end()) {
        //             m[i];
        //             // a[i] = -1;
        //         }
        //     }
        //     i--;
        // }
        // if (s + a[s] < a.size()) {
        //     if (m.find(s + a[s]) != m.end()) {
        //         return 1;
        //     }
        // }
        // if (s - a[s] >= 0) {
        //     if (m.find(s - a[s]) != m.end()) {
        //         return 1;
        //     }
        // }

        return b;
    }
};
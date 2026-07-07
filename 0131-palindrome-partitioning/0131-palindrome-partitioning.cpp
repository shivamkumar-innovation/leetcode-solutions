// class Solution {
// public:
//     vector<vector<string>> partition(string s) {
//         vector<vector<string>>v;
//         return v;
//     }
// };

class Solution {
public: 
vector<string>v;
    void f(string& a, vector<vector<string>>&d, int i) {
        if (i == a.size())
            d.push_back(v);

        int l = INT_MAX;

        for (int k = i; k < a.size(); k++) {

            int x = i, y = k;
            bool b = 1;

            while (x < y) {
                if (a[x] != a[y]) {
                    b = 0;
                    break;
                }
                x++;
                y--;
            }

            if (b){
                v.push_back(a.substr(i, k - i + 1));
                 f(a, d, k + 1);
                 v.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>d;
         f(s, d, 0);
         return d;
    }
};
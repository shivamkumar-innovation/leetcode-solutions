// class Solution {
// public:
//     int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
//     }
// };

class Solution {
public:
    int f(vector<int>& a, vector<int>& d, int i,int x) {
        if (i == a.size())
            return 0;

        if (d[i] != -1)
            return d[i];

        int l = 0;
        int k=i;
        int m=0;
        while (k<i+x && k < a.size()) {
            m=max(m,a[k]);
                l = max(l, m*(k-i+1) + f(a, d, k + 1,x));
                k++;
        }

        return d[i] = l;
    }

    int maxSumAfterPartitioning(vector<int>& a, int k) {
        vector<int> d(a.size(), -1);
        return f(a, d, 0,k);
    }
};


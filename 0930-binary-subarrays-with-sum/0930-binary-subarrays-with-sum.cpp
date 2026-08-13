class Solution {
public:
int f(vector<int>& v, int k) {
    if(k==-1) return 0;
        int i = 0;
        int ans = 0;
        int s=0;
        for (int j = 0; j < v.size(); j++) {

            s=s+v[j];

            while ( s > k) {
                s=s-v[i];
                i++;
            }

            ans += j - i + 1;
        }

        return ans;
    }

    int numSubarraysWithSum(vector<int>& v, int k) {
        return f(v,k)-f(v,k-1);
    }
};
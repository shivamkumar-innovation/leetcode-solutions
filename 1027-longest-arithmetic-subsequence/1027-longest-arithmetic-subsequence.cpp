class Solution {
public:
    vector<unordered_map<int, int>> d;

    long long f(vector<int>&a, int i, int j,int diff) {
        // if (dp[i].count(diff))
        //     return dp[i][diff];

        long long ans = 0;
        if(d[j].count(diff)==0){
            ans=2;
           
        }
        else{
            ans=1+d[j][diff];
        }

        // if(i!=0){

        // }

        // for (int j = i-1; j >- 0; j--) {

        //     if (1LL * a[i] - a[j] == diff) {

        //         ans = max(ans,1+ f(j, diff));
        //     }
        // }

        return d[i][diff] = ans;
    }

    int longestArithSeqLength(vector<int>& a) {


        int n = a.size();
        if (n == 1)
            return n;
        d.assign(n, {});

        long long ans = 0;

        for (int i = 0; i < n; i++) {

            unordered_set<long long> s;

            for (int j = i-1; j>=0; j--) {

                int diff = a[i] - a[j];

                if (s.insert(diff).second)
                    ans = max(ans, f(a,i, j, diff));
            }
        }

        return ans;
    }
};
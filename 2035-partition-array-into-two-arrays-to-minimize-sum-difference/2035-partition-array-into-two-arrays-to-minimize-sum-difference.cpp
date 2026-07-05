// class Solution {
// public:
// int k=INT_MAX;
// void f(vector<int>& a,int s,int t,int i,int x,int y){
//         if(x==y && x==a.size()/2){
//             k=min(k,abs(s-t));
//             return ;
//         }
//     if(x<a.size()/2){
//         f(a,s-a[i],t+a[i],i+1,x+1,y);
//     }
//     if(y<a.size()/2){
//         f(a,s,t,i+1,x,y+1);
//     }
// }
//     int minimumDifference(vector<int>& a) {
//         int s=accumulate(a.begin(),a.end(),0);
//         f(a,s,0,0,0,0);
//         return k;
//     }
// };

//extremely tough to do this question.
//initially, i had solved the question but with O(2^(2n)) time complexity but that is not acceptable(TLE) for this problem .
// so i took help from gpt and optimal time is O(n*2^n) 
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        int total = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> left(n + 1), right(n + 1);

        for (int mask = 0; mask < (1 << n); mask++) {
            int cnt = 0;
            int sumL = 0, sumR = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    cnt++;
                    sumL += nums[i];
                    sumR += nums[i + n];
                }
            }

            left[cnt].push_back(sumL);
            right[cnt].push_back(sumR);
        }

        for (int i = 0; i <= n; i++)
            sort(right[i].begin(), right[i].end());

        int ans = INT_MAX;

        for (int cntL = 0; cntL <= n; cntL++) {
            int cntR = n - cntL;

            for (int sumL : left[cntL]) {

                int target = total / 2 - sumL;

                auto it = lower_bound(right[cntR].begin(),
                                      right[cntR].end(),
                                      target);

                if (it != right[cntR].end()) {
                    int chosen = sumL + *it;
                    ans = min(ans, abs(total - 2 * chosen));
                }

                if (it != right[cntR].begin()) {
                    --it;
                    int chosen = sumL + *it;
                    ans = min(ans, abs(total - 2 * chosen));
                }
            }
        }

        return ans;
    }
};
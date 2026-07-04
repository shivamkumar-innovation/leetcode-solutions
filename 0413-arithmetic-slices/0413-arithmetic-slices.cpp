
class Solution {
public:
    vector<unordered_map<long long, long long>> d;

    long long f(vector<int>&a, int i, int j,long long diff) {

         long long ans = 0;
        if(d[j].count(diff)==0){
            ans=2;
           
        }
        else{
            ans=1+d[j][diff];
        }

        return d[i][diff] = ans;
    }

    int numberOfArithmeticSlices(vector<int>& a) {


        int n = a.size();
     
        d.assign(n, {});

        long long ans = 0;

        for (int i = 1; i < n; i++) {

                long long diff = a[i] - a[i-1];
                int p=f(a,i,i-1,diff);
                if(p>=3)
                    ans = ans+p-2;
            }
        

        return ans;
    }
};

class Solution {
    public:
    

    int f(vector<int>&d, int i, int j) {
    
        int ans = 0;        
            ans=1+d[j];
        
        d[i]=max(ans,d[i]);
        return d[i] ;
    }
    int lengthOfLIS(vector<int>& a) {
        vector<int> d(a.size(),1);
        int n=a.size();
        int ans = 1;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j<i; j++) {
                if(a[j]<a[i])
                    ans = max(ans, f(d,i,j));
            }
        }

        return ans;
    }
};
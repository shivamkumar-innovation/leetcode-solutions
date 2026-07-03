class Solution {
  public:
 	bool h(vector<int>& a, vector<vector<int>>& d, int n, int t) {
		if (t == 0) {
			return 1;
		}
		
		if (n >= a.size() || t < 0)
			return 0;
			if(d[n][t]!=-1){
			    return d[n][t];
			}
		bool l= h(a, d,n + 1, t - a[n]);
		bool r =h(a, d,n + 1, t);
		
		return d[n][t] = l || r;;
	}
    bool canPartition(vector<int>& a) {
        // code here
       
        int t=accumulate(a.begin(),a.end(),0);
         if(t%2!=0) return 0;
        vector<vector<int>>d(a.size(),vector<int>(t/2+1,-1));
        return h(a, d, 0, t/2) ;
        
    }
};
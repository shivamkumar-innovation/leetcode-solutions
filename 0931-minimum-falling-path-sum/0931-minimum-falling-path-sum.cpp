class Solution {
  public:
  int f(vector<vector<int>>& a, vector<vector<int>>& d, int i,int l){
    if(l==-1 || l==a.size()){
        return INT_MAX;
    }
      if(a.size()==i){
          return 0;
      }
      if(d[i][l]!=-1000000){
          return d[i][l];
      }
      long long r=INT_MAX;
          r=f(a,d,i+1,l)+1LL*a[i][l];
      
      long long fi=INT_MAX;
      
          fi=f(a,d,i+1,l-1)+1LL*a[i][l];
    
      long long le=INT_MAX;
    
          le=f(a,d,i+1,l+1)+1LL*a[i][l];
    
    //   d[i][l]=max(le,max(r,fi));
      return d[i][l]=(int)min(le,min(r,fi));
  }
  
    int minFallingPathSum(vector<vector<int>>& a) {
        if(a.size()==1) return a[0][0];
        vector<vector<int>>v(a.size(), vector<int>(a.size(), -1000000));
        int i=0;
        int m=INT_MAX;
        while(i<a.size()){
            m=min(f(a,v,0,i),m);
            i++;
        }
        return m;
        //return max(f(a,d,0,0),max(f(a,d,0,1),f(a,d,0,2))
    }
};
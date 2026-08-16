class Solution {
public:
    char nextGreatestLetter(vector<char>& a, char t) {
        int i=0;
      int j=a.size()-1;

      int mid=(i+j)/2;
      int x=a[j];
      while(i<=j){
          mid=(i+j)/2;
          if(a[mid]<=t){
              i=mid+1;
          }
          else{
              j=mid-1;
          }
      }
      if(i>=a.size()) return a[0];
      return a[i];
    }
};
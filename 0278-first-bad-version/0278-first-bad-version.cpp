// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l=1;
        int r=n;
        while(l<r){
            int m=(r-l)/2+l;
            bool b=isBadVersion(m);
            if(!b){
                l=m+1;
            }
            else{
                r=m;
            }
        }
        return l;
    }
};
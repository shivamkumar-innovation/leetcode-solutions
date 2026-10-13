class Solution {
public:
    int trailingZeroes(int n) {
        int x=5;
        int s=0;
        while(x<=n){
            s+=n/x;
            x*=5;
        }
        return s;
    }
};
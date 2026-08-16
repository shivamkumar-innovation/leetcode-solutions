class Solution {
public:
    int arrangeCoins(int n) {
        return (sqrt(1+1LL*4*2*n)-1)/2;
    }
};
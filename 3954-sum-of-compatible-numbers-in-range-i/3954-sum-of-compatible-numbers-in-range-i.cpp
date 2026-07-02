class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int i = n - k;
        if(i<1){
            i=1;
        }
        int s = 0;
        while (i <= n + k) {
            if(!(i & n)){
                s=s+i;
            }
            i++;
        }
        return s;
    }
};
class Solution {
public:
    int integerBreak(int n) {
        if(2==n) return 1;
        int x=1;
        if(n==3) return 2;
        // int y=n%3;
        // if(y==0){
        //     return pow(3,n/3);
        // }
        // else{

        // }
        while(n-3>=0){
            x*=3;
            n=n-3;
        }
        if(n%3==1 ){
            x=x/3;
            x=x*4;
        }
        else if(n%3==2){
            x=x*n;
        }
        return x;
    }
};
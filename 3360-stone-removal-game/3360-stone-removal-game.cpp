class Solution {
public:
    bool canAliceWin(int n) {
        bool b=0;

        int x=10;
        while(n>0){
            n-=x;
            x--;
            b=!b;
        }
        if(n<0){
            return !b;
        }
        return b;
    }
};
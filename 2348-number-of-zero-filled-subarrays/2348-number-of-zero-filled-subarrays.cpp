class Solution {
public:
    long long zeroFilledSubarray(vector<int>& a) {
        int i=0;
        long long s=0;
        while(i<a.size()){
            if(a[i]==0){
                int j=i;
                while(i<a.size() && a[i]==0){
                    i++;
                }
                long long x=i-j;
                s=s+x*(x+1)/2;
            }
            else{
                i++;
            }
        }
        return s;
    }
};
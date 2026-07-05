class Solution {
public:
    int findLengthOfLCIS(vector<int>& a) {
        int i=1;
        int k=1;
        int x=1;
        while(i<a.size()){
            if(a[i]<=a[i-1]) x=1;
            else{
                x++;
                k=max(k,x);
            }
            i++;
        }
        return k;
    }
};
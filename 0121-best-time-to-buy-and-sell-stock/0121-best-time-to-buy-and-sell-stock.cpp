class Solution {
public:
    int maxProfit(vector<int>& a) {
        int i=0;
        int x=a[0];
        //int y=a[0];
        int k=0;
        while(i<a.size()){
            x=min(x,a[i]);
            if(x<=a[i]){
                k=max(k,a[i]-x);
            }
            i++;
        }
        return k;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& a) {
        int m=a[0];
        int i=0;
        int s=0;
        while(i<a.size()){
            if(a[i]>m){
                s=s+a[i]-m;
                m=a[i];
            }
            else{
                m=min(m,a[i]);
            }
            i++;
        }
        return s;
    }
};
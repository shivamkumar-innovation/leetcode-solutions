class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int ma=INT_MIN;
        int i=0;
        int s=0;
        while(i<a.size()){
            int s=s+a[i];
            ma=max(ma,s);
            if(s<0){
                s=0;
            }
            i++;
        }
        return ma;
    }
};
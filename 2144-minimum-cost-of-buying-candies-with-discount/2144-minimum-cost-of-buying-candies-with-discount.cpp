class Solution {
public:
    int minimumCost(vector<int>& a) {
        sort(a.begin(),a.end());
        int k=1;
        int s=0;
        int i=a.size()-1;
        while(i>=0){
            if(k==3){
                k=1;
            }
            else{
                k++;
                s+=a[i];
            }
            i--;
        }
        return s;
    }
};
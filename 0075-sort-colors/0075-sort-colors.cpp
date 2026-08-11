class Solution {
public:
    void sortColors(vector<int>& n) {
        int i=0;
        int x=0;
        int l=n.size()-1;
        while(i<=l){
            if(n[i]==0){
                swap(n[x],n[i]);
                x++;
                i++;
            }
            else if(n[i]==1){
                i++;
            }
            else{
                swap(n[i],n[l]);
                l--;
            }
        }
    }
};
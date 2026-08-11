class Solution {
public:
    int longestOnes(vector<int>& n, int k) {
        int i=0;
        int ans=0;
        int j=0;
        if(k==0){
            while(j<n.size()){
                if(n[j]){
                    ans=max(ans,j-i+1);
                }
                else{
                    i=j+1;
                }
                j++;
            }
        }
        while(j<n.size()){
            if(n[j]==0 && k==0){
                while(i<=j){
                    if(n[i]==0){
                        i++;
                        break;
                    }
                    i++;
                }
            }
            else if(n[j]){
                ans=max(ans,j-i+1);
            }
            else {
                k--;
                ans=max(ans,j-i+1);
            }
            j++;
        }
        return ans;
    }
};
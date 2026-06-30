

class Solution {
public:
    int alternatingSubarray(vector<int>& a) {
       // if(a.size()==1) return 1;
       
       int v=-1;
       int i=1;
       while(i<a.size()){
        int k=1;
        if(a[i]-a[i-1]==1){
        while(i<a.size()-1 && (a[i]-a[i-1]==a[i]-a[i+1] && abs(a[i]-a[i-1])==1)){
            i++;
            k++;
        }
        k++;
        }
        // if(a[i]-a[i-1]==1){
        //     k++;
        // }
        i++;
        if(k>1)
        v=max(k,v);
       }
        return v;
    }
};
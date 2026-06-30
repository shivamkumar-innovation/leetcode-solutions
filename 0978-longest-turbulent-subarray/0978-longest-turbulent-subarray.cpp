class Solution {
public:
    int maxTurbulenceSize(vector<int>& a) {
       // if(a.size()==1) return 1;
       
       int v=1;
       int i=1;
       while(i<a.size()){
        int k=1;
        while(i<a.size()-1 && (a[i-1]>a[i] && a[i]<a[i+1] || a[i-1]<a[i] && a[i]>a[i+1])){
            i++;
            k++;
        }
        if(a[i-1]>a[i] || a[i-1]<a[i]){
            k++;
        }
        i++;
        v=max(k,v);
       }
        return v;
    }
};
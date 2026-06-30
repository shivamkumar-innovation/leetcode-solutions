class Solution {
public:

    int jump(vector<int>& a) {
        vector<int>v;
       if(a.size()==1) return 0;
        int i=1;
        int k=1;
        int x=0;
        int m=a[0];
        v.push_back(0);
        while(i<a.size()){
            // if(m<=a[i]){
            //     v.push_back({a[i],i});
            //     m=a[i];
            // }
            if(x+m>=a.size()-1){
                break;
            }
            if(x+m<i+a[i]){
                //k++;
                v.push_back(i);
                m=a[i];
                x=i;
            }
            // else{
            //     v.push_back(v.back().first,v.back().second)
            // }
            i++;
        }
        i=1;
        if(v.size()==1) return 1;
        x=v[0];
        while(i<v.size()){
            if(a[v[x]]+v[x]>=a.size()-1) return k;
            if(a[v[x]]+v[x]==v[i]){
                k++;
                 x=i;
            }
            else if(a[v[x]]+v[x]<v[i]){
             x=i-1;
             k++;
            }
            i++;
        }
        if(a[v[x]]+v[x]>=a.size()-1) return k;
        k++;
        // return f(a,d,)
        return k;
    }
};
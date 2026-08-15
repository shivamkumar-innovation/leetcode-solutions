class Solution {
public:
int f(vector<int>& v, int x,int l,int r){
    while(l<r){
        int m=l+(r-l)/2;
        if(v[m]==x){
            r=m;
        }
        else{
            l=m+1;
        }
    }
    return l;
}
int h(vector<int>& v, int x,int l,int r){
    while(l<r){
        int m=l+(r-l+1)/2;
        if(v[m]==x){
            l=m;
        }
        else{
            r=m-1;
        }
    }
    return r;
}
    vector<int> searchRange(vector<int>& v, int x) {
        int l=0;
        int r=v.size()-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(v[m]==x){
                return {f(v,x,l,m),h(v,x,m,r)};
            }
            else if(v[m]>x){
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return{-1,-1};
    }
};
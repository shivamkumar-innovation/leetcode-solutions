class Solution {
public:
    int candy(vector<int>& a) {
        if(a.size()==1) return 1;
        vector<pair<int,int>>v;
        vector<int>n(a.size(),0);
        int i=0;
        while(i<a.size()){
            v.push_back({a[i],i});
            i++;
        }
        sort(v.begin(),v.end());
        i=0;
        while(i<v.size()){
            int x=v[i].first;
            int y=v[i].second;
            if(y-1>=0 && y+1<a.size()){
                if(x<=a[y-1] && x<=a[y+1]){
                    n[y]=1;
                }
                else if(x>a[y-1] && x>a[y+1]){
                    n[y]=max(n[y-1],n[y+1])+1;
                }
                else if(x>a[y-1] && x<=a[y+1]){
                    n[y]=n[y-1]+1;
                }
                else if(x<=a[y-1] && x>a[y+1]){
                    n[y]=n[y+1]+1;
                }
                //else if(x>a[y-1] && x<a[y+1])
            }
            else if(y-1>=0){
                if(x<=a[y-1]){
                    n[y]=1;
                }
                else if(x>a[y-1]){
                    n[y]=n[y-1]+1;
                }
            }
            else{
                if(x<=a[y+1]){
                    n[y]=1;
                }
                else if(x>a[y+1]){
                    n[y]=n[y+1]+1;
                }
            }
            i++;
        }
        i=0;
        int s=0;
        while(i<n.size()){
            s+=n[i];
            i++;
        }

        return s;
    }
};
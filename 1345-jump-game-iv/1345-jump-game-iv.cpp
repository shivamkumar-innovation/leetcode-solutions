class Solution {
public:
    int minJumps(vector<int>& a) {
        if(a.size()==1) return 0;
        // if i-1 ele has copy at i< then only go pre otherwise first check its own copy then go to i-1 check and then go on i+1 but first check whether is visite or not for both i-1 and i+1 also check if n-1 then store in the beggining and do not check if i+1==n-1 
        vector<int >v(a.size(),-1);
        unordered_map<int,vector<int>>m;
        int i=0;
        while(i<a.size()){
            m[a[i]].push_back(i);
            i++;
        }
        int n=INT_MAX;
        queue<pair<int,int>>q;
        q.push({0,0});
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();

            if(x==a.size()-1){
                n=min(n,y);
                continue;
            }

            auto it=m.find(a[x]);
            int j=0;

            if(it!=m.end()){
            while(j<it->second.size()){
                q.push({it->second[j],y+1});
                v[it->second[j]]=1;
                j++;
            }
            m.erase(it);
            }
            
            if(x>0 && v[x-1]!=1){
                v[x-1]=1;
                q.push({x-1,y+1});
            }
            if(x+1==a.size()-1){
                q.push({x+1,y+1});
            }
            else if(v[x+1]!=1){
                 q.push({x+1,y+1});
                 v[x+1]=1;
            }
        }
        return n;
    }
};
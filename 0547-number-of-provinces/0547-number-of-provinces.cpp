class Solution {
public:
    int findCircleNum(vector<vector<int>>& v) {
        queue<int>q;
        int i=0;
        vector<int>a(v.size());
        int t=0;
        while(i<a.size()){
            t++;
            a[i]=1;
            q.push(i);
            while(!q.empty()){
                int b=q.front();
                q.pop();
                // a[b]=1;
                int j=0;
                while(j<v.size()){
                    if(v[b][j]==1 && !a[j]){
                        a[j]=1;
                        q.push(j);
                    }
                    j++;
                }
            }
            while(i<v.size() && a[i]!=0){
                i++;
            }
        }
        return t;
    }
};


class Solution {
public:
    int maxResult(vector<int>& a, int k) {
        int i=a.size()-1;
        int s=a[i];
        priority_queue<pair<long long,int>>p;
        p.push({a[i],i});
        i--;
        //int ;
        while(i>=0){
            while(!p.empty() && i<p.top().second-k){
                p.pop();
            }
            long long z=p.top().first+a[i];
            if(i==0){
                s=z;
            }
            p.push({z,i});
            i--;
        }
        return s;
    }
};
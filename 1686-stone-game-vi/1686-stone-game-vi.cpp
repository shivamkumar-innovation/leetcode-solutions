class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        int n = a.size();

        priority_queue<pair<int,int>> q;

        for(int i=0; i<n; i++){
            q.push({a[i]+b[i], i});
        }

        int x=0;
        int y=0;

        for(int i=0; i<n; i++){
            int j=q.top().second;
            q.pop();

            if(i%2==0)
                x += a[j];
            else
                y += b[j];
        }

        if(x>y)
            return 1;
        if(x<y)
            return -1;

        return 0;
    }
};
class Solution {
public:
    vector<int> successfulPairs(vector<int>& a, vector<int>& b, long long t) {
        sort(b.begin(),b.end());
        vector<int >v;
        int i=0;
        while(i<a.size()){
            int l=0;
            int r=b.size()-1;
            while(l<=r){
                int m=l+(r-l)/2;
                if(1LL*b[m]*a[i]<t){
                    l=m+1;
                }
                else {
                    r=m-1;
                }
            }
            i++;
            v.push_back(b.size()-l);
        }
        return v;

    }
};
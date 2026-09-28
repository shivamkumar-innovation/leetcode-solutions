class Solution {
public:
    int kthFactor(int n, int k) {
        int x=sqrt(n);
        int i=1;
        vector<int>v;
        while(i<=x){
            if(n%i==0){
                if(n/i!=i){
                    v.push_back(i);
                    v.push_back(n/i);
                }
                else{
                    v.push_back(i);
                }
            }
            i++;
        }
        sort(v.begin(),v.end());
        return v.size()<k?-1:v[k-1];
    }
};
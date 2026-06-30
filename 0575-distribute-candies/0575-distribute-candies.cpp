class Solution {
public:
    int distributeCandies(vector<int>& a) {
        unordered_set<int>m;
        int i=0;
        while(i<a.size()){
           m.insert(a[i]);
           i++;
        }
        return min(a.size()/2,m.size());
    }
};
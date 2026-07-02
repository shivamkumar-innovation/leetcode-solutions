class Solution {
public:
int s=0;
void f(vector<int>& a,int i,int x){
    if(i==a.size()){
        s=s+x;
        return;
    }
    // x=x^a[i];
    f(a,i+1,x^a[i]);
    f(a,i+1,x);
}
    int subsetXORSum(vector<int>& a) {
        f(a,0,0);
        return s;
    }
};
class Solution {
public:
vector<string>v;
void f(int i, int j, string s){
    if(i==0 && j==0){
        v.push_back(s);
    }
    if(i>0){
        f(i-1,j,s+'(');
    }
    if(j>0 && i<j){
        f(i,j-1,s+')');
    }
}
    vector<string> generateParenthesis(int n) {
        f(n,n,"");
        return v;
    }
};
class Solution {
public:
int m=0;
void f(vector<int>& a,int i ){
        if (i >= a.size()) {
            return;
        }
        if(i==a.size()-2){
            m=max(m,a[i+1]-a[i]);
            return ;
        }
        if(i+2<a.size()){
        m=max(m,a[i+2]-a[i]);
        f(a,i+2);
        }
        return ;
}
    // void f(vector<int>& a, int c, int i) {
    //     if (i >= a.size() - 1) {
    //         return;
    //     }
    //     if (c == 0) {
    //         if (i - 1 >= 0) {
    //             m = max(m, abs(a[i] - a[i - 1]));
    //             f(a, c + 1, i + 2);
    //         } else
    //             f(a, c, i + 1);
    //     } 
    //     else {
    //         if (i - 2 >= 0) {
    //             m = max(m, abs(a[i] - a[i - 2]));
    //         }
    //     }
    //     // if(i-2>=0){
    //     //     m=max(m,abs(a[i]-a[i-2]));
    //     // }
    //     f(a, c, i + 2);
    // }
    int maxJump(vector<int>& a) {
        if(a.size()==2 || a.size()==3){
            return a[a.size()-1]-a[0];
        }
        //if(a.size() & 1){
        f(a,0);
        f(a,1);
            m=max(m,a[1]-a[0]);
        //}
        return m;
    }
};
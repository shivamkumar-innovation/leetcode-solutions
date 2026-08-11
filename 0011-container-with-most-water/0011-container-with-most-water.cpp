class Solution {
public:
    int maxArea(vector<int>& v) {
       int i=0;
       int j=v.size()-1;
       int s=0;
       while(i<j){
        s=max(s,(j-i)*min(v[i],v[j]));
        if(v[i]>v[j]){
            j--;
        }
        else{
            i++;
        }
       }
        return s;
    }
};





































//  int a=0;
//         int i=0;
//         int j=h.size()-1;
//         while(i<j){
//             a=max(a,min(h[i],h[j])*(j-i));
//             if(h[i]<h[j]){
//                 i++;
//             }
//             else{
//                 j--;
//             }
        // }
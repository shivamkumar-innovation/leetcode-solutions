// class Solution {
// public:
// int f(vector<int> &a,vector<vector<int>> &d,int i, int j){
//       if(i==j) return a[i];
//       if(d[i][j]!=-1) return d[i][j];
//       int l=0;
//       int k=i;
//       while(k<=j){
//         int x=0;
//         if(k==0){
//             x=1*a[k]*a[k+1];
//         }
//         else if(k=a.size()-1){
//             x=a[k-1]*a[k]*1;
//         }
//         else{
//             x=a[k-1]*a[k]*a[j].
//         }
//           l=max(l,x+f(a,d,k+1,j));
//           k++;
//       }
//       return d[i][j]=l;
// }
//     int maxCoins(vector<int>& a) {
//          vector<vector<int>>d(a.size(),vector<int>(a.size(),-1));
//         return f(a,d,0,a.size()-1);
//     }
// };

class Solution {
public:
    int f(vector<int>& a, vector<vector<int>>& d, int i, int j) {
        if (i > j)
            return 0;
        if (d[i][j] != -1)
            return d[i][j];
        int l = 0;
        int k = i;
        while (k <= j) {
            int x = 0;
            if (i == 0 && j == a.size() - 1) {
                x = 1 * a[k] * 1;
            } else if (i == 0) {
                x = 1 * a[k] * a[j + 1];
            } else if (j == a.size() - 1) {
                x = a[i - 1] * a[k] * 1;
            } else {
                x = a[i - 1] * a[k] * a[j + 1];
            }

            l = max(l, x + f(a, d, i, k - 1) + f(a, d, k + 1, j));
            k++;
        }
        return d[i][j] = l;
    }
    int maxCoins(vector<int>& a) {
        vector<vector<int>> d(a.size(), vector<int>(a.size(), -1));
        return f(a, d, 0, a.size() - 1);
    }
};

class Solution {
	public:
	void f(vector<vector<int>> & a, int i, int j,int nc,int x) {
		int n = a.size();
		int m = a[0].size();
		a[i][j] = nc;
		if (j + 1<m) {
			if (a[i][j + 1] == x) {
				f(a, i, j + 1,nc,x);
			}
		}
		if (j - 1 >= 0) {
			if (a[i][j - 1] == x) {
				
				f(a, i, j - 1,nc,x);
			}
		}
		if (i + 1<n) {
			if (a[i + 1][j] == x) {
				
				f(a, i + 1, j,nc,x);
			}
		}
		if (i - 1 >= 0) {
			if (a[i - 1][j] == x) {
				
				f(a, i - 1, j,nc,x);
			}
		}
	}
	vector<vector<int>> floodFill(vector<vector<int>> & a, int sr, int sc,int nc) {
		// Code here
		int n = a.size();
		int m = a[0].size();
		int j = 0;
		int i = 0;
		int x = a[sr][sc];
		if(x!=nc)
		f(a,sr,sc,nc,x);
		
		return a;
	}
};

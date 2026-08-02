class Solution {
	public:
	int makeConnected(int n, vector<vector<int>> &a) {
		
		vector<vector<int>> adj(n);
		
		int i = 0;
		while (i < a.size()) {
			adj[a[i][0]].push_back(a[i][1]);
			adj[a[i][1]].push_back(a[i][0]);
			i++;
		}
		
		queue<int> q;
		vector<int> vis(n, 0);
		
		int t = 0;
		i = 0;
		
		while (i < n) {
			
			if (vis[i]) {
				i++;
				continue;
			}
			
			t++;
			vis[i] = 1;
			q.push(i);
			
			while (!q.empty()) {
				
				int b = q.front();
				q.pop();
				
				int j = 0;
				while (j < adj[b].size()) {
					
					if (!vis[adj[b][j]]) {
						vis[adj[b][j]] = 1;
						q.push(adj[b][j]);
					}
					
					j++;
				}
			}
			
			while (i < n && vis[i])
				i++;
		}
		
		t--;
		int e=a.size()-(n-1);
		if (e >=0)
			return t;
		
		return -1;
	}
};
#include<bits/stdc++.h>
using namespace std;
	
int n;
int dp[200005][2];
vector<int> parent;

void dfs(int cur, vector<vector<int>> & g , vector<int> & vis){
	vis[cur] = 1;

	for(int nbr : g[cur]){
		if(!vis[nbr]){
			parent[nbr] = cur;
			dfs(nbr, g, vis);
		}
	}
	
	for(int c : g[cur]){
		if(c!=parent[cur]){
			dp[cur][0] += dp[c][1]; // ??
		}
	}


	for(int c : g[cur]){
		if(c!=parent[cur]){
			int here = dp[cur][0] - dp[c][1] + dp[c][0] + 1;
			dp[cur][1] = max(here, dp[cur][1]);
		}
	}

}

void test_case(){
	cin >> n;
	vector<vector<int>> g(n);
	for(int i=0;i<n-1;i++){
		int u,v;
		cin >> u >> v;
		u--;v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	memset(dp, 0, sizeof(dp));
	vector<int> vis(n);
	parent = vector<int> (n);
	dfs(0,g,vis);
	cout << max(dp[0][0] , dp[0][1]) <<"\n";
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>

vi vis;
vector<vi> g;

// returns the min of this grp
int dfs(int u=1){
	vis[u]=1;
	int ans = u;
	for(int v : g[u]){
		if(!vis[v]){
			ans = min(ans, dfs(v));
		}
	}
	return ans;
}

void test_case(){
	int n,m;
	cin >> n >> m;
	g = vector<vi> (n+1);
	for(int i=0;i<m;i++){
		int u,v;cin >> u >>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vis = vi(n+1);
	
	vi v;
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		v.push_back(dfs(i));
	}
	cout<< v.size()-1 <<"\n";
	for(int i=1;i<v.size();i++) 
		cout << v[i] <<" "  << v[i-1] <<"\n";
	
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}

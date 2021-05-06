#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define vvi vector<vector<int>>


int n;
vector<int> vis(2e5+123), cnt(2e5+12);
vector<int> ans(2e5+1);
vector<vector<int>> g;


int dfs1(int cur=0, int lvl=0){
	vis[cur]=1;
	cnt[cur]=1;
	ans[0] += lvl;
	for(int nbr : g[cur]){
		if(!vis[nbr]){
			cnt[cur] += dfs1(nbr, lvl+1);
		}
	}
	return cnt[cur];
}

void dfs2(int cur=0){
	vis[cur]=1;

	for(int nbr : g[cur]){
		if(!vis[nbr]){
			ans[nbr] = ans[cur] - cnt[nbr] + (n-cnt[nbr]);
			dfs2(nbr);
		}
	}

}

void test_case(){
	cin >> n;
	g = vvi(n);

	for(int i=0;i<n-1;i++){
		int u,v;
		cin >> u >> v;
		u--;v--;			// 0 ... n-1 labeled
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs1();
	vis = vi(n);
	dfs2();
	for(int i=0;i<n;i++) cout << ans[i] <<" ";
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}
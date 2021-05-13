#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>

void test_case(){
	int n,m;
	cin >> n >> m;
	vector<vi> g(n+1);
	for(int i=0;i<m;i++){
		int u,v;cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}	
	vi vis(n+1), color(n+1,-1);

	for(int i=1;i<=n;i++){
		if(vis[i]) continue;

		queue<int> q;
		vis[i]=1;
		color[i]=0;
		q.push(i);

		while(q.size()){
			int u=q.front();
			q.pop();
			for(int v : g[u]){
				if(!vis[v]){
					color[v] = (1^color[u]);
					q.push(v);
					vis[v]=1;
				}
				else if(color[v]==color[u]){
					cout <<"IMPOSSIBLE\n";
					return;
				}
			}
		}
	}


	for(int i=1;i<=n;i++)
		cout << 1+color[i] <<" ";
	cout << endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}

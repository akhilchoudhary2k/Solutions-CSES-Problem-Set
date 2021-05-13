#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>

void test_case(){
	int n,m;
	cin >> n >> m;
	vector<vi> g(n+1);
	for(int i=0;i<m;i++){
		int u,v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vi parent(n+1,-1);
	vi vis(n+1);
	queue<int> q;
	q.push(1);
	vis[1]    = 1;
	parent[1] = 1;

	while(q.size()){
		int u = q.front();
		q.pop();

		for(int v : g[u]){
			if(!vis[v]){
				vis[v]=1;
				parent[v]=u;
				q.push(v);
			}
		}
	}

	if(parent[n]==-1){
		cout <<"IMPOSSIBLE";
	}
	else{
		vi v;
		int c=n;
		while(c != parent[c]){
			v.push_back(c);
			c = parent[c];
		}
		cout << v.size()+1 <<"\n";
		cout <<"1 ";
		for(int i=v.size()-1;i>=0;i--) 
			cout << v[i] <<" ";
	}
	cout <<"\n";
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}

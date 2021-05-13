#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>

int inf = 1e18;

// time complexity = O(V^3)

void test_case(){
	int n,m,q;
	cin >> n >> m >> q;
	vector<vector<int>> dist(n+1,vector<int>(n+1,inf));

	for(int i=0; i<m ; i++){
		int a,b,c;
		cin >> a >> b >> c;
		// multiple edges possible
		dist[a][b] = min(c,dist[a][b]); 
		dist[b][a] = min(c,dist[b][a]);
	}	
	for(int i=1 ; i<=n ; i++) dist[i][i]=0;


	for(int x = 1 ; x<=n ; x++){
		for(int u=1; u<=n ; u++){
			for(int v=1 ; v<=n ; v++){
				dist[u][v] = min(dist[u][v] , dist[u][x]+dist[x][v] );
			}
		}
	}

	while(q--){
		int u,v;
		cin >> u >> v;
		cout << ( dist[u][v]>=inf ? -1 : dist[u][v]) <<"\n";
	}

}

signed main(){
	// ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
int inf = 1e18;


// time complexity = V + log(V)*E


void test_case(){
	int n,m;
	cin >> n >> m;

	vector<vector<array<int,2>>> g(n+1);			// {id,dist}

	for(int i=0;i<m;i++){
		int a,b,c;
		if(a==b) continue;
		cin >> a >> b >> c;
		g[a].push_back({b,c});
	}

	set<array<int,2>> st;							// {dist,id}
	st.insert({0,1});
	for(int i=2;i<=n;i++) st.insert({inf,i});
	vi dist(n+1, inf);
	dist[1]=0;

	for(int i = 1 ; i <= n ; i++ ){
		// get the min dist unvisited(from set) node
		int which = (*st.begin())[1];

		for(auto x : g[which]){
			int cur = dist[x[0]];
			int newd = dist[which] + x[1];
			if(newd < cur){
				dist[x[0]] = newd;
				st.erase({cur,x[0]});
				st.insert({newd,x[0]});
			}
		} 
		
		st.erase(st.begin()); 
	}


	
	for(int i=1;i<=n;i++){
		cout << dist[i] <<" ";
	}
	cout <<"\n";

}

signed main(){
	// ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}

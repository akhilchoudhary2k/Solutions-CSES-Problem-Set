#include<bits/stdc++.h>
using namespace std;
#define int long long

int residual[1000][1000];
vector<vector<int>> g(1000);

vector<int> parent;
int v,e;

int bfs(int s, int t){
	// cout <<"\nbfs called \n";
	parent = vector<int> (v,-1);
	// if parent[x] == -1 => x is not visited

	int mini = INT_MAX;
	queue<int> q;
	q.push(s);
	parent[s] = 10; // random value

	while(!q.empty()){
		int cur = q.front();
		q.pop();
		// cout <<"cur=" << cur << ", ";
		if(cur == t) return mini;

		for(int nbr : g[cur]){
			// not visited & has residual cap>0 take it 
			if(parent[nbr]==-1 && residual[cur][nbr]>0){
				// cout << nbr << "(" << residual[cur][nbr] <<") ";
				mini = min(mini, residual[cur][nbr]);
				parent[nbr] = cur;
				q.push(nbr);
			}
		}
		// cout << "[mini="<<mini<<"]"<< endl;
	}

	return 0;
}


int max_flow(int s, int t){
	int flow = 0;
	int aug = 0;

	while(aug = bfs(s,t)){
		flow += aug;
		// cout << "\naug = " << aug << endl;
		int cur = t;
		// cout <<"path = [ ";
		while(cur != s){
			int prev = parent[cur];
			// cout << cur << " ";
			residual[prev][cur] -= aug;
			residual[cur][prev] += aug;
			cur = prev;
		}
		// cout <<"]\n";
	}

	return flow;
}

signed main(){
	memset(residual,0,sizeof(residual));
	cin >> v >> e;
	// 0 to v-1

	for(int i=0;i<e;i++){
		int u,v,c;
		cin >> u >> v >> c;
		g[u-1].push_back(v-1);
		residual[u-1][v-1] += c;
	}

	int s=0,t=v-1;
	// cin >> s >> t;

	int ans = max_flow(s,t);
	cout << ans << endl;

	return 0;
}



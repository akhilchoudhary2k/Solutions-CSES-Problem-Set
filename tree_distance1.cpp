#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define vvi vector<vector<int>>

// 	we can also do it using BFS!!  2 times
int n;
vector<int> depth(200005);


class Binary_Lifting{
	// with N*log(N) pre processing,  N nodes with 0 to N-1 lables

	// USAGE :    
	// initialise a object named temp of this class :  Binary_Lifting temp = Binary_Lifting(g, [root]);
	// calling the find kth ancestor function 		:  int val = temp.get_kth_ancestor(node, k);
	// calling the get_lca function 				:  int val = temp.get_lca(a,b);
	public :
	// variables
	int n, LOG = 20;  			// LOG is the number of bits required to represent n
	vector<vector<int>> up; 	// up[n][LOG]
	vector<int> depth;

	void dfs(int cur, vector<vector<int>> & g, vector<bool> & vis){
		vis[cur] = 1;
		for(int nbr : g[cur]){
			if(!vis[nbr]){
				up[nbr][0] = cur;
				depth[nbr] = 1 + depth[cur];
				for(int i=1;i<LOG;i++)
					up[nbr][i] = up[up[nbr][i-1]][i-1];
				dfs(nbr, g, vis);
			}
		}
	}
	// constructor
	Binary_Lifting(vector<vector<int>> & g, int root=0){
		n = g.size();
		up = vector<vector<int>> (n, vector<int>(LOG, root)); // initialising with root is important
		depth = vector<int> (n,0);
		vector<bool> vis(n, false);
		dfs(root,g,vis);
	}
	// function
	int get_kth_ancestor(int node, int k){
		if(depth[node] < k) return -1;
		for(int j=LOG-1 ; j>=0 ; j--){
			if(k&(1<<j)){
				node = up[node][j];
				k -= (1<<j);
			}
		}
		return node;
	}
	int get_lca(int a,int b){
		if(depth[a] < depth[b]) swap(a,b);  // a is deeper
		int k = depth[a]-depth[b];
		a = get_kth_ancestor(a, k); 		// a and b are on same level
		if(a == b) return a;				// return ans
		for(int i=LOG-1 ; i>=0 ;i--){
			if( up[a][i] != up[b][i] ){
				a = up[a][i];
				b = up[b][i];
			}
		}
		return up[a][0]; 					// a and b are child of LCA
	}
	int get_distance(int a,int b){
		int lca = get_lca(a,b);
		return depth[a]+depth[b]-2*depth[lca];
	}
};

// returns the last visited node in BFS (farthest node from root)
int bfs(vvi & g, int root){
	int n = g.size();
	vi vis(n);
	int ans=root;

	queue<int> q;
	q.push(root);
	vis[root]=1;

	while(q.size()){
		int f = q.front();
		q.pop();
		ans = f;

		for(int nbr : g[f]){
			if(!vis[nbr]){
				vis[nbr]=1;
				q.push(nbr);
			}
		}
	}

	return ans;
}



void test_case(){

	cin >> n;
	vector<vector<int>> g(n);
	for(int i=0;i<n-1;i++){
		int u,v;
		cin >> u >> v;
		u--;v--;			// 0 ... n-1 labeled
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int  a = bfs(g,0);
	int  b = bfs(g,a);

	Binary_Lifting bl = Binary_Lifting(g);

	for(int i=0;i<n;i++){
		cout << max(bl.get_distance(i,a), bl.get_distance(i,b)) <<" ";
	}
	cout <<"\n";

}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}
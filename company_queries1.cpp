#include<bits/stdc++.h>
using namespace std;
#define int long long

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

void test_case(){
	int n,q;
	cin >> n >> q;
	vector<vector<int>> g(n);
	for(int i=1;i<n;i++){
		int u;
		cin >>u;
		u--;
		g[u].push_back(i);
		g[i].push_back(u);
	}

	Binary_Lifting B = Binary_Lifting(g,0);

	while(q--){
		int x,k;
		cin >> x >> k;
		int ans = B.get_kth_ancestor(x-1,k);
		cout << (ans==-1?ans:ans+1) <<"\n";
	}

}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}

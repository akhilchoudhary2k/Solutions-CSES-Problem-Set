#include<bits/stdc++.h>
using namespace std;
int N = 2e5+1;
vector<vector<int>> tree(N);
vector<int> ans(N);

int find(int root, int parent){
	int temp = 0;
	for(int child : tree[root]) {
		if(child==parent) continue;
		temp += 1+find(child, root);
	}
	ans[root] = temp;
	return temp;
}

int main(){
	
	int n;
	cin >> n;
	for(int i=2;i<=n;i++){
		int a; 
		cin >> a;
		tree[a].emplace_back(i);
		tree[i].emplace_back(a);
	}

	find(1, -1);
	for(int i=1;i<=n;i++) cout << ans[i] << " " ; 
	cout << endl;

	
	return 0;
}
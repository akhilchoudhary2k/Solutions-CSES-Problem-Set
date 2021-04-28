#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

int n;
vector<vector<int>> tree(200000+5);
vector<int> visited(200000+5, 0);

// diameter , depth
pii find(int cur){
	visited[cur]=1;
	int d1=0, d2=0;
	int diam=0; 
	int depth=0;
	int individual_max=0;

	for(int c : tree[cur]){
		if(visited[c]) continue;

		pii temp = find(c);
				
		// treating 1+depth of subtree is a better option

		if(1+temp.second > d1){
			d2=d1;
			d1=1+temp.second;
		}
		else if(1+temp.second < d1 && 1+temp.second > d2){
			d2 = 1+temp.second;
		}
		individual_max = max(individual_max, temp.first);
		diam = max(diam , d2+d1 );
		depth = max(depth , d1);
	}

	return { max(diam,individual_max) , depth};
}

void test_case(){

	cin >> n;
	for(int i=0;i<n-1;i++){
		int a,b;
		cin >> a >> b;
		// --a; --b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	cout << find(1).first << endl;

}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}
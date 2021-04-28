#include<bits/stdc++.h>
using namespace std;
int MAX=1000;
int n,m,cnt=0;
vector<vector<bool>> visited(MAX, vector<bool>(MAX, false));
vector<string> grid(MAX);

void dfs(int r, int c){
	if(r<0||r>=n || c<0||c>=m || visited[r][c] || grid[r][c]=='#') return;
	// cnt++;
	visited[r][c]=1;
	dfs(r+1,c);
	dfs(r-1,c);
	dfs(r,c+1);
	dfs(r,c-1);
}

int main(){

	cin >> n >> m;
	for(int i=0;i<n;i++) cin >> grid[i];

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(grid[i][j] == '#' || visited[i][j]) continue;
			dfs(i,j);
			cnt++;
		}
	}

	cout << cnt << endl;
	
	return 0;
}
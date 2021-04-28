#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second



class Cell{
public:
	int r, c, len;
	Cell(int x,int y, int z){
		r=x; c=y; len=z;
	}
};

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int n,m;
	cin >> n >> m;
	vector<string> grid(n);
	for(int i=0;i<n;i++) cin >> grid[i];

	int r=-1,c=-1;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) if(grid[i][j] == 'A') {r=i; c=j; break;}
		if(r!=-1) break;
	}

	// cout <<"start : "<<r <<", " << c << endl;

	map< pair<int,int> , pair<int,int>  > parent;
	vector<vector<bool>> visited(n, vector<bool>(m, false) );
	queue<Cell> q;

	auto valid = [&](int row, int col){
		if(row>=0&&row<n&&col>=0&&col<m&&grid[row][col]!='#' && !visited[row][col])
			return true;
		return false;
	};

	auto print = [&](pair<int,int> curr){

		vector<char> path;
		while(parent[curr] != curr){
			if(parent[curr].ff - curr.ff == 1){
				path.push_back('U');
			}
			if(parent[curr].ff - curr.ff == -1){
				path.push_back('D');
			}
			if(parent[curr].ss - curr.ss == 1){
				path.push_back('L');
			}
			if(parent[curr].ss - curr.ss == -1){
				path.push_back('R');
			}
			curr = parent[curr];
		}
		reverse(path.begin(), path.end());
		for(char x : path) cout << x;
		cout << endl;
	};

	// BFS

	q.push(Cell(r,c,0));
	visited[r][c]=1;
	parent[ {r,c} ] = {r,c};

	while(!q.empty()){
		Cell f = q.front();
		q.pop();
		if(grid[f.r][f.c] == 'B'){
			// ...
			cout << "YES" << endl;
			cout << f.len << endl;
			print({f.r , f.c});
			return 0;
		}

		if(valid(f.r-1, f.c)){
			visited[f.r-1][f.c]=1;
			q.push( Cell(f.r-1 , f.c , f.len+1) );
			parent[ {f.r-1,f.c} ] = {f.r, f.c};
		}
		if(valid(f.r+1, f.c)){
			visited[f.r+1][f.c]=1;
			q.push( Cell(f.r+1 , f.c , f.len+1) );
			parent[ {f.r+1,f.c} ] = {f.r, f.c};
		}
		if(valid(f.r, f.c-1)){
			visited[f.r][f.c-1]=1;
			q.push( Cell(f.r , f.c-1 , f.len+1) );
			parent[ {f.r,f.c-1} ] = {f.r, f.c};
		}
		if(valid(f.r, f.c+1)){
			visited[f.r][f.c+1]=1;
			q.push( Cell(f.r , f.c+1 , f.len+1) );
			parent[ {f.r,f.c+1} ] = {f.r, f.c};
		}


	}
	cout <<"NO" << endl;
	
	return 0;
}
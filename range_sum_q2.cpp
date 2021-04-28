#include<bits/stdc++.h>
using namespace std;
#define int long long

int *segtree, *arr;

void buildTree(int start, int end, int treenode){
	if(start == end){
		segtree[treenode] = arr[start];
		return;
	}
	int mid = (start+end)/2;
	buildTree(start, mid, 2*treenode+1);
	buildTree(mid+1, end, 2*treenode+2);
	segtree[treenode] = segtree[2*treenode+1] + segtree[2*treenode+2];
}

void updateTree(int start, int end, int treenode, int ind, int val){
	if(start == end){
		segtree[treenode] = val;
		arr[ind] = val;
		return;
	}
	int mid = (start+end)/2;
	if(ind <= mid) updateTree(start, mid, 2*treenode+1, ind, val);
	else updateTree(mid+1, end, 2*treenode+2, ind, val);
	segtree[treenode] = segtree[2*treenode+1] + segtree[2*treenode+2];
}

int query(int start, int end, int treenode, int left, int right){
	
	if(start >= left && end <= right){
		return segtree[treenode];
	}

	if(start > right || end < left ){
		return 0;
	}

	int mid = (start+end)/2;
	int L = query(start, mid, 2*treenode+1, left, right);
	int R = query(mid+1, end, 2*treenode+2, left, right);
	return L+R;

}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int n, q;
	cin >> n >> q;

	arr = new int[n];
	segtree = new int[4*n];

	for(int i=0;i<n;i++) cin >> arr[i];

	buildTree(0,n-1,0);

	while(q--){
		int t, a, b;
		cin >> t >> a >> b;
		if(t==1){
			updateTree(0, n-1, 0, a-1, b);
		}
		else{
			cout << query(0, n-1, 0, a-1, b-1) << endl;
		}
	}
	
	return 0;
}
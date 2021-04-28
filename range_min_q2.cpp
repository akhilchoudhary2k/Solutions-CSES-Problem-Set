#include<bits/stdc++.h>
using namespace std;

int *arr, *segtree;

void buildTree(int arrstart, int arrend, int treeind){
	if(arrstart == arrend){
		segtree[treeind] = arr[arrstart];
		return;
	}
	int mid = (arrstart+arrend)/2;
	buildTree(arrstart, mid, 2*treeind+1);
	buildTree(mid+1, arrend, 2*treeind+2);

	segtree[treeind] = min(segtree[2*treeind+1] , segtree[2*treeind+2]);
}

int query(int arrstart, int arrend, int treeind, int left, int right){
	// inside
	if(arrstart >= left && arrend<= right){
		return segtree[treeind];
	}

	//outside
	if(arrstart > right || arrend < left){
		return INT_MAX;
	}

	//partial overlap
	int mid = (arrstart+arrend)/2;
	int L = query(arrstart, mid, 2*treeind+1, left, right);
	int R = query(mid+1, arrend, 2*treeind+2, left, right);
	return min(L, R);
}

void updateTree(int arrstart, int arrend, int treeind, int ind, int val){
	
	if(arrstart == arrend){
		segtree[treeind] = val;
		return ;
	}

	int mid = (arrstart+arrend)/2;
	if(ind <= mid){
		updateTree(arrstart, mid, 2*treeind+1, ind, val);
	}else{
		updateTree(mid+1, arrend, 2*treeind+2, ind, val);
	}
	segtree[treeind] = min(segtree[2*treeind+1] , segtree[2*treeind+2]);

}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int n,q;
	cin >> n >> q;
	arr = new int[n];
	segtree = new int[4*n];

	for(int i=0;i<n;i++) cin >> arr[i];
	buildTree(0, n-1, 0);
	
	while(q--){
		int a,b, type;
		cin >> type >> a >> b;
		if(type == 2){
			cout << query(0, n-1, 0, a-1, b-1) << endl;
		}
		else{
			updateTree(0, n-1, 0, a-1, b);
		}
	}

	return 0;
}
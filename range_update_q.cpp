// update a range
// query a single element

#include<bits/stdc++.h>
using namespace std;
#define int long long
int *arr, *lazy;

void update(int arrstart, int arrend, int treeind, int left, int right, int inc){
	// inside
	if(arrstart>=left && arrend <= right){
		lazy[treeind] += inc;
		return ;
	}

	// outside
	if(arrstart > right || arrend < left){
		return;
	}

	// partial
	int mid = (arrstart+arrend)/2;
	update(arrstart, mid, 2*treeind+1, left, right, inc);
	update(mid+1, arrend, 2*treeind+2, left, right, inc);
}

int query(int arrstart, int arrend, int treeind, int ind){
	if(arrstart == arrend){
		return lazy[treeind] + arr[arrstart];
	}

	int mid = (arrstart+arrend)/2;
	if(ind <= mid){
		return lazy[treeind] + query(arrstart, mid, 2*treeind+1, ind );
	}else{
		return lazy[treeind] + query(mid+1, arrend, 2*treeind+2, ind );
	}
}

signed main(){

	int n,q;
	cin >> n >> q;
	arr = new int[n];
	lazy = new int[4*n]();

	for(int i=0;i<n;i++) cin >> arr[i];


	while(q--){
		int t;
		cin >> t;
		if(t==1){
			int a,b,u;
			cin >> a >> b >> u;
			update(0, n-1, 0, a-1, b-1, u);
		}
		else{
			int k;
			cin >> k;
			cout << query(0, n-1, 0, k-1) << endl;
		}
	}
	

	return 0;
}
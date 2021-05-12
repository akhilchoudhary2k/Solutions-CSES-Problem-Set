#include<bits/stdc++.h>
using namespace std;
#define int long long

#define N 200000

int n;
vector<array<int,3>> v;
vector<int> segtree[4*N+1];

void build_tree(int st, int en, int tree_ind){
	if(st>en) return;
	if(st==en){
		segtree[tree_ind].push_back(v[st][1]);
		return;
	}

	int mid = (st+en)/2;
	build_tree(st,mid, 2*tree_ind+1);
	build_tree(mid+1, en, 2*tree_ind+2);

	segtree[tree_ind] = segtree[2*tree_ind+1];

	for(int x : segtree[2*tree_ind+2]) 
		segtree[tree_ind].push_back(x);

	sort(segtree[tree_ind].begin(), segtree[tree_ind].end());

}

// left to right index ke segments with ending <= val
int query1(int st, int en, int tree_ind,  int left, int right, int val){
	if(st>en) return 0;
	
	// complete overlap
	if(st>=left && en<=right){
		return upper_bound(segtree[tree_ind].begin(), segtree[tree_ind].end(),val) - segtree[tree_ind].begin();
	}

	// no overlap
	if(st>right || en<left){
		return 0;
	}

	int mid = (st+en)/2;
	return query1(st,mid,2*tree_ind+1, left, right, val) + 
			query1(mid+1,en, 2*tree_ind+2, left, right, val);

}

// count of left to right index segments with val >= v[i][1]
int query2(int st, int en, int tree_ind, int left, int right, int val){
	if(st>en) return 0;

	if(st>=left && en<=right){
		int ind = lower_bound(segtree[tree_ind].begin(), segtree[tree_ind].end(),val)-segtree[tree_ind].begin();
		return segtree[tree_ind].size() - ind;
	}

	if(st>right || en<left){
		return 0;
	}

	int mid = (st+en)/2;
	return query2(st,mid,2*tree_ind+1, left, right, val) + 
			query2(mid+1,en, 2*tree_ind+2, left, right, val);
}

void test_case(){
	cin >> n;
	v = vector<array<int,3>> (n);
	for(int i=0;i<n;i++){
		cin >> v[i][0] >> v[i][1];
		v[i][2]=i;
	}	
	sort(v.begin(), v.end());
	// for(auto x : v)
	// 	cout << x[0] <<" " << x[1] <<" " << x[2]<<"\n";

	build_tree(0, n-1, 0);
	
	vector<int> ans1(n),ans2(n),starting(n);
	for(int i=0;i<n;i++) starting[i]=v[i][0];

	// count of other ranges it contains
	for(int i=0;i<n;i++){
		// count of ranges with ending <= v[i][1] & starting >= v[i][0]
		int ind = lower_bound(starting.begin(), starting.end(), v[i][0]) - starting.begin();
		int ans = query1(0,n-1,0,  ind,n-1,v[i][1]);
		ans1[v[i][2]]=ans-1;
	}


	// count of ranges which contain it
	for(int i=0;i<n;i++){
		// count of ranges with ending >= v[i][1] & starting <= v[i][0]
		int ind = upper_bound(starting.begin(), starting.end(), v[i][0]) - starting.begin();
		ind--;

		int ans = query2(0,n-1,0 , 0,ind,v[i][1] );
		ans2[v[i][2]] = ans-1;
	}

	for(int x : ans1) cout << x <<" "; cout <<"\n";
	for(int x : ans2) cout << x <<" "; cout <<"\n";
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}

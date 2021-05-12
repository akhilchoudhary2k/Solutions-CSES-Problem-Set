#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>


void test_case(){
	int n,k;
	cin >> n >> k;
	ordered_set oset;
	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];

	for(int i=0;i<k;i++)
		oset.insert(a[i]);
	
	cout << *oset.find_by_order((k-1)/2) <<" ";

	int end = k;
	while(end < n){
		oset.insert(a[end]);
		// cout << "order:" << oset.order_of_key(a[end-k]) <<"\n";
		oset.erase(oset.find_by_order(oset.order_of_key(a[end-k])));
		cout << *oset.find_by_order((k-1)/2) <<" ";
		// cout <<"set:";
		// for(int x : oset) cout << x <<" "; cout  <<"\n";
		end++;
	}
	cout <<"\n";

}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}

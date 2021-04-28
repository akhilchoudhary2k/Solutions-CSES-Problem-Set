#include<bits/stdc++.h>
using namespace std;
#define int long long

void test_case(){
	int n; cin >> n;
	int arr[n];
	for(int i=0;i<n;i++) cin >> arr[i];

	int best=INT_MIN;
	int so_far=0;

	for(int i=0;i<n;i++){
		so_far += arr[i];
		best = max(best, so_far);
		if(so_far<0) so_far=0; 
	}

	cout << best << endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long


void test_case(){
	int n;
	cin >> n;
	int ans = 0;
	while(n){
		int N=n;
		int mx=0;
		while(N){
			mx = max(mx, N%10);
			N/=10;
		}
		n -= mx;
		ans ++;
	}
	cout << ans <<"\n";
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}

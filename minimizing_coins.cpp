#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> dp(1000000+123, 1e9);
// dp[x] -> min coins for sum x

void test_case(){
	int n,x;
	cin >> n >> x;
	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];
	sort(a,a+n);
	
	dp[0] = 0;
	for(int i=1 ; i<=x ; i++){
		// make sum i and last choosen coin is a[j]
		for(int j=0 ; j<n && a[j]<=i ; j++){
			dp[i] = min(dp[i] , 1+dp[i-a[j]]);
		}
	}

	cout << (dp[x]==1e9 ? -1 : dp[x]) << "\n";
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
// #define int long long

int mod = 1e9+7;
int dp[100000][102];

void test_case(){
	int n,m;
	cin >> n >> m;
	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];
	
	memset(dp,0,sizeof(dp));
	// dp[i][j] --> ways when ith index has value j

	if(a[0]) dp[0][a[0]] = 1;
	else for(int j=1; j<=m ;j++) dp[0][j]=1;

	for(int i=1;i<n;i++){
		if(a[i]) {
			dp[i][a[i]] = ((dp[i-1][a[i]-1] + dp[i-1][a[i]])%mod + dp[i-1][a[i]+1])%mod;			
		}
		else{
			for(int j=1;j<=m;j++){
				dp[i][j] = ((dp[i-1][j-1] + dp[i-1][j])%mod + dp[i-1][j+1])%mod;
			}
		}
	}

	int ans = 0;
	if(a[n-1]) cout << dp[n-1][a[n-1]] <<"\n";
	else{
		for(int j=1;j<=m;j++){
			ans += dp[n-1][j];
			ans %= mod;
		}
		cout << ans <<"\n";
	}

}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

#define ll long long
int mod = 1e9+7;

int dp[100+1][1000000+1];

void test_case(){
	int n,x;
	cin >> n >> x;
	int coin[n];
	for(int i=0;i<n;i++) cin >> coin[i];

	// dp[a][b] --> unique ways to make sum b using first a coins
	
	for(int i=0;i<=n;i++) dp[i][0] = 1;
	for(int j=1;j<=x;j++) dp[0][j] = 0;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=x;j++){
			//dont use ith coin
			dp[i][j] = dp[i-1][j];
			// use ith coin if possible
			if(coin[i-1] <= j) {
				dp[i][j] += dp[i][j-coin[i-1]];
				// if(dp[i][j] >= mod) dp[i][j] -= mod;
				dp[i][j] %= mod;
			}
		}
	}
	cout << dp[n][x] <<"\n";
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long


void test_case(){
	string s,t;
	cin >> s >> t;
	int n=s.length(), m=t.length();
	int dp[n+1][m+1];

	for(int i=0;i<=n;i++) 
		dp[i][0] = i;
	for(int j=0;j<=m;j++)
		dp[0][j] = j;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j] = min(1+dp[i-1][j] , 1+dp[i][j-1]);
			dp[i][j] = min(dp[i][j], ((s[i-1]==t[j-1])?0:1)+dp[i-1][j-1]);
			// cout << 
		}
	}
	cout << dp[n][m] <<"\n";
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}

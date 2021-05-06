#include<bits/stdc++.h>
using namespace std;
// #define int long long

int dp[1001][100001];
// vector<vector<int>> dp;


void test_case(){
	int n,x;
	cin >> n >> x;
	int price[n], pages[n];
	for(int i=0;i<n;i++) cin >> price[i]; 
	for(int i=0;i<n;i++) cin >> pages[i];
	
	// dp = vector<vector<int>> (n+1, vector<int>(x+1));
	// dp[i][j]  --> max pages in first i books and j money
	memset(dp, 0, sizeof(dp));

	for(int i=1;i<=n;i++){
		for(int j=1;j<=x;j++){
			dp[i][j] = dp[i-1][j];
			if(price[i-1] <= j){
				dp[i][j] = max(dp[i][j] , pages[i-1] + dp[i-1][j-price[i-1]]);
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

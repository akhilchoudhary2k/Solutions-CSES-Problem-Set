#include<bits/stdc++.h>
using namespace std;

void test_case(){
	int n;
	cin >> n;
	int m = 1e9+7;

	vector<string> grid(n);
	for(int i=0;i<n;i++) cin >> grid[i];

	long long dp[n][n];
	dp[n-1][n-1] = (grid[n-1][n-1]=='*') ? 0 : 1;

	for(int i=n-2;i>=0;i--){
		if(grid[n-1][i]=='*') dp[n-1][i]=0;
		else dp[n-1][i] = dp[n-1][i+1];
	}
	for(int j=n-2;j>=0;j--){
		if(grid[j][n-1]=='*') dp[j][n-1] = 0;
		else dp[j][n-1] = dp[j+1][n-1];
	}

	for(int i=n-2;i>=0;i--){
		for(int j=n-2;j>=0;j--){
			if(grid[i][j]=='*') dp[i][j]=0;
			else{
				dp[i][j] = dp[i+1][j]+dp[i][j+1];
				dp[i][j] %= m;
			}
		}
	}

	cout << dp[0][0] << endl;

}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}
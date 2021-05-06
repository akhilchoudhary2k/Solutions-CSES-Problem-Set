#include<bits/stdc++.h>
using namespace std;
#define int long long


void test_case(){
	int a,b;
	cin >> a >> b;
	int dp[a][b];
	
	for(int i=0;i<a;i++)
		dp[i][0] = i;
	for(int j=0;j<b;j++)
		dp[0][j] = j;
	
	for(int i=1;i<a;i++){
		for(int j=1;j<b;j++){
			dp[i][j] = 1e9;

			//these are all the exclusive moves

			// 1 vertical cut
			for(int k=1;k<=j;k++){
				dp[i][j] = min(dp[i][j] , 1+dp[i][k-1]+dp[i][j+1-k-1]);
			}
			// 1 horizontal cut
			for(int k=1;k<=i;k++){
				dp[i][j] = min(dp[i][j] , 1+dp[k-1][j]+dp[i+1-k-1][j]);
			}

			if(i==j) dp[i][j]=0;
		}
	}


	cout << dp[a-1][b-1] << "\n";
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}

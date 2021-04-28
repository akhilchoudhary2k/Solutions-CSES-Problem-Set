#include<bits/stdc++.h>
using namespace std;
int m = 1e9+7;

int main(){
	
	int n;
	cin >> n;

	int dp[n+1] = {0};
	dp[0] = 1;

	for(int i=1;i<=n;i++){
		
		for(int j=1;j<=6;j++){
			if(i>=j) dp[i] += dp[i-j] % m  , dp[i] %= m;;
		}
	}

	cout << dp[n]%m << endl;

	return 0;
}









	// if dice combinations are unordered


	// int dp[8][n+1];
	// // dp[i][j] --> make sum j using i, i+1, ... 6 numbers

	// for(int i=1;i<=n;i++) dp[7][i] = 0; 
	// for(int i=1;i<8;i++) dp[i][0] = 1;

	// for(int j=1;j<=n;j++){
	// 	for(int i=6;i>=1;i--){
	// 		dp[i][j] = 0;
	// 		int a=0,b=0;
	// 		if(i<=j) a = dp[i][j-i];
	// 		b = dp[i+1][j];
	// 		dp[i][j] = a+b;
	// 	}
	// }
	// for(int i=1;i<=6;i++){
	// 	for(int j=1;j<=n;j++) cout << dp[i][j] << " ";
	// 	cout << endl;
	// }

	// cout << dp[1][n] << endl;
#include<bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int n,m;
	cin >> n >> m;
	vector<string> v(n);
	for(int i=0;i<n;i++) cin >> v[i];

	int dp[n+1][n+1];
	for(int i=0;i<=n;i++) dp[i][0]=0;
	for(int i=0;i<=n;i++) dp[0][i]=0;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1];
			if(v[i-1][j-1] == '*') dp[i][j]++;
		}
	}

	// for(int i=0;i<=n;i++){
	// 	for(int j=0;j<=n;j++){
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	while(m--){
		int y1,x1,y2,x2;
		cin >> y1 >> x1 >> y2 >> x2;
		int ans = 0;
		ans += dp[y2][x2];
		ans -= dp[y1-1][x2];
		ans -= dp[y2][x1-1];
		ans += dp[y1-1][x1-1];

		cout << ans << endl;
	}
	
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long

int dp[5000][5000];		

void test_case(){
	int n,total=0;;
	cin >> n;
	int a[n];
	for(int i=0; i<n; ++i) cin >> a[i], total+=a[i];
	
	// dp[i][j] --> score1-score2 if we play in a[i...j] and start with player 1

	for(int i=n-1;i>=0;i--){
		for(int j=i;j<n;j++){
			if(i==j) dp[i][j] = a[i];
			else{
				dp[i][j] = max(a[i] - dp[i+1][j] , a[j] - dp[i][j-1]);
			}
		}
	}		
	// cout << "total " << total <<"\n";
	cout << (dp[0][n-1]+total)/2 <<"\n";
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}

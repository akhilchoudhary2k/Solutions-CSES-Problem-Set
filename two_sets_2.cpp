#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int power(int a, int b){int ans = 1;a %= mod;while(b){if(b&1){ans = (ans*a)%mod;b--;}a = (a*a)%mod;b/=2;}return ans;}

int fermat_inv(int x){
	return power(x, mod-2);    // (a/b)%mod = (a*(fermat_inv(b)))%mod
}

void test_case(){
	int n;
	cin >> n;
	int s=(n*(n+1))/2;
	if(s&1){
		cout <<0<<"\n"; return;
	}

	int dp[s+1]={0};
	// dp[i] --> ways to make sum i
	dp[0]=1;

	for(int i=1;i<=n;i++){
		// using first i elements we can make 
		// all sums from 1 to n(n+1)/2 
		for(int j = ((i-1)*i)/2 ; j >= 0 ; j-- ){
			dp[j+i] += dp[j]%mod;
			dp[j+i] %= mod;
		}
	}
	cout << ( dp[s/2] * fermat_inv(2) ) % mod<< "\n";
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}






























// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int mod = 1e9+7;
// vector<vector<int>> dp;
// void test_case(){
// 	int n;
// 	cin >> n;
// 	int s = (n*(n+1))/2;
// 	if(s&1){
// 		cout << "0\n"; return;
// 	}	
// 	dp = vector<vector<int>> (n+1, vector<int>(s+1,0));
// 	int ans = 0;
// 	// dp[x][k] --> # ways to make sum k using first x elements
// 	for(int i=1;i<=n;i++) dp[i][0] = 1;
// 	for(int i=1;i<=n;i++){
// 		for(int j=1;j<=s;j++){
// 			dp[i][j] += dp[i-1][j];
// 			dp[i][j] %= mod;
// 			if(j-i>=0) {
// 				dp[i][j] += dp[i-1][j-i];
// 				dp[i][j] %= mod;
// 				if(j==s/2) ans += dp[i-1][j-i];
// 				ans %= mod;
// 			}
// 		}
// 	} 
//  	cout << ans <<"\n";
// }

// signed main(){
// 	ios_base::sync_with_stdio(false); cin.tie(0);
	
// 	int t=1;
// 	// cin >> t;

// 	while(t--) test_case();
	
// 	return 0;
// }



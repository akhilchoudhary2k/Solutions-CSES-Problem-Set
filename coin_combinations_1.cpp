#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")

#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

// time complexity = O(N*X)
// space complexity = O(X)

int coin[101];
int dp[1000000+1];
// dp[i] --> no of ways of making sum i	

void add_self(int & a, int & b){
	// a = (a+b)%mod
	a += b;
	if(a >= mod)
		a-=mod;
}


void test_case(){
	int n,x;
	cin >> n >> x;

	for(int i=0;i<n;i++) cin >> coin[i];                      

	dp[0] = 1;

	for(int s=1 ; s<=x ; s++){
		dp[s]=0;
		for(int i=0; i<n ; i++){
			if(coin[i] > s) continue;
			add_self(dp[s], dp[s-coin[i]]);
			// dp[s] += dp[s-coin[i]];
			// dp[s] %= mod;
		}
	}
	cout << dp[x] << "\n";
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}





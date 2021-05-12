#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> dp;

void test_case(){
	int n, w;
	cin >> n >> w;
	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];
	sort(a,a+n);
	
	dp = vector<int>(1<<n,0);
	// int dp[1<<n];
	// dp[0]=0;

	for(int mask=1;mask<(1<<n);mask++){
		// bitset<4> b(mask);
		// cout << b <<" ";

		int here=0;
		int mask2 = mask;
		// remove max weight
		for(int i=n-1;i>=0;i--){
			if(mask&(1<<i)){
				if(a[i]+here<=w){
					here += a[i];
					//unset the ith bit
					mask2 = (mask2&(~(1<<i)));
				}
			}
		}
		dp[mask] = 1+dp[mask2];
		// cout << dp[mask] <<" ";

		//remove max people
		here=0;
		mask2=mask;
		for(int i=0;i<n;i++){
			if(mask&(1<<i)){
				if(a[i]+here<=w){
					here += a[i];
					// unset the ith bit
					mask2 = mask2&(~(1<<i));
				}
			}
		}
		dp[mask] = min(dp[mask], 1+dp[mask2]);
		// cout << 
	}
	cout << dp[(1<<n)-1]<<"\n";
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}

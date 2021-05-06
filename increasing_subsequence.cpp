#include<bits/stdc++.h>
using namespace std;
#define int long long
int inf = 1e18+123;

// strictly increasing subsequence

void test_case(){
	int n; cin >> n;
	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];

	// dp[x] -> min ending value for x length inc subseq
	vector<int> dp(n+1, inf); 
	dp[0] = -inf;

	for(int i=0;i<n;i++){
		// rightmost index in dp with value < a[i]
		int ind = lower_bound(dp.begin(), dp.begin()+n+1, a[i]) - dp.begin();
		if(ind) ind--;
		dp[ind+1] = min(dp[ind+1], a[i]);
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		if(dp[i] != inf) ans = i;
	}
	cout << ans <<"\n";
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long


void test_case(){
	int n;
	cin >> n;

	vector<tuple<int,int,int>> v(n);
	for(int i=0;i<n;i++) {
		int a,b,c;
		cin >> a >> b >> c;
		v[i] = make_tuple(a,b,c);
	}
	sort(v.begin(), v.end());
	vector<int> x;
	for(auto f : v) x.push_back(get<0>(f));

	int dp[n];
	dp[n-1] = get<2>(v[n-1]);
	// cout <<"dp[9]=" << dp[9]<<"\n";

	for(int i=n-2;i>=0;i--){
		dp[i] = dp[i+1];

		int ind = upper_bound(x.begin(), x.end(), get<1>(v[i]) ) - x.begin();
		
		dp[i] = max(dp[i] , get<2>(v[i]) + (ind<n?dp[ind]:0)  );
		

	}

	cout << dp[0];
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}

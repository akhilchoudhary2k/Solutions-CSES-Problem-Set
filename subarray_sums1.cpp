#include<bits/stdc++.h>
using namespace std;
#define int long long

void test_case(){
	int n,x;
	cin >> n >> x;

	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];

	int ans = 0;
	int pref = 0;
	map<int,int> mp;
	mp[pref]++;

	for(int i=0;i<n;i++){
		pref += a[i];
		ans += mp[pref-x];
		mp[pref]++;
	}
	cout << ans <<"\n";

}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}
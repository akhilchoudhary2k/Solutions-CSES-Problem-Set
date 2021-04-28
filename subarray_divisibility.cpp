#include<bits/stdc++.h>
using namespace std;
#define int long long


// important TC
// 3
// -7 7 11

void test_case(){
	// cout << (-11)%3 << endl;
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];

	unordered_map<int,int> mp;
	mp[0]++;

	int cur = 0, ans = 0;
	for(int i=0;i<n;i++){
		cur += a[i];
		int rem = (cur%n + n )%n;
		ans += mp[rem];
		// cout <<"i:" << i <<" ans:" << ans << endl;
		mp[rem] ++;
	}

	cout << ans << endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long

void test_case(){
	int n,x;
	cin >> n >> x;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin >> v[i];

	int pref=0;
	map<int,int> mp;
	mp[pref]++;

	int cnt=0;

	for(int i=0;i<n;i++){
		pref += v[i];
		cnt += mp[pref-x];
		// cout << "i=" << i <<" pref=" << pref << "[" << cnt <<"]" << endl;
		mp[pref]++;
	}
	cout << cnt << endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long

void test_case(){
	int n;
	cin >> n;
	int t = 0;
	vector<pair<int,int>> v(n); 
	for(int i=0;i<n;i++){
		int a,b;
		cin >> a >> b;
		v[i] = {a,b};
	}
	sort(v.begin(), v.end());
	int ans = 0;

	for(int i=0;i<n;i++){
		t += v[i].first;
		ans += v[i].second - t;
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
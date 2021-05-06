#include<bits/stdc++.h>
using namespace std;
// #define int long long


void test_case(){
	int n;
	cin >> n;
	int coin[n];
	for(int i=0;i<n;i++) cin >> coin[i];

	unordered_set<int> s;
	s.insert(0);

	for(int i=0;i<n;i++){
		unordered_set<int> temp=s;
		for(int x : s) temp.insert(x+coin[i]);
		s = temp;
	}
	cout << s.size()-1 <<"\n";
	vector<int> v(s.begin(),s.end());
	sort(v.begin(), v.end());
	for(int i=1;i<(int)v.size();i++) cout << v[i] <<" ";
	cout <<"\n";
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}

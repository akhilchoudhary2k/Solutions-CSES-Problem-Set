#include<bits/stdc++.h>
using namespace std;
#define int long long


void test_case(){
	int n,m;
	cin >> n >> m;
	multiset<int> st;
	for(int i=0;i<n;i++){
		int x;cin >>x;st.insert(x);
	}
	for(int i=0;i<m;i++){
		int cost;cin >> cost;
		// find a value <= cost
		auto p = st.upper_bound(cost);
		if(p==st.begin()) cout <<"-1\n";
		else{
			p--;
			cout << *p <<"\n";
			st.erase(p);
		}
	}
	cout <<"\n";
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}

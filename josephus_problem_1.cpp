#include<bits/stdc++.h>
using namespace std;
#define int long long


void test_case(){
	int n;
	cin >> n;
	set<int> st;
	for(int i=1;i<=n;i++)
		st.insert(i);

	if(n==1){
		cout << "1\n"; return;
	}
	auto p = st.begin();
	p++;
	while(st.size()>1){
		auto temp = p;
		cout << *temp <<" ";
		// cout <<"hello akhil\n";
		temp++;
		if(temp==st.end()) temp = st.begin();
		temp++;
		if(temp==st.end()) temp = st.begin();

		st.erase(*p);
		p=temp;
	}	
	cout << *st.begin() <<"\n";
}

signed main(){
	// ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}

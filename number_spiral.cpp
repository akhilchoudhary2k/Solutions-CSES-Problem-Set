#include<bits/stdc++.h>
using namespace std;
#define int long long


void test_case(){
	int r,c;
	cin >> r >> c;
	int M = max(r-1,c-1);

	int up = (M&1);

	// 2M+1
	if(r > M){
		int diff = c-1;
		if(up) cout << (M+1)*(M+1) - diff;
		else   cout << M*M+1 + diff;
	}
	else{
		int diff = r-1;
		if(up) cout << M*M+1 + diff;
		else cout << (M+1)*(M+1) - diff;
	}
	cout <<"\n";
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t=1;
	cin >> t;

	while(t--) test_case();
	
	return 0;
}

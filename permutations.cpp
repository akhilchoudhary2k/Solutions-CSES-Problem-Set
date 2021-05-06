#include<bits/stdc++.h>
using namespace std;
#define int long long


void test_case(){
	int n;
	cin >> n;
	if(n<=3 && n!=1){
		cout <<"NO SOLUTION\n";
	}
	else{
		for(int i=2;i<=n;i+=2) cout << i <<" ";
		for(int i=1;i<=n;i+=2) cout << i <<" ";
		cout <<"\n";
	}
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}

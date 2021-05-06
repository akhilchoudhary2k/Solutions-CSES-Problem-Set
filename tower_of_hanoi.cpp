#include<bits/stdc++.h>
using namespace std;
#define int long long

// a --> b, using c
void solve(int n, int a , int b, int c){
	if(n == 0) return;
	
	solve(n-1, a, c, b);
	cout << a <<" " << b <<"\n";
	solve(n-1, c, b, a);
}

void test_case(){
	int n;
	cin >> n;
	cout << (1<<n)-1 <<"\n";
	solve(n,1,3,2);
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}

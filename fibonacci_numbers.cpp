#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

vector<int> mult(vector<int> a, vector<int> b){
	vector<int> v(4);
	v[0] = (a[0]*b[0] + a[1]*b[2])%mod;
	v[1] = (a[0]*b[1] + a[1]*b[3])%mod;
	v[2] = (a[2]*b[0] + a[3]*b[2])%mod;
	v[3] = (a[2]*b[1] + a[3]*b[3])%mod;
	return v;
}

vector<int> F{1,1,1,0};

vector<int> fib(int n){
	if(n==0){
		vector<int> v(4,0);
		return v;
	}
	if(n==1){
		return F;
	}
	vector<int> x = fib(n/2);
	x = mult(x,x);
	if(n&1) x= mult(F,x);
	return x;
}


void test_case(){
	int n;
	cin >> n;
	if(n==1) cout << 1 << '\n';
	else cout << fib(n-1)[0] << '\n';;;;;;;;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}
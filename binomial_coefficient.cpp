#include<bits/stdc++.h>
using namespace std;
#define int long long

int mod = 1e9+7;
const int N = 1e6;

int fact[N+1];

// a^b
int power(int a, int b){
	if(b==0) return 1;

	int small = power(a,b/2);
	int ans = (small*small)%mod;
	if(b&1) ans *= a;
	return ans%mod;
}

int fermat_inverse(int x){
	return power(x,mod-2);
}

void test_case(){
	int n,r;
	cin >> n >> r ;
	//nCr  = n! / (n-r)! r!

	int num = fact[n];
	int den = (fact[n-r]*fact[r])%mod;

	int ans = (num * fermat_inverse(den))%mod;
	cout << ans <<"\n";
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	fact[0]=1;
	for(int i=1;i<=N;i++){
		fact[i] = (i*fact[i-1])%mod;
	}

	int t=1;
	cin >> t;
	while(t--) test_case();
	
	return 0;
}

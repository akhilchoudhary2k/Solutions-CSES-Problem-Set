#include<bits/stdc++.h>
using namespace std;
#define ll long long
int m = 1e9+7;

ll power(ll a, ll b){
	if(a==1 || b==0 ) return 1;
	else if(a==0) return 0;
	
	ll small = power(a, b/2)%m;
	if(b&1){
		ll ans = small;
		ans = (ans * ans )%m;
		ans = (ans*a) %m;
		return ans%m;
	}
	else {
		return (small*small)%m;
	}
}
ll power2(ll a, ll b, ll c){
	if(a==1 || b==0 ) return 1;
	else if(a==0) return 0;
	
	ll x = power(b,c)%m;
	ll y = power(a, x)%m;
	return y;
}

void test_case(){
	ll a,b,c;
	cin >> a >> b >> c;
	cout << power2(a, b, c) << endl;
}

int main(){
	int t=1;
	cin >> t;

	while(t--) test_case();
	
	return 0;
}

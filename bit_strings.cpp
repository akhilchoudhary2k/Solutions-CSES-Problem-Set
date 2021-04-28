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



int main(){

	int n;
	cin >> n;
	cout << power(2, n) << endl;
	return 0;
}

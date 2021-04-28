#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	ll n,q;
	cin >> n >> q;

	ll arr[1+n];
	for(int i=1;i<=n;i++) cin >> arr[i];

	ll pref[n+1] = {0};
	pref[1] = arr[1];
	for(int i=2;i<=n;i++) pref[i] = pref[i-1] + arr[i];

	// int q;
	// cin >> q;
	while(q--){
		int l,r;
		cin >> l >> r;
		cout << pref[r] - pref[l-1] << endl;
	}

	return 0;
}
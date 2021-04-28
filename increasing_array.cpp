#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++) cin >> arr[i];

	int ans=0;
	for(int i=1;i<n;i++){
		ans += max(0LL, arr[i-1]-arr[i]);
		arr[i] = max(arr[i-1], arr[i]);
	}
	cout << ans << endl;
	
	return 0;
}
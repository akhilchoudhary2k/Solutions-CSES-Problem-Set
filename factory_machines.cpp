#include<bits/stdc++.h>
using namespace std;

#define int long long

void test_case(){
	int n,t;
	cin >> n >> t;
	int time[n];
	for(int i=0;i<n;i++) cin>>time[i];

	int l=1, r=1e18,ans = -1;
	while(l<=r){
		int mid = l + (r-l)/2;
		int how = 0;
		for(int i=0;i<n;i++) {
			how += mid/time[i];
			if(how >= t) break;
		}

		if(how >= t){
			ans = mid;
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	cout << ans << endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int tt=1;
	// cin >> t;

	while(tt--) test_case();
	
	return 0;
}
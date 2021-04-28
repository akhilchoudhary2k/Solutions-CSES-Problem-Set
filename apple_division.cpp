#include<bits/stdc++.h>
using namespace std;
	
#define int long long
int n;
int a[20];


// int f(int done,  int A, int B){
// 	if(done == n) 
// 		return abs(A-B);

// 	int a = 
// 	return min ();
// }

void test_case(){
	cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];

	int ans = 1e9;
	for(int mask = 0 ; mask < (1<<20) ; mask ++ ){
		int x=0,y=0;
		for(int i=0;i<n;i++){
			if(mask&(1<<i)){
				x += a[i];
			}else{
				y += a[i];
			}
		}
		ans = min(ans, abs(x-y));
	}
	cout << ans << endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}
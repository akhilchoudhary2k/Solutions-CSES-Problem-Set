#include<bits/stdc++.h>
using namespace std;
#define int long long
 
void test_case(){
	// 2 3 4 8 11 15
	// 1 2 3 6
	// 1 2 3 4
	// 2 3 8
	// s = 43
	int n, sum=0;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++) cin >> a[i],sum+=a[i];
	sort(a,a+n);
	
 
	cout << max(sum, 2*a[n-1]) << endl;
 
}
 
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t=1;
	// cin >> t;
 
	while(t--) test_case();
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long

// vector<int> divisors(1000000+1);

// void test_case(){
// 	int n;
// 	cin >> n;
// 	for(int i=0;i<n;i++){
// 		long long x; cin >> x;
// 		for(long long d1=1 ; d1*d1<=x ; d1++){
// 			if(x%d1==0){
// 				divisors[d1]++;
// 				if(x/d1 != d1) divisors[x/d1]++;
// 			}
// 		}
// 	}	
// 	for(int d=1000000;d>=1;d--){
// 		if(divisors[d]>1){
// 			cout << d <<"\n";
// 			return;
// 		}
// 	}
// }

void test_case(){
	int n;
	cin >> n;

	vector<int> mp(1000000+1);
	// unordered_map<int,int> mp;
	
	int X=1;
	for(int i=0;i<n;i++){
		int x; cin >> x;
		mp[x]++;
		X = max(X,x);
	}

	for(int x=X;x>=1;x--){
		// is x the answer ?
		int cnt=0;
		for(int i=1; i*x<=X; i++){
			cnt += mp[x*i];
			if(cnt>1){
				cout << x <<"\n"; return;
			}
		}
	}

}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long

void test_case(){
	int n; cin >> n;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin >> v[i];

	// ternary search

	int left=*min_element(v.begin(), v.end());
	int right=*max_element(v.begin(), v.end());
	int ans=0;

	auto f = [&](int m){
		int ans=0;
		for(int x : v) {
			ans += abs(m-x);
		}
		return ans;
	};

	while(right-left >=2){
		int m1 = left + (right-left)/3;
		int m2 = right- (right-left)/3;
		
		if(f(m1) < f(m2)){
			right = m2-1;
		}
		else{
			left = m1+1;
		}
	}

	// handle properly the case when n<=2 ..... done

	int a = f(left);
	int b = f(left+1);
	int c = f(right);
	cout << min(a, min(b, c)) << endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}
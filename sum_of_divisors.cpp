#include<bits/stdc++.h>
using namespace std;

void test_case(){
	int n;
	cin >> n;
	int mod = 1e9+7;
	long long cnt =0;
	for(int i=1;i*i<=n;i++){
		if(n%i==0){
			cnt += 2*i;
			if(i == n/i) cnt -= i;
			cnt %= mod;
		}
	}
	cout << cnt << endl;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}
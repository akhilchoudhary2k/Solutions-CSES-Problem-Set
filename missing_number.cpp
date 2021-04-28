#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int n;
	cin >> n;
	int sum = n*(n+1)/2;
	for(int i=0;i<n-1;i++){
		int a;
		cin >> a;
		sum -= a;
	}

	cout << sum << endl;
	
	return 0;
}
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
 
#include<bits/stdc++.h>
using namespace std;

const int N = 1e9+1;
bitset<N> bset;

int main(){
	
	int n;
	cin >> n;
	bset.reset();

	int ans = 0;

	while(n--){
		int x;
		cin >> x;
		if(bset[x]==0) {
			bset[x]=1;
			ans ++;
		}
	}

	cout << ans << endl;
	
	return 0;
}
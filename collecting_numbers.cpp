#include<bits/stdc++.h>
using namespace std;
#define int long long
int inf = 1e15;

void test_case(){
	int n;
	cin >> n;
	int a[n];
	unordered_set<int> s;
	for(int i=0;i<n;i++) {
		cin >> a[i];
		if(s.count(a[i]-1)){
			s.erase(a[i]-1);
		}
		s.insert(a[i]);
	}
	cout << s.size() <<"\n";

}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}

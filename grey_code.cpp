#include<bits/stdc++.h>
using namespace std;
#define int long long


void test_case(){
	int n;
	cin >> n;

	vector<string> ans;
	ans.emplace_back("0");
	ans.emplace_back("1");


	while(ans.size() != (1<<n)){
		for(int i=ans.size()-1;i>=0;i--){
			ans.emplace_back(ans[i]);
			ans.back().push_back('1');
			ans[i].push_back('0');
		}
	}

	for(string s : ans){
		reverse(s.begin(), s.end());
		cout << s <<"\n";
	}

}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}

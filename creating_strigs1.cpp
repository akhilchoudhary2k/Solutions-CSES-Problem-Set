#include<bits/stdc++.h>
using namespace std;

void test_case(){
	string s;
	cin >> s;
	
	vector<string> ans;
	int cnt=0;
	sort(s.begin(), s.end());
	ans.push_back(s);
	cnt++;

	while( next_permutation(s.begin(), s.end()) ){
		ans.push_back(s);
		cnt++;
	}

	cout << cnt << endl;
	for(string t : ans )cout << t << endl;
		
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}
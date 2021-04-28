#include<bits/stdc++.h>
using namespace std;

void test_case(){
	string s;
	cin >> s;
	unordered_map<char,int> mp;
	for(char x : s) mp[x]++;
	
	char odd_ch = 0;
	map<char,int> mp2;

	for(auto x : mp){
		if( (x.second&1) ){
			if(odd_ch==0 && (s.size()&1) ) odd_ch=x.first;
			else{cout <<"NO SOLUTION\n"; return;}
		}
		mp2[x.first] += x.second/2;
	}

	string ans="";
	for(auto x : mp2){
		while(x.second--){
			ans += x.first;
		}
	}

	cout << ans;
	if(odd_ch!=0) cout << odd_ch;
	reverse(ans.begin(), ans.end());
	cout << ans << endl;

}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}
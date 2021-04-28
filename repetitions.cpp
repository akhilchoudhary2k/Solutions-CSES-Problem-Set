#include<bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	string s;
	cin >> s;
	int ans=1;

	int i=0;
	int n = s.length();
	for(int i=0;i<n;i++){
		int j=i;
		while(j<n && s[j]==s[i]) j++;
		ans = max(ans, j-i);
		i = j-1;
	}
	cout << ans << endl;
	
	return 0;
}
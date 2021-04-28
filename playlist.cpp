#include<bits/stdc++.h>
using namespace std;

void test_case(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin >> v[i];

	int i=0, j=0;
	int len=0, maxlen=0;

	set<int> s;

	while(i<n){

		while(j<n && s.count(v[j])==0 ){
			s.insert(v[j]);
			len++;
			j++;
			maxlen = max(maxlen, len);
		}

		s.erase(v[i]);
		len--;
		i++;
	}

	cout << maxlen << endl;

}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

void test_case(){
	int n,x;
	cin >> n >> x;
	vector<pair<int,int>> v(n);
	for(int i=0;i<n;i++) {
		cin >> v[i].first;
		v[i].second = i;
	}

	sort(v.begin(), v.end());
	
	int i=0,j=n-1;
	while(i<j){
		if(v[i].first+v[j].first==x){
			cout << 1+v[i].second << " " << 1+v[j].second << endl;
			return;
		}
		else if(v[i].first+v[j].first<x) i++;
		else j--;
	}

	cout <<"IMPOSSIBLE"<<endl;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long

void test_case(){
	int n,x;
	cin >> n >> x;
	vector<pair<int,int>> v(n+1);
	for(int i=1;i<=n;i++){
		int a;
		cin >> a;
		v[i] = {a,i};
	}
	v[0]={-1,-1};
	sort(v.begin(), v.end());

	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			// j+1 to n 
			int req = x - v[i].first - v[j].first;
			if(req<=0) break;
			pair<int,int> pp = {req,0};
			auto p = lower_bound(v.begin()+j+1, v.end(), pp);
			if(p!= v.end() && p->first == req){
				// cout <<"p = {" << p->first<<","<<p->second<<"}\n";
				cout << v[i].second <<" "<<v[j].second<<" "<<p->second<<'\n';
				return ;
			}
		}
	}

	cout <<"IMPOSSIBLE\n";
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}
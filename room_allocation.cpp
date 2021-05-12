#include<bits/stdc++.h>
using namespace std;
#define int long long

// first see starting(not ending) at some day

void test_case(){
	int n;
	cin >> n;
	vector<array<int,3>> v;
	for(int i=0;i<n;i++){
		int x,y;
		cin >> x >> y;
		v.push_back({x,0,i});
		v.push_back({y,1,i});
	}
	sort(v.begin(), v.end());
	vector<int> ans(n);
	
	set<int> free;
	free.insert(1);
	int mx = 1;

	for(auto x : v){
		int who = x[2];
		if(x[1]==0){
			int temp;
			if(free.size()>0){
				temp = *free.begin();
				free.erase(free.begin());
			}else{

				temp = ++mx;
			}
			ans[who] = temp;
		}
		else{
			free.insert(ans[who]);
		}
	}

	cout << mx <<"\n";
	for(int x : ans) cout << x <<" "; cout <<"\n";

}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}

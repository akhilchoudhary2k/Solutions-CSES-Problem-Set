#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")

#include<bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int n, cnt=0, num;
	cin >> n;
	map<int,int> mp;
	
	for(int i=0;i<n;i++){
		cin >> num;
		auto it = mp.upper_bound(num); 
		if(it!=mp.end()){
			it->second--;
			if(it->second == 0) mp.erase(it);
		} else{
			cnt++;
		}
		mp[num]++;
	}


	cout << cnt << endl;
	
	return 0;
}

// 54321
// 843
// 7
// 7
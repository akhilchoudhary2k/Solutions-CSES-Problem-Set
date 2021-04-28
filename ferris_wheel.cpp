#include<bits/stdc++.h>
using namespace std;

// TIME COMPLEXITY = O(N*logN)

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	multiset<int> s;
	int n,x;
	cin >> n >> x;
	for(int i=0;i<n;i++) {
		int a;
		cin >> a;
		s.insert(a);
	}

	int total=0, reqd=0;
	
	while(total<n){
		if(s.size()==1){
			reqd++; break;
		}
		int last = *(s.rbegin()), vacant = x-last;

		auto it = s.upper_bound(vacant);
		if(it == s.begin()) {
			total++;
		} else{
			it--;
			total+=2;
			s.erase(it);
		}
		reqd++;
		s.erase(-- s.end());
	}
	cout << reqd << endl;
	return 0;
}

// x=10
// 2 3 7 9
// 2 3 5 7 8

// 1 2 3
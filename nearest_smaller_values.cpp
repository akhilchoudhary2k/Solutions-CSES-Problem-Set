#include<bits/stdc++.h>
using namespace std;

// time complexity = O(N) per test case

void test_case(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin >> v[i];
	stack<int> st;
	st.push(0);
	cout << 0 << " ";
	for(int i=1;i<n;i++){
		while(!st.empty() && v[st.top()]>=v[i] ) st.pop();
		if(st.empty()) cout << 0 << " ";
		else cout << st.top()+1 << " ";
		st.push(i);
	}
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}
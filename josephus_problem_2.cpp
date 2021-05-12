#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

signed main(){

	int n,k;
	cin >> n >>k;
	int p = k%n;
	oset<int> st;

	for(int i=1;i<=n;i++) st.insert(i);

	while(st.size()){
		int which = *st.find_by_order(p);
		cout << which <<" ";
		// IMPORTANT :
		// first erase then find the next position 
		st.erase(which);
		if(st.size() > 0){
			p = (p+k)%st.size();
		}
	}
	cout <<"\n";

	return 0;
}
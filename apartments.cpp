#include<bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int n,m,k;
	cin >> n >> m >> k;
	int req[n];
	for(int i=0;i<n;i++) cin >> req[i];
	int aprt[m];
	for(int i=0;i<m;i++) cin >> aprt[i];

	sort(req, req+n);
	sort(aprt, aprt+m);
	for(int i=0;i<n;i++) cout << req[i] << " "; cout << endl;
	for(int j=0;j<m;j++) cout << aprt[j]<< " "; cout << endl;

	int total=0;
	int start=0;

	for(int i=0;i<n;i++){
		int ind = lower_bound(aprt+start, aprt+m, req[i]-k ) - aprt;
		if( ind==m || aprt[ind] > req[i]+k) continue;
		start = ind+1;
		total ++;
	}
	cout << total << endl;
	
	return 0;
}

// 45 60 60 80 85
// 30 60 75 90
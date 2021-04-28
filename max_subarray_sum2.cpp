#include<bits/stdc++.h>
using namespace std;
#define int long long

wrong answer

int *arr, n, a, b;

int sum(int m){
	int maxi=LONG_MIN, temp=0;
	for(int i=0;i<m;i++) temp+=arr[i];
	maxi = max(maxi, temp );
	
	for(int i=m; i<n ; i++){
		temp += arr[i];
		temp -= arr[i-m];
		maxi = max(maxi, temp );	
	}

	// 0 1 2 3 4 5 6 7 8 9
	
	return maxi;
}

void test_case(){

	cin >> n >> a >> b;
	arr = new int[n];
	for(int i=0;i<n;i++) cin >> arr[i];

	// TERNARY SEARCH

	if(a == b){
		cout << sum(a) << endl;
		return;
	}

	int left=a, right=b;
	while(right-left >=3){
		int m1 = left + (right-left)/3;
		int m2 = right - (right-left)/3;
		// cout << "sum(" << m1<<") = " << sum(m1);
		// cout << " sum(" << m2<<") = " << sum(m2) << endl;
		if(sum(m1)>sum(m2)){
			right = m2;
		}
		else{
			left = m1;
		}
	}

	int A = sum(left);
	int B = sum(left+1);
	int C = sum(right);
	cout << max(A, max(B, C)) << endl;

}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}
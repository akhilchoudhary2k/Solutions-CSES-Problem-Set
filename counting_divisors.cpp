#include<bits/stdc++.h>
using namespace std;

void test_case(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		int cnt=0;
		for(int j=1;j*j<=a;j++){
			if(a%j==0) {
				cnt+=2;
				if(j == a/j) cnt--;
			}
		}
		cout << cnt << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}
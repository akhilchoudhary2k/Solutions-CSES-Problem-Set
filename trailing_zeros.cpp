#include<bits/stdc++.h>
using namespace std;

void test_case(){

}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int n;
	cin >> n;

	int ans=0;
	int m = n/5;
	while(m){
		ans += m;
		m /= 5;
	}
	cout << ans << endl;
	
	return 0;
}
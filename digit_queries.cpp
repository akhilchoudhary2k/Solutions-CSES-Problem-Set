#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long

int cnt_digit(int n){
	int ans=0;
	while(n>0){
		ans++;
		n/=10;
	}
	return ans;
}

void test_case(){
	int n;
	cin >> n;

	int dig[20];
	int p=0;

	dig[0]=0;
	for(int x=1;x<=18;x++){
		int c = p + 9ll * pow(10ll, x-1)*x;
		dig[x] = c;
		p=c;
	}

	int l = 1, r = 1e18 , ans = -1;
	while(l<=r){
		int m = (l+r)/2;
		// cout <<"m:" << m;
		int d = cnt_digit(m);

		int before = dig[d-1] + d*(m - pow(10ll, d-1));
		
		if(n>before && n<=before+d){
			string st = to_string(m);
			// cout <<"found \n";
			cout << st[n-before-1] << endl;

			break;
		}
		else if(n<=before){
			// cout <<" left\n";
			r=m-1;
		}
		else{
			l=m+1;
			// cout <<" right\n";
		}
	}


}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t=1;
	cin >> t;

	while(t--) test_case();
	
	return 0;
}
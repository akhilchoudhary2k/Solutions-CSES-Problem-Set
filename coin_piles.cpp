#include<bits/stdc++.h>
using namespace std;

void test_case(){
	int a,b;
	cin >> a >> b;
	if(a>b) swap(a,b);

	int dif = b-a;

	if(b>2*a) cout << "NO" << endl;
	else{
		a -= dif;
		b -= 2*dif;
		if(a==b && a>=0 && b>=0 && a%3==0 && b%3==0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

}

int main(){
	int t=1;
	cin >> t;

	while(t--) test_case();
	
	return 0;
}

// 7 6 5 
// 9 7 5
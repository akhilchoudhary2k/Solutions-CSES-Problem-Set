#include<bits/stdc++.h>
using namespace std;

void test_case(){
	int n;
	cin >> n;
	int s = (n*(n+1))/2;
	if(s&1){
		cout <<"NO"<<endl;
		return;
	}

	cout << "YES" << endl;
	vector<int> A,B;

	int f=0;
	for(int i=n;i>0;i-=2){
		int a=i, b=i-1; 
		if(f) swap(a,b);
		if(a!=0) A.push_back(a);
		if(b!=0) B.push_back(b);
		f^=1;
	}

	cout << A.size() << endl;
	for(int a : A) cout << a << " ";
	cout << endl;

	cout << B.size() << endl;
	for(int a : B) cout << a << " ";
	cout << endl;

}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
	ifstream f;
	ofstream o;
	f.open("in");
	o.open("int");
	int n;
	f >> n;
	int arr[n];
	// cout << n << endl;
	for(int i=0;i<n;i++) f >> arr[i];
	sort(arr, arr+n);

	o << n << endl;
	for(int i=0;i<n;i++) o << arr[i] << " ";

	return 0;
}
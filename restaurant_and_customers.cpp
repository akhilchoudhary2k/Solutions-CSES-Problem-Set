#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> a , pair<int,int> b){
	if(a.first==b.first) return a.second>b.second;
	else return a.first < b.first;
}

void test_case(){
	int n;
	cin >> n;
	vector<pair<int,int>> arr;
	for(int i=0;i<n;i++){
		int a,b;
		cin >> a >> b;
		arr.push_back({a, 1});
		arr.push_back({b, -1});
	}

	sort(arr.begin(), arr.end(), comp);

	int maxi=0;
	int temp=0;
	for(auto x : arr){
		temp += x.second;
		maxi = max(temp, maxi);
	}

	cout << maxi << endl;
}

int main(){
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}


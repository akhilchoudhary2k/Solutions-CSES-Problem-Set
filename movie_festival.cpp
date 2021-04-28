#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> a, pair<int,int> b){
	return a.second < b.second;
}

int main(){
	int n;
	cin >> n;
	pair<int,int> arr[n];
	for(int i=0;i<n;i++){
		int s,f;
		cin >> s >> f;
		arr[i] = {s, f};
	}
	
	sort(arr, arr+n, comp);
	
	int cnt=1;
	int last_finish = arr[0].second;
	for(int i=1;i<n;i++){
		if(arr[i].first>=last_finish){
			cnt++;
			last_finish = arr[i].second;
		}
	}
	
	cout << cnt << endl;
	
	return 0;
}

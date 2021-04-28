#include<bits/stdc++.h>
using namespace std;

	wrong answer .....

void test_case(){
	int n;
	cin >> n;

	// 1-> arrival, 2-> departure
	
	vector< pair<int,int> > v;
	
	for(int i=0;i<n;i++){
		int a,b;
		cin >> a >> b;
		v.push_back({a, 1});
		v.push_back({b, 2});
	}

	sort(v.begin(), v.end());

	int req=0, curr=0;;
	deque<int> taken;
	deque<int> free;
	vector<int> ans;

	for(auto x : v){
		if(x.second == 2){
			curr--;
			free.push_back(taken.front());
			taken.pop_front();
			// free.insert(*taken.begin());
			// taken.erase(taken.begin());
		}
		else{
			curr++;
			if(!free.empty()){
				ans.push_back(free.front());
				taken.push_back(free.front());
				free.pop_front();
				// taken.insert(*free.begin());
				// free.erase(free.begin());
			}
			else {
				ans.push_back(curr);
				taken.push_back(curr);
				// taken.insert(curr);
			}
		}
		req = max(req, curr);
	}
	cout << req << endl;
	for(int a : ans ) cout << a << " ";
	cout << endl;

}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}
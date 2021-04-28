#include<bits/stdc++.h>
using namespace std;

set<int> position; // will save the positions of lights added till now
map<int,int> heap; // will save the max length till now

int getmax(){
	if(heap.empty()) return 0;
	auto it = heap.rbegin();
	return it->first;
}

int main(){

	int x,n;
	cin >> x >> n;
	
	position.insert(0);
	position.insert(x);
	heap[x]++;

	for(int i=0;i<n;i++){

		// left means the nearest light towards left fo current added light simillarly right
		int left, right, num;
		cin >> num;
		
		auto it2 = position.lower_bound(num);
		if(it2 == position.begin()) left = num;
		else {
			it2--;
			left = *it2;
		}

		auto it3 = position.upper_bound(num);
		if(it3 == position.end()) right = num;
		else{
			right = *it3;
		}

		position.insert(num);

		int curmax = getmax();
		int a = num - left;
		int b = right - num;
		int larger = max(a,b);
		int curlen = right - left;

		// cout << "i=" << i << " left=" << left << " right=" << right << endl;
		// cout <<"maxheap:" ;
		// for(auto x : heap) cout << "(" << x.first << "," << x.second << ") "; cout << endl;
		// cout << "curlen=" << curlen << " curmax=" << curmax << endl;
 

		if(curlen == curmax){

			heap[curmax]--;
			if(heap[curmax] == 0) heap.erase(curmax);
			int newcurmax = getmax();
			cout << max( larger , newcurmax ) << " ";
			
		}
		else{ 
			cout << curmax << " ";
			heap[curlen]--;
			if(heap[curlen] == 0) heap.erase(curlen);
		}

		heap[a]++;
		heap[b]++;
	}
 

	return 0;
}
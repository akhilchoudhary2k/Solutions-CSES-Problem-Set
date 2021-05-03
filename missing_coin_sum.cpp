#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main() {
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    
    sort(a,a+n);
    // if(a[0]!=1) {
    //     cout <<"1\n"; return 0;
    // }
    int p=0;
    for(int i=0;i<n;i++){
        if(a[i] > p+1){
            cout << p+1 <<"\n"; return 0;
        }
        p+= a[i];
    }
    cout << p+1;
    
	return 0;
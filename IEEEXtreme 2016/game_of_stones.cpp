#include <bits/stdc++.h>

using namespace std;

int main(){
	long long t,n,p,alice,bob;
	cin >> t;
	while(t--){
		alice = 0;
		bob = 0;
		cin >> n;
		int res=0;
		for(int i=0; i<n; i++){
			cin >> p;
			for(int j=0; j<p; j++){
				int k;
				cin >> k;
				k = k/2;
				k = k%2;
				res+=k;
				res= res%2;
			}
		}
		res = res%2;
		if(res) cout << "Alice" << endl;
		else cout << "Bob" << endl;
	}
}
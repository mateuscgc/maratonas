#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n,l;
	cin >> n >> l;
	int v[n];	
	for(int i=0; i<n; i++) cin >> v[i];
	int mmc = (v[0]*v[1])/__gcd(v[0], v[1]);
	for(int i=2; i<n; i++){
		mmc = (mmc*v[i])/__gcd(mmc, v[i]);
	}
	int best = mmc, ans=1;	
	for(int i=1; i<=l; i++){
		int aux = (mmc*i)/__gcd(mmc,i);
		if(aux > best && aux <= l){
			best = aux;
			ans = i;
		}
	}
	cout << ans << endl;
}

#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

bool prime(int n){
	if(n == 2) return true;
	if(n%2 == 0) return false;
	for(int i=3; i<=sqrt(n); i+=2){
		if(n%i == 0) return false;
	}
	return true;
}

int f(int n, int k){
	int c[k+10];
	memset(c, 0, sizeof c);
	c[0] = 1;
	for(int i=1; i<=n; i++){
		for(int j=min(i,k); j>0; j--){
			c[j] = c[j]+c[j-1];
		}
	}
	return c[k];
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long n;
	cin >> n;
	bool flag = true;
	for(int i=3; i<=sqrt(n); i+=2){
		if(n%i == 0){
			flag = false;
			break;
		}
	}
	if(flag || n == 2){
		cout << 0 << endl;
		return 0;
	}
	
	int cont = 0;
	for(int i=2; i<=sqrt(n); i++){
		if(n % i == 0){
			if(prime(i)){
				cont++;
				//cout << i << endl;
			}
			if(prime(n/i)){
				cont++;
				//cout << n/i << endl;
			}
		}
	}
	int ans = 0;
	for(int i=2; i<=cont; i++) ans += f(cont,i);
	cout << ans << endl;
	
}



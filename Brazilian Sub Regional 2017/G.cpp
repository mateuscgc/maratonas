#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
int dp[51][100001];

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t,l,r;
	cin >> t >> l >> r;
	
	for(int i=0; i<=t; i++){
		for(int j=0; j<=r; j++) dp[i][j] = 0;
	}
	for(int i=l; i<=r; i++){
		dp[1][i] = 1;
	}
		
	for(int i=1; i<= t-1; i++){
		for(int j=l; j<=r; j++){
			if(j != l){
				dp[i+1][j-1] += dp[i][j];
				dp[i+1][j-1]%=(int)1e9+7;
			}
			if(j != r){
				dp[i+1][j+1] += dp[i][j];
				dp[i+1][j+1]%=(int)1e9+7;
			}
		}
	}	
	int ans = 0;
	for(int i=l; i<=r; i++){
		ans += dp[t][i];
		ans %=(int)1e9+7;
	}
	cout << ans << endl;
}
	

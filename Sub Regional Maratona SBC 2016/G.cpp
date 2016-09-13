#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

#define F first
#define S second

int main() {
    int n, p;
    cin >> n >> p;

    pair<int, int> dp[n][n];
    memset(dp, 0, sizeof dp);
    for(int i = 0; i < p; i++) {
        int y,x; cin >> y >> x;
        dp[y-1][x-1].F = 1;
    }
    for(int i = 0; i < p; i++) {
        int y,x; cin >> y >> x;
        dp[y-1][x-1].S = 1;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i > 0) { dp[i][j].F += dp[i-1][j].F; dp[i][j].S += dp[i-1][j].S; }
            if(j > 0) { dp[i][j].F += dp[i][j-1].F; dp[i][j].S += dp[i][j-1].S; }
            if(i > 0 && j > 0) { dp[i][j].F -= dp[i-1][j-1].F; dp[i][j].S -= dp[i-1][j-1].S; }
        }
    }



    int ans_b = p;
    int ans_p = p;
    for(int l = 2; l <= n; l++) {
        for(int i = l-1; i < n; i++) {
            for(int j = l-1; j < n; j++) {
                pair<int,int> cur = dp[i][j];
                if(i >= l) { cur.F -= dp[i-l][j].F; cur.S -= dp[i-l][j].S; }
                if(j >= l) { cur.F -= dp[i][j-l].F; cur.S -= dp[i][j-l].S; }
                if(i >= l && j >= l) { cur.F += dp[i-l][j-l].F; cur.S += dp[i-l][j-l].S; }
                if(cur.F > 0 && cur.S == 0) ans_p++;
                else if(cur.S > 0 && cur.F == 0) ans_b++;
            }
        }
    }

    cout << ans_p << " " << ans_b << "\n";

    return 0;
}

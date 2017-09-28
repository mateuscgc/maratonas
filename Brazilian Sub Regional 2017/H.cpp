#include <bits/stdc++.h>
#define endl '\n'
#define Y first
#define X second
using namespace std;
typedef pair<int, int> point;

int cross(point a, point b, point c) {
	point vec = point(a.X-c.X, a.Y-c.Y);
	point vec2 = point(b.X-c.X, b.Y-c.Y);
	return vec.X*vec2.Y - vec.Y*vec2.X;
}

bool good(point p2, point p1, point a, point b) {
	return (cross(p2, p1, a) > 0 && cross(p2,p1,b) < 0);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, xa, xb;
	cin >> n >> xa >> xb;

	
	point p[n];
	for(int i = 0; i < n; i++) {
		cin >> p[i].X >> p[i].Y;
	}

	sort(p, p+n);

	int dp[n];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;

	for(int i = 0; i < n; i++) {
		dp[i] = 1;
		for(int j = i-1; j >= 0; j--) {
			if(good(p[i], p[j], point(0, xa), point(0, xb))) {
				dp[i] = max(dp[j]+1, dp[i]);
			}
		}
	}

	int ans = 0;
	for(int i = 0; i < n; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;

}


#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;

	for(int t = 1; t <= T; t++) {
		int n,m;
		cin >> n >> m;

		int pies[n][m];
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				cin >> pies[i][j];
			}
			sort(pies[i], pies[i]+m);
		}

		int cur[n];
		memset(cur, 0, sizeof(cur));

		int ans = 0;
		for(int p = 0; p < n; p++) {
			int bi, bj, cost = 10000000;
			for(int i = 0; i <= p; i++) {
				if(cur[i] < m && (i == 0 || pies[i][cur[i]] + (cur[i]+1)*(cur[i]+1) - (cur[i])*(cur[i]) < cost)) {
					bi = i;
					bj = cur[i];
					//cout << i << " " << cur[i] << endl;
					cost = pies[i][cur[i]] + (cur[i]+1)*(cur[i]+1) - (cur[i])*(cur[i]);
				}
			}
			//cout << bi << " " << bj << endl;
			//cout << (cur[bi]+1)*(cur[bi]+1) - (cur[bi])*(cur[bi]) <<  endl;
			//cout << cost << endl << endl;
			ans += cost;
			cur[bi]++;
		}

		cout << "Case #" << t << ": " << ans << endl;
	}
}

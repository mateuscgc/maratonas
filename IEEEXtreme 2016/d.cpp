#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while(t--) {
		int n;
		cin >> n;
		int c[n];
		for(int i = 0; i < n; i++) cin >> c[i];

		int b1 = -1;
		int b2 = -1;

		int ans = 0;
		for(int i = 0; i < n; i++) {
			if(b1 != c[i] && b2 != c[i]) {
				int j;
				for(j = i+1; j < n; j++) {
					if(b1 == c[j]) {
						b2 = c[i];
						ans++;
						break;
					} else if(b2 == c[j]) {
						b1 = c[i];
						ans++;
						break;
					}
				}
				if(j == n) {
					b2 = c[i];
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
}
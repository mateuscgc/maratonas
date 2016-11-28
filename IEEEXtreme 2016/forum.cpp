#include <bits/stdc++.h>

using namespace std;

int main() {

	int ppp, np;
	while(cin >> ppp >> np) {
		int posts[np];
		int sz[np]; for(int i = 0; i < np; i++) sz[i] = 0;
		int nexqt[np]; for(int i = 0; i < np; i++) nexqt[i] = 0;
		for(int i = 0; i < np; i++) {
			cin >> posts[i];
			if(posts[i] == 0) {
				sz[i]++;
				posts[i] = i;
			} else {
				// cout << posts[posts[i]-1] << endl;
				sz[posts[posts[i]-1]]++;
				posts[i] = posts[posts[i]-1];
			}
		}

		int pag_s = 0;
		int pag_s2 = 0;
		int ans = -1;
		// cout << ppp << " " << np << endl;
		for(int i = 0; i < np; i++) {
			if(posts[i] == i) {
				int po_s = sz[i];
				// cout << pag_s << endl;
				// cout << "--> " << po_s << endl;
				if(pag_s + po_s - ppp <= ppp - pag_s || pag_s == 0) {
					pag_s += po_s;
				} else {
					ans = max(ans, abs(ppp - pag_s));
					i--;
					pag_s = 0;
				}
			}
		}
		cout << ans << endl;
	}
}
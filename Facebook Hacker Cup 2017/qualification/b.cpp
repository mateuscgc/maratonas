#include <bits/stdc++.h>

using namespace std;


int main() {

	int T;
	cin >> T;

	for(int t = 1; t <= T; t++) {
		int n;
		cin >> n;

		vector<int> items;
		for(int i = 0; i < n; i++) {
			int num; cin >> num;
			items.push_back(num);
		}

		sort(items.begin(), items.end());

		int ini = 0, end = items.size()-1;

		int ans = 0;
		while(ini <= end) {
			// cout << items[end] << endl;
			int needed = (50+items[end]-1)/items[end--] - 1;
			// cout << needed << endl;
			if(ini+needed-1 <= end) {
				ini += needed;
				ans++;
			} else
				break;
		}

		cout << "Case #" << t << ": " << ans << endl;
	}
}
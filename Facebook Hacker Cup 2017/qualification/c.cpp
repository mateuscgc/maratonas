#include <bits/stdc++.h>

using namespace std;


int main() {

	int T;
	cin >> T;

	for(int t = 1; t <= T; t++) {
		
		int h, s;
		cin >> h >> s;

		double ans = 0;
		for(int i = 0; i < s; i++) {
			string spell;
			cin >> spell;

			int d = spell.find('d');
			int x = stoi(spell.substr(0, d));
			int y = stoi(spell.substr(d+1, 2));

			cout << x << " " << y;

			int p = spell.find_first_of("+-");

			int ini = x, end = x*y;
			if(p != string::npos) {
				int z = stoi(spell.substr(p, 5));
				ini += z;
				end += z;
				cout << " " << z;
			}
			cout << endl;
			
			cout << ini << " " << end << endl;
			cout << h << endl;

			double rangeD = end - ini + 1;
			double rangeK = (h <= end) ? rangeD - (max(ini, h) - ini) : 0;
			cout << rangeK << "/" << rangeD << endl;
			// double rangeD = x*(y - 1) + 1;
			// double rangeK = (h <= x*y) ? rangeD - (max(x, h) - x) : 0;
			cout << rangeK/rangeD << endl;
			ans = max(ans, rangeK/rangeD);
		}

		cout << "Case #" << t << ": " << ans << endl;
	}
}
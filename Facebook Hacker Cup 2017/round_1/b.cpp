#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

pair<int, int> zobs[50];
vector < pair<int, int> > gru[50];
vector < pair<int, int> > final[2500];

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.Y < b.Y;
}

int main() {
	int T;
	cin >> T;

	for(int t = 1; t <= T; t++) {
		int n,r;
		cin >> n >> r;
		//cout << n << " " << r << endl;


		for(int i = 0; i < n; i++) {
			int x,y;
			cin >> zobs[i].X >> zobs[i].Y;
			//cout << zobs[i].X << " " << zobs[i].Y << endl;
		}

		sort(zobs, zobs+n);

		for(int i = 0; i < 50; i++) gru[i].clear();

		for(int i = 0; i < n; i++) {
			for(int j = i; j < n; j++) {
				if(zobs[j].X - zobs[i].X <= r) {
					gru[i].push_back(zobs[j]);
				}
			}
		}

		for(int i = 0; i < 2500; i++) final[i].clear();


		int f = -1;
		for(int i = 0; i < n; i++) {
			sort(gru[i].begin(), gru[i].end(), cmp);
			//cout << "=======" << endl;
			//for(int j = 0; j < gru[i].size(); j++) cout << gru[i][j].X << " " << gru[i][j].Y << endl;
			//cout << "=======" << endl;
			for(int j = 0; j < gru[i].size(); j++) {
				f++;
				for(int k = j; k < gru[i].size(); k++) {
					if(abs(gru[i][k].Y - gru[i][j].Y) <= r) {
						final[f].push_back(gru[i][k]);
					}
				}
			}
		}

		//cout << "bla" << endl;


		int best;
		for(int i = 0; i <= f; i++) {
			if(i == 0 || final[i].size() > final[best].size()) {
				best = i;
			}
			//for(int j = 0; j < final[i].size(); j++) {
			// 	cout << "(" << final[i][j].X << ", " << final[i][j].Y << ")" << " ";
			//}
			//cout << endl;
		}

		set< pair<int, int> > bla;
		for(int i = 0; i < final[best].size(); i++) {
			bla.insert(final[best][i]);
		}

		int ans = -1;
		for(int i = 0; i <= f; i++) {
			set< pair<int, int> > bla2 = bla;
			for(int j = 0; j < final[i].size(); j++) {
				bla2.insert(final[i][j]);
			}
			ans = max(ans, (int)bla2.size());
		}

		cout << "Case #" << t << ": " << ans << endl;
	}
}

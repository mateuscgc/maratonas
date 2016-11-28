#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
#define A first
#define C second

struct State {
	int city, fuel, spent;
};

map<string, int> cities;
int fuels[51];
vector<ii> adj[51];


int main() {

	int t; cin >> t;

	while(t--) {
		int n; cin >> n;

		for(int i = 0; i < n; i++) {
			string city; cin >> city;
			cities[city] = i;
			int fuel; cin >> fuel;
			fuels[i] = fuel;
		}

		int m; cin >> m;
		for(int i = 0; i <= n; i++) adj[i].clear();
		for(int i = 0; i < m; i++) {
			string a,b; cin >> a >> b;
			int cost; cin >> cost;
			adj[cities[a]].push_back(ii(cities[b], cost));
			adj[cities[b]].push_back(ii(cities[a], cost));
		}


		queue<State> q; q.push({cities["start"], 0, 0});

		int best = 10000;

		while(!q.empty()) {
			State cur = q.front(); q.pop();
			cur.fuel += fuels[cur.city];
			cur.fuel = min(cur.fuel, 100);

			if(cur.city == cities["end"]) {
				best = min(best, cur.spent);
			} else {
				for(int i = 0; i < adj[cur.city].size(); i++) {
					if(cur.spent + adj[cur.city][i].C <= 200 && cur.fuel >= adj[cur.city][i].C) { // Talvez cortar essa chamada pelo menor custo
						q.push({ adj[cur.city][i].A, cur.fuel, cur.spent + adj[cur.city][i].C });
					}
				}
			}
		}

		if(best == 10000)
			cout << "Impossible" << endl;
		else
			cout << best << endl;
	}
}
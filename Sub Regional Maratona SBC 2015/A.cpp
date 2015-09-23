#include <bits/stdc++.h>

using namespace std;

int dist[10001];

struct cmp {
	bool operator()(const int& lhs, const int& rhs) {
		return dist[lhs] > dist[rhs];
	}
};

int main() {
	int c, v;
	scanf("%d%d", &c, &v);
	
	int pDist[c+1];
	int iDist[c+1];
	for (int i = 1; i <= c; i++) {
		dist[i] = 0x3f3f3f3f;
		pDist[i] = 0x3f3f3f3f;
		iDist[i] = 0x3f3f3f3f;
	}
	
	vector < pair <int, int> > adj[c+1];
	for (int i = 0; i < v; i++) {
		int a, b, g;
		scanf("%d%d%d", &a, &b, &g);
		adj[a].push_back(make_pair(b, g));
		adj[b].push_back(make_pair(a, g));
	}
	
	priority_queue <int, vector<int>, cmp> pq;
	
	dist[1] = 0;
	pDist[1] = 0;
	pq.push(1);
	
	
	while (!pq.empty()) {
		int curr = pq.top();
		//printf("\ncurr %d\n", curr);
		pq.pop();
		for (int i = 0; i < adj[curr].size(); i++) {
			pair <int, int> ad = adj[curr][i];
			if (iDist[curr] + ad.second < pDist[ad.first]) {
				pDist[ad.first] = iDist[curr] + ad.second;
				pq.push(ad.first);
				//printf("pDist %d\n", pDist[ad.first]);
			} else if (pDist[curr] + ad.second < iDist[ad.first]) {
				iDist[ad.first] = pDist[curr] + ad.second;
				pq.push(ad.first);
				//printf("iDist %d\n", iDist[ad.first]);
			}
			//printf("p -> %d --- i -> %d\n", pDist[ad.first], iDist[ad.first]);
			if(dist[ad.first] != min(pDist[ad.first], iDist[ad.first])) {
				dist[ad.first] = min(pDist[ad.first], iDist[ad.first]);
			}
		}
	}
	
	if (pDist[c] == 0x3f3f3f3f) {
		printf("-1\n");
	} else {
		printf("%d\n", pDist[c]);
	}
	//printf("--> %d\n", dist[c]);
	
	return 0;
}

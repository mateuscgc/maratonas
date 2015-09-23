#include <bits/stdc++.h>

using namespace std;

int main() {
	
	int n;
	scanf("%d", &n);
	
	int pos[n/2+1][2];
	for (int i = 1; i <= n/2; i++) {
		pos[i][0] = 0;
		pos[i][1] = 0;
	}
	
	for (int i = 1; i <= n; i++) {
		int aux;
		scanf("%d", &aux);
		if (!pos[aux][0]) {
			pos[aux][0] = i;
		} else {
			pos[aux][1] = i;	
		}
	}
	
	vector <int> adj[n+1];
	for (int i = 0; i < n-1; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	int dist[n+1];
	for (int i = 1; i <= n; i++) {
		dist[i] = -1;
	}
	int parent[n+1];
	
	dist[1] = 0;
	parent[1] = -1;
	queue <int> q;
	
	q.push(1);
	
	while(!q.empty()) {
		int curr = q.front();
		q.pop();
		
		for (int i = 0; i < adj[curr].size(); i++) {
			int ad = adj[curr][i];
			if (dist[ad] == -1) {
				dist[ad] = dist[curr]+1;
				parent[ad] = curr;
				q.push(ad);
			}
		}
	}
	
	int result = 0;
	for (int i = 1; i <= n/2; i++) {
		int a = pos[i][0], b = pos[i][1];
		while(a != b) {
			if (dist[a] > dist[b]) {
				a = parent[a];
			} else {
				b = parent[b];
			}
		}
		result += dist[pos[i][0]] + dist[pos[i][1]] - 2*dist[a];
	}
	
	printf("%d\n", result);
	
	return 0;
}

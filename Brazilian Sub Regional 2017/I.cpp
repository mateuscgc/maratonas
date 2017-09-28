#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int cap[11234];
vector<int> adj[11234];
vector<int> adj_cost[11234];
int vis[11234];

int n,k;
int ans;

void resolve_ae_bichao(int u){
	//cout << "entrou em " << u << endl;
	vis[u] = 1;
	int cont = 0;
	for(int i=0; i<adj[u].size(); i++){
		int v = adj[u][i];
		if(!vis[v]){
			resolve_ae_bichao(v);
			cont++;
		}
	}
	if(cont == 0){
		vis[u] = 2;
		return;
	}
	
	for(int i=0; i<adj[u].size(); i++){
		int v = adj[u][i];
		if(vis[v] != 2) continue;
		int aux = cap[v]/k + (cap[v] % k != 0);
		//cout << "de " << u << " para " << v << endl;
		//cout << aux << endl;
		ans += aux*adj_cost[u][i]*2;
		cap[u] += cap[v];
	}
	vis[u] = 2;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
		
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		cin >> cap[i];
		vis[i] = 0;
	}
	
	for(int i=0; i<n-1; i++){
		int u,v,c;
		cin >> u >> v >> c;
		adj[u].push_back(v);
		adj[v].push_back(u);
		adj_cost[u].push_back(c);
		adj_cost[v].push_back(c);
	}
	
	ans = 0;
	resolve_ae_bichao(1);
	cout << ans << endl;
}

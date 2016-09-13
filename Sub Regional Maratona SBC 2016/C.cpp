#include <bits/stdc++.h>

using namespace std;

#define D second
typedef vector<int> vi;

struct Cmp {
    bool operator()( pair<vi, int> a, pair<vi, int> b) {
        return a.D > b.D;
    }
};

int main() {

    map<vi, int> dist;
    map<vi, int> vis;
    vi ini;
    for(int i = 0; i < 8; i++) {
        int aux; cin >> aux;
        ini.push_back(aux);
    }

    vi final;
    for(int i = 0; i < 8; i++) {
        int aux; cin >> aux;
        final.push_back(aux);
    }

    dist[ini] = 0;
    vis[ini] = 1;
    priority_queue< pair<vi, int>, vector< pair<vi, int> >,  Cmp> pq; pq.push(pair<vi, int>(ini, dist[ini]));
    while(vis.find(final) == vis.end()) {
        pair<vi, int> cur = pq.top(); pq.pop();
        if(cur.D > dist[cur.first]) continue;
        vis[cur.first] = 1;
        for(int i = 0; i < 4; i++) {
            vi adj = cur.first;
            int aux = adj[i]; adj[i] = adj[i+4]; adj[i+4] = aux;
            if(dist.find(adj) == dist.end() || dist[cur.first] + adj[i] + adj[i+4] < dist[adj]) {
                dist[adj] = dist[cur.first] + adj[i] + adj[i+4];
                pq.push(pair<vi, int>(adj, dist[adj]));
            }
        }

        for(int i = 0; i < 8; i++) {
            if(i % 4 != 3) {
                vi adj = cur.first;
                int aux = adj[i]; adj[i] = adj[i+1]; adj[i+1] = aux;
                if(dist.find(adj) == dist.end() || dist[cur.first] + adj[i] + adj[i+1] < dist[adj]) {
                    dist[adj] = dist[cur.first] + adj[i] + adj[i+1];
                    pq.push(pair<vi, int>(adj, dist[adj]));
                }
            }
        }
    }

    cout << dist[final] << "\n";
}

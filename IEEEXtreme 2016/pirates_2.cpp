#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
#define Y first
#define X second


char world[1000][1000];
int vert[1000][1000];
int n, m;

set<int> s_adj[1000*1000+1];
vector<int> adj[1000*1000+1];

int g[1000*1000+1][21];
int pa[1000*1000+1];
int le[1000*1000+1];

int vis[1000*1000+1];
int ss;

int dy[] = {-1,-1,0,1,1,1,0,-1};
int dx[] = {0,1,1,1,0,-1,-1,-1};

int valid(int y, int x) {
    return (y >= 0 && y < n && x >= 0 && x < m);
}

void bfs(int y, int x, int v) {

    vert[y][x] = v;
    queue<ii> q; q.push(ii(y,x));

    while(!q.empty()) {
        ii cur = q.front(); q.pop();

        for(int i = 0; i < 8; i++) {
            if(valid(cur.Y+dy[i], cur.X+dx[i]) && !vert[cur.Y+dy[i]][cur.X+dx[i]] && world[cur.Y][cur.X] == world[cur.Y+dy[i]][cur.X+dx[i]]) {
                vert[cur.Y+dy[i]][cur.X+dx[i]] = v;
                q.push(ii(cur.Y+dy[i], cur.X+dx[i]));
            }
        }
    }
}

void update_adj(int y, int x) {
    for(int i = 0; i < 8; i++) {
        if(valid(y+dy[i], x+dx[i])) {

            s_adj[vert[y][x]].insert(vert[y+dy[i]][x+dx[i]]);
            s_adj[vert[y+dy[i]][x+dx[i]]].insert(vert[y][x]);
        }
    }
}

void get_tree_height(int v, int p, int h) {
    vis[v] = 1;

    pa[v] = p;
    le[v] = h;


    int ch = 0;
    for(int i = 0; i < adj[v].size(); i++) {
        if(!vis[adj[v][i]]) {
            get_tree_height(adj[v][i], v, h+1);
        }
    }
}

void process(int v) {

    for(int i = 1; i <= v; i++) {
        for(int j = 0; (1 << j) <= v; j++) {
            g[i][j] = -1;
        }
    }

    for(int i = 1; i <= v; i++) {
        g[i][0] = pa[i];
    }

    for(int j = 1; (1 << j) <= v; j++) {
        for(int i = 1; i <= v; i++) {
            if(g[i][j-1] != -1) {

                g[i][j] = g[g[i][j-1]][j-1];
            }
        }
    }
}

int LCA(int v, int a, int b) {
    if(le[a] < le[b]) swap(a,b);

    int logL;
    for(logL = 1; (1 << logL) <= le[a]; logL++);
    logL--;

    for(int i = logL; i >= 0; i--) {
        if(le[a] - (1 << i) >= le[b]) {
            a = g[a][i];
        }
    }

    if(a == b)
        return a;

    for(int i = logL; i >= 0; i--) {
        if(g[a][i] != -1 && g[a][i] != g[b][i]) {
            a = g[a][i];
            b = g[b][i];
        }
    }

    return pa[a];
}

int main() {
    int q;
    cin >> n >> m >> q;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> world[i][j];
            vert[i][j] = 0;
        }
    }

    int v = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!vert[i][j]) {
                bfs(i,j,++v);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            update_adj(i,j);
        }
    }

    for(int i = 1; i <= v; i++) {
        for(int ad : s_adj[i]) if(ad != i) {
            adj[i].push_back(ad);
        }
    }

    for(int i = 0; i <= v; i++) vis[i] = 0;
    get_tree_height(1, 0, 1);

    process(v);

    for(int i = 0; i < q; i++) {
        int a,b,c,d; cin >> a >> b >> c >> d;


        int lca = LCA(v, vert[a-1][b-1], vert[c-1][d-1]);
        cout << ((le[vert[a-1][b-1]]-le[lca])+(le[vert[c-1][d-1]]-le[lca]))/2 << endl;
    }

}

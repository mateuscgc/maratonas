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

int g[1000*1000+1];
int pa[1000*1000+1];
int le[1000*1000+1];

int vis[1000*1000+1];
int ss;

int dy[] = {-1,-1,0,1,1,1,0,-1};
int dx[] = {0,1,1,1,0,-1,-1,-1};

int valid(int y, int x) {
    return (y >= 0 && y < n && x >= 0 && x < m);
}
int t_height;

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

int get_tree_height(int v) {
    vis[v] = 1;

    int ch = 0;
    for(int i = 0; i < adj[v].size(); i++) {
        if(!vis[adj[v][i]]) {
            ch = max(ch, get_tree_height(adj[v][i]));
        }
    }

    return ch+1;
}

void sectionize(int v, int p, int h) {
    vis[v] = 1;

    pa[v] = p;
    le[v] = h;
    // if(v == 5) cout << h << endl;
    if(h % ss == 0)
        g[v] = p;
    else
        g[v] = g[p];

    for(int i = 0; i < adj[v].size(); i++) {
        if(!vis[adj[v][i]]) {
            sectionize(adj[v][i], v, h+1);
        }
    }
}

void update_adj(int y, int x) {
    for(int i = 0; i < 8; i++) {
        if(valid(y+dy[i], x+dx[i])) {

            s_adj[vert[y][x]].insert(vert[y+dy[i]][x+dx[i]]);
                    // (world[y+dy[i]][x+dx[i]] == 'O') && (world[y][x] == '~')));

            s_adj[vert[y+dy[i]][x+dx[i]]].insert(vert[y][x]);
                    // (world[y+dy[i]][x+dx[i]] == '~') && (world[y][x] == 'O')));
        }
    }
}

int dist(int a, int b) {
    // cout << a << " " << b << endl;
    // cout << le[a] << " " << le[b] << endl;

    // cout << ss << endl;

    int ans = 0;

    // while(le[a]%ss != ss-1 && le[b]%ss != ss-1) {
    //     if(a == b) break;
    //     a = pa[a];
    //     swap(a,b);
    //     ans++;
    // }

    while(g[a] != g[b]) {
    // cout << "blA" << endl;
        if(le[a] > le[b]) {
            a = g[a];
            ans += le[a]%ss+1;
        } else {
            b = g[b];
            ans += le[b]%ss+1;
        }
        // cout << ans << endl;
    }

    while(a != b) {
        // cout << a << " " << b;
        if(le[a] > le[b])
            a = pa[a];
        else
            b = pa[b];
        ans++;
    }

    return ans/2;
}

int main() {
    int q;
    cin >> n >> m >> q;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> world[i][j];
            vert[i][j] = 0;
            //cout << world[i][j] << " ";
        }
        //cout << "\n";
    }
    //cout << "\n";

    int v = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!vert[i][j]) {
                //vert[i][j] = ++v;
                //cout << i << " " << j << endl;
                //cout << v + 1 << "\n\n";
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
        // cout << i << endl;
        for(int ad : s_adj[i]) if(ad != i) {
            // cout << " " << ad << endl;
            adj[i].push_back(ad);
        }
        // cout << endl;
    }

    for(int i = 0; i <= v; i++) vis[i] = 0;
    t_height = get_tree_height(1);

    // cout << t_height << endl;
    int ng = ceil(sqrt(t_height));
    // cout << ng << endl;
    ss = (t_height+(ng-1)) / ng;


    for(int i = 0; i <= v; i++) vis[i] = 0;

    sectionize(1,1,0);


    for(int i = 0; i < q; i++) {
        int a,b,c,d; cin >> a >> b >> c >> d;
        cout << dist(vert[a-1][b-1], vert[c-1][d-1]) << endl;
    }

}

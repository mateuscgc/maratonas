#include <bits/stdc++.h>

typedef long long ll;
#define F first
#define S second

using namespace std;

int main() {

    int h,w;
    cin >> h >> w;

    int lad[h][w];
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> lad[ i][j];
        }
    }

    int vis[h][w];
    memset(vis, 0, sizeof vis);
    int ans = h*w+1;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(!vis[i][j]) {
                queue< pair<int,int> > q;
                int ca = 1;
                q.push(make_pair(i,j));
                vis[i][j] = 1;
                while(!q.empty()) {
                    pair<int, int> c = q.front(); q.pop();
                    if(c.F > 0 && lad[c.F-1][c.S] == lad[c.F][c.S] && !vis[c.F-1][c.S]) {
                        ca++;
                        vis[c.F-1][c.S] = 1;
                        q.push(make_pair(c.F-1, c.S));
                    }
                    if(c.F < h-1 && lad[c.F+1][c.S] == lad[c.F][c.S] && !vis[c.F+1][c.S]) {
                        ca++;
                        vis[c.F+1][c.S] = 1;
                        q.push(make_pair(c.F+1, c.S));
                    }
                    if(c.S > 0 && lad[c.F][c.S-1] == lad[c.F][c.S] && !vis[c.F][c.S-1]) {
                        ca++;
                        vis[c.F][c.S-1] = 1;
                        q.push(make_pair(c.F, c.S-1));
                    }
                    if(c.S < w-1 && lad[c.F][c.S+1] == lad[c.F][c.S] && !vis[c.F][c.S+1]) {
                        ca++;
                        vis[c.F][c.S+1] = 1;
                        q.push(make_pair(c.F, c.S+1));
                    }
                }
                ans = min(ans, ca);
            }
        }
    }

    cout << ans << "\n";

    return 0;
}

#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;

int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

int uf[1003][1003];
int open[1003][1003];
int sz[1003][1003];

int n;

void init() {
	for(int i = 0; i <= n+1; i++) {
		for(int j = 0; j < n; j++) {
			uf[i][j] = i*n+j;
			sz[i][j] = 1;
			open[i][j] = 0;
		}
	}
}

bool valid(int y, int x){
	return x >= 0 && x < n && y >= 0 && y <= n+1; 
}

int find(int i, int j) {
	return (uf[i][j] == i*n+j ? i*n+j : uf[i][j] = find(uf[i][j]/n, uf[i][j]%n));
}

void merge(int a, int b, int c, int d) {
	int uab = find(a,b);
	int ucd = find(c,d);

	//cout << uab << " " << ucd << endl;

	if(sz[a][b] < sz[c][d]) { swap(uab, ucd); }

	uf[ucd/n][ucd%n] = uab;
	sz[uab/n][uab%n] += sz[ucd/n][ucd%n];
}

int main() {

	cin >> n;

	init();

	for(int i = 1; i < n; i++) {
		merge(0,i-1, 0,i);
		open[0][i-1] = open[0][i] = 1;
		//cout << find(0,i) << endl;
	}


	for(int i = 1; i < n; i++) {
		open[n+1][i-1] = open[n+1][i] = 1;
		merge(n+1,i-1, n+1,i);
	}

	int y, x;
	int t = 0;
	while(cin >> y, y != -1) {
		cin >> x;
		x--; 
		open[y][x] = 1;
		//cout << "\n" << y << " " << x << endl;
		t++;
		for(int i = 0; i < 4; i++) {
			if(valid(y+dy[i], x+dx[i]) && open[y+dy[i]][x+dx[i]]) {
				//cout << "ad = " << y+dy[i] << " " << x+dx[i] << endl;
				
				// cout << find(0,0) << endl;
				// cout << find(0,3) << endl;


				//cout << find(y,x) << " - " << find(y+dy[i],x+dx[i]) << "\n";
				merge(y,x, y+dy[i],x+dx[i]);
				//cout << find(y,x) << " - " << find(y+dy[i],x+dx[i]) << "\n";

				
				// cout << find(0,1) << endl;
				// cout << find(0,3) << endl;

				//cout << find(0,0) << " - " << find(n+1,0) << "\n";
				if(find(0,0) == find(n+1,0)) {
					//cout << "bla\n";
					cout << t << endl;
					return 0;
				}
			}
		}
	}
	cout << "-1" << endl;
}
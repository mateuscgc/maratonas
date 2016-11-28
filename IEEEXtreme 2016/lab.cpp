#include <bits/stdc++.h>
using namespace std;

#define MAX 1001

int N;
int mat[MAX][MAX], usado[MAX][MAX];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

struct state{
	int x, y, peso;
	bool operator < (const state& a)const{
		return peso > a.peso;
	}
};

bool valid(int x, int y){
	return x >= 1 && x <= N && y >= 1 && y <= N; 
}


int prim(int u){
	int v, resp = INT_MAX;
	priority_queue<state> pq;
	pq.push({1,u,mat[1][u]});

	while(!pq.empty()){

		state aa = pq.top();
		pq.pop();

		int i;

		pair<int, int> mini;

		if(aa.x == N)
			resp = min(resp, aa.peso);

		for(i = 0; i < 4; i++)
			if( valid(aa.x+dx[i],aa.y+dy[i]) && mat[ aa.x+dx[i] ][ aa.y+dy[i] ] != INT_MAX && usado[ aa.x+dx[i] ][ aa.y+dy[i] ] != u){
				mini = make_pair(i, mat[ aa.x+dx[i] ][ aa.y+dy[i] ]);
				break;
			}

		for(i++; i < 4; i++){
			if( valid(aa.x+dx[i],aa.y+dy[i]) && mat[ aa.x+dx[i] ][ aa.y+dy[i] ] != INT_MAX && usado[ aa.x+dx[i] ][ aa.y+dy[i] ] != u){
				if(mat[ aa.x+dx[i] ][ aa.y+dy[i] ] < mini.second)
					mini = make_pair(i, max( mat[ aa.x+dx[i] ][ aa.y+dy[i] ], aa.peso));
			}
		}

		pq.push({aa.x+dx[mini.first], aa.y+dy[mini.first],mini.second});
	}
	return resp;
}

int main(){

	cin >> N;
	vector<int> inicio;

	for(int i = 1; i <= N; i++){	
		for(int j = 1; j <= N; j++){
			mat[i][j] = INT_MAX;
			usado[i][j] = 0;
		}
	}

	int x, y, cont = 1;

	for(cin >> x; x != -1; cin >> x ){
		cin >> y;
		mat[x][y] = cont++;
		if(x == 1)
			inicio.push_back(y);
	}

	int resp = INT_MAX;

	for(int v = 0; v < inicio.size(); v++)
		resp = min( prim(inicio[v]), resp);
	
	if(resp == INT_MAX)
		cout << "-1\n";
	else
		cout << resp << endl;

	return 0;
}
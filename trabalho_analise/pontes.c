#include <stdio.h>
#include <stdbool.h>

#define IMPOSSIVEL 10000001

typedef struct{
	int vizinho;
	int buracos;
} Aresta;

typedef struct{
	Aresta pontes[1002];
	int numPontes;
} Vertice;

Vertice vertices[1002];
int best[1002];
_Bool visited[1002];

int main(int argc, char const *argv[])
{
	int n, m, s, t, b, i;
	scanf("%d %d", &n, &m);

	for (i = 0; i < m; i++){
		scanf("%d %d %d", &s, &t, &b);
		vertices[s].pontes[vertices[s].numPontes].vizinho = t;
		vertices[s].pontes[vertices[s].numPontes++].buracos = b;

		vertices[t].pontes[vertices[t].numPontes].vizinho = s;
		vertices[t].pontes[vertices[t].numPontes++].buracos = b;
	}

	best[0] = 0;
	for(i = 1; i <= n+1; i++){
		best[i] = IMPOSSIVEL;
	}

	while(true){
		int x = -1, min = IMPOSSIVEL+1, k, j;
		for (k = 0; k <= n+1; k++){
			if (best[k] < min && !visited[k]){
				x = k;
				min = best[x];
			}
		}
		if(x == -1) break;
		visited[x] = true;

		for(j = 0; j < vertices[x].numPontes; j++){
			if (best[x] + vertices[x].pontes[j].buracos < best[vertices[x].pontes[j].vizinho]) {
				best[vertices[x].pontes[j].vizinho] = best[x] + vertices[x].pontes[j].buracos;
			}
		}  
	}

	printf("%d\n", best[n+1]);

	return 0;
}
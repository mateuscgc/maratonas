// Finalizada

#include "stdio.h"

int main(int argc, char const *argv[]) {
	long n, m, i, j, saiu;
	scanf("%ld", &n);
	long pessoas[n];
	for (i = 0; i < n; i++) {
		scanf("%ld", &pessoas[i]);
	}
	
	scanf("%ld", &m);
	for (i = 0; i < m; i++) {
		scanf("%ld", &saiu);
		for(j = 0; j < n; j++){
			if(pessoas[j] == saiu){
				pessoas[j] = -1;
				break;
			}
		}
	}
	for (i = 0; i < n; i++){
		if (pessoas[i] != -1)
			printf("%ld ", pessoas[i]);
	}
	printf("\n");

	return 0;
}
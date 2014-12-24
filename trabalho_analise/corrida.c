#include "stdio.h"

int main(int argc, char const *argv[])
{
	int n, m, i, j, k;
	int podio[3] = {-1, -1, -1};
	long pTempo[3] = {100000001, 100000001, 100000001};
	long soma;
	long tempo;
	scanf("%d", &n);
	scanf("%d", &m);
	for (i = 1; i <= n; i++){
		soma = 0;
		for(j = 1; j <= m; j++){
			scanf("%ld", &tempo);
			soma += tempo;
		}
		for (j = 0; j < 3; j++){
			if(soma < pTempo[j]) {
				for(k = 2;k > j;k--){
					pTempo[k] = pTempo[k-1];
					podio[k] = podio[k-1];
				}
				pTempo[j] = soma;
				podio[j] = i;
				j = 3;
			}
		} 
	}
	for (i = 0; i < 3; i++)
		printf("%d\n", podio[i]);
	
	return 0;
}
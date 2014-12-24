#include <stdio.h>


int main(int argc, char const *argv[])
{
	int n, i, j, k, inicial = 0, max;
	scanf("%d", &n);
	if (n == 1) {
		printf("1\n");
		return 0;
	}
	long consultas[n][2];
	int resultados[n];
	for (i = 0; i < n; i++){
		scanf("%li %li", &consultas[i][0], &consultas[i][1]);
		if (consultas[i][1] < consultas[inicial][1]) {
			inicial = i;
		}
	}
	resultados[inicial] = 1;
	for (i = inicial + 1; i < n && consultas[i][0] < consultas[inicial][1]; i++){
		resultados[i] = 1;
	}
	for (j = i; j < n; j++){
		max = inicial;
		for (k = i; k < j; k++){
			if (consultas[k][1] <= consultas[j][0] && resultados[k] > resultados[max]){
				max = k;
			}
		}
		resultados[j] = resultados[max] + 1;
	}

	printf("%d\n", resultados[n-1]);

	return 0;
}
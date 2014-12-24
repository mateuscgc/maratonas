#include <stdio.h>

int main(int argc, char const *argv[])
{
	int c, f, i, j, teste = 0;

	scanf("%d %d", &c, &f);

	for (;c != 0;){
		teste++;
		int results[f+1][c+1];
		int frases[f][2];
		for (i = 0; i < f; i++){
			scanf("%d %d", &frases[i][0], &frases[i][1]);
		}
		
		for(i = 0; i <= c; i++) results[0][i] = 0;
		for(i = 0; i <= f; i++) results[i][0] = 0;
		
		for(i = 1; i <= f; i++){
			for(j = 1; j <= c; j++) {
				if (frases[i-1][0] > j || results[i-1][j] >= (results[i-1][j-frases[i-1][0]] + frases[i-1][1])){
					results[i][j] = results[i-1][j];
				} else {
					results[i][j] = results[i-1][j-frases[i-1][0]] + frases[i-1][1];
				}
			}
		}
		printf("Teste %d\n", teste);
		printf("%d\n\n", results[f][c]);

		scanf("%d %d", &c, &f);
	}
	
	return 0;
}
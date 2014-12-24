#include <stdio.h>


typedef struct {
	char name[16];
	int pontos;
	int pos;
} jogador;

int main(int argc, char const *argv[]) {
	int j, teste = 0;
	int i, h, k, b, d;
	int pontuacao;
	int ordenado;
	int soma, pMin, pMax;
	char nl;


	scanf("%d", &j);
	while(j != 0) {
		teste++;
		jogador jogadores[j];
		jogador *classificacao[j];

		for (i = 0; i < j; i++){
			ordenado = 0;
			pMax = -1;
			pMin = 1001;
			soma = 0;
			scanf("%s", jogadores[i].name);
			nl = getchar();
			for (k = 0; k < 12; k++){
				scanf("%d", &pontuacao);
				soma += pontuacao;
				if (pontuacao > pMax)
					pMax = pontuacao;
				if (pontuacao < pMin)
					pMin = pontuacao;
			}
			jogadores[i].pontos = soma - (pMax + pMin);
			for (k = 0; k < i; k++){
				if(jogadores[i].pontos > classificacao[k]->pontos){
					for (h = i; h > k; h--){
						classificacao[h] = classificacao[h-1];
					}
					classificacao[k] = &jogadores[i];
					ordenado = 1;
					k = j;
				} else {
					for(h = k; h < i && jogadores[i].pontos == classificacao[h]->pontos; h++){
						for(b = 0; jogadores[i].name[b] == classificacao[h]->name[b]; b++) {
						}
						if ((jogadores[i].name[b] == 0 || jogadores[i].name[b] < classificacao[h]->name[b]) && classificacao[h]->name[b] != 0) {
							for (d = i; d > h; d--){
								classificacao[d] = classificacao[d-1];
							}
							classificacao[h] = &jogadores[i];
							ordenado = 1;
							h = i;
							k = i;
						}
					}
				}
			}
			if (!ordenado){
				classificacao[i] = &jogadores[i];
			}
			// for(k = 0; k <= i; k++){
			// 	printf("%d %d %s\n", k+1, classificacao[k]->pontos, classificacao[k]->name);
			// }
			// 	printf("==============================\n");
		}
		int ult = -1, cont = 0;
		printf("Teste %d\n", teste);
		for(i = 0; i < j; i++){
			if(classificacao[i]->pontos == ult){
				cont++;
			} else {
				cont = 0;
				ult = classificacao[i]->pontos;
			}
			printf("%d %d %s\n", i+1-cont, classificacao[i]->pontos, classificacao[i]->name);
		}
		scanf("%d", &j);
		if(j != 0)
			printf("\n");
	}

	return 0;
}
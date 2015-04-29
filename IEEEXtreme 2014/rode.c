#include <stdio.h>

int main(int argc, char const *argv[])
{
	int numTestes, numEstacoes, capacidadeTanque, capacidadeAtual, tamViagem, tamRestante, i, passo, adicionadoTanque, j;
	int gasto, prox, precoAtual, consegue;
	
	scanf("%d", &numTestes);

	for (j = 0; j < numTestes; j++){
		scanf("%d %d %d %d", &numEstacoes, &capacidadeTanque, &capacidadeAtual, &tamViagem);

		int estacoes[numEstacoes][2];
		for (i = 0; i < numEstacoes; i++)
			scanf("%d %d", &estacoes[i][0], &estacoes[i][1]);
		tamRestante = tamViagem;
		gasto = 0;
			
		while(capacidadeAtual < tamRestante){
			consegue = 0;
			prox = -1;
			// printf("%d\n", consegue);
			// printf("%d\n", capacidadeAtual);
			for (i = 0; i < numEstacoes; i++){
				if(capacidadeAtual >= estacoes[i][0] - (tamViagem - tamRestante)
					&& estacoes[i][0] > (tamViagem - tamRestante)){
					// printf("what?\n");
					consegue = 1;
					if(prox == -1 || estacoes[i][1] < estacoes[prox][1])
						prox = i;
				}
			}
			precoAtual = estacoes[prox][1];
			// printf("Proxima Estação = %d\n", prox);
			// printf("Preço do combustivel atual = %d\n", precoAtual);
			passo = estacoes[prox][0] - (tamViagem - tamRestante);
			capacidadeAtual -= passo;
			// printf("Passo = %d\n", passo);
			tamRestante -= passo;
			// printf("Viajem restante = %d\n", tamRestante);
			prox = -1;
			for(i = 0; i < numEstacoes; i++){
				// printf("%d\n", estacoes[i][0]);
				if(estacoes[i][0] > (tamViagem - tamRestante) && (estacoes[i][0] - (tamViagem - tamRestante)) < capacidadeTanque && estacoes[i][1] < precoAtual){
					// printf("%d( %d; %d)\n", i, estacoes[i][0], estacoes[i][1]);
					if((prox == -1 || estacoes[i][0] < estacoes[prox][0]) && estacoes[i][1] < precoAtual){
						// printf("%d\n", estacoes[i][0]);
						// printf("%d\n", estacoes[prox][0]);
						prox = i;
						// printf("%d\n", prox);
					}
				}
			}
			if (prox == -1)
				adicionadoTanque = tamRestante < capacidadeTanque ? tamRestante - capacidadeAtual : capacidadeTanque - capacidadeAtual;
			else
				adicionadoTanque = estacoes[prox][0] - (tamViagem - tamRestante) - capacidadeAtual;
			gasto += adicionadoTanque*precoAtual;
			capacidadeAtual += adicionadoTanque;
			// printf("Abastecido = %d\n", adicionadoTanque);
			// printf("Gasto ate o momento = %d\n", gasto);
			// printf("%d\n", consegue);
			if (!consegue)
				break;
		}
		if(consegue)
			printf("%d\n", gasto);
		else
			printf("-1\n");
	}

	return 0;
}
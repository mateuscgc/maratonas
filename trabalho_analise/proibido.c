#include <stdio.h>
#include <stdlib.h>

typedef struct sTree {
	long chave;
	struct sTree *esq, *dir, *parent;
} tree, *pTree;

void arvoreBBInicializa(pTree *t){
	(*t) = NULL;
}



pTree arvoreBBBusca(pTree t, int k){  //copia de apontador 
	while (t != NULL && k != t->chave){
		if(k < t->chave)
			t = t->esq;
		else
			t = t->dir;
	}
	return t;
}

void arvoreBBinsercao (pTree *t,pTree k) {
	pTree auxPai = NULL;
	pTree aux = *t;
	while (aux != NULL){
		auxPai = aux;
		if(k->chave < aux->chave)
			aux = aux->esq;
		else
			aux = aux->dir;
	}
	k->parent = auxPai;
	if (auxPai == NULL)
		(*t) = k;
	else {// precisa de chaves eu esqueci
		if (k->chave < auxPai->chave)
			auxPai->esq = k;
		else
			auxPai->dir = k;
	}
}

pTree criaNo(int x){
	pTree aux = (tree*) malloc (sizeof(tree));
	aux->chave = x;
	aux->parent = NULL;
	aux->esq = NULL;
	aux->dir = NULL;
	
	return aux;
}

	void emOrdemCrescente(pTree t){
		if(t != NULL){
			emOrdemCrescente(t->esq);
			printf("%li\n", t->chave);
			emOrdemCrescente(t->dir);
		}
	}

int main(int argc, char const *argv[])
{
	pTree t;
	arvoreBBInicializa(&t);

	int numProibidos, i;
	scanf("%d", &numProibidos);
	long teste;

	for (i = 0; i < numProibidos; i++){
		scanf("%li", &teste);
		arvoreBBinsercao(&t, criaNo(teste));
	}
	while (scanf("%li", &teste) >= 0) {
		if (arvoreBBBusca(t, teste))
			printf("sim\n");
		else
			printf("nao\n");
	}

	/* code */
	return 0;
}
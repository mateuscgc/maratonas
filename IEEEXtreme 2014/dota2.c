#include <stdio.h>
#define INTELLIGENCE 0
#define STRENGTH 1
#define AGILITY 2

typedef struct {
	char nome[100];
	int tipo;//0,1 ou 2;
	float qi;

}hero;

int main(){
	int i, j, n, m, att[3] = { 0, 0, 0 }, v, d, posMaior;
	scanf("%i %i",&n,&m);
	//scanf("%*c");
	char aux;
	hero h[n];
	for(i = 0; i < n ; i++){
		scanf("%*c");
        scanf("%c", &h[i].nome[0]);
        for(j = 0; (h[i].nome[j] != ',') ; j++)
        	scanf("%c", &h[i].nome[(j+1)]);
        h[i].nome[j] = 0;
        scanf("%c",&aux);
        switch(aux){
        	case 'A':
        		h[i].tipo = AGILITY;
        		break;
        	case 'I':
        		h[i].tipo = INTELLIGENCE;
        		break;
        	case 'S':
        		h[i].tipo = STRENGTH;
        		break;
        }
	    while(aux != ',')
        	scanf("%c", &aux);
	    scanf("%d", &v);
	    scanf("%*c");
	    scanf("%d",&d);
	    h[i].qi = v / (float)(v + d);
	    h[i].qi *= (i+1) * 100;
	    h[i].qi = (int)h[i].qi;
	    scanf("%*c");
	}
	for(i = 0 ; i < m; ++i){
		posMaior = -1;
		for(j = 0; j < n; ++j){
			if(((posMaior == -1) || (h[j].qi > h[posMaior].qi)) && h[j].tipo != 3)
				posMaior = j;
		}
		printf("%s\n", h[posMaior].nome);
		att[h[posMaior].tipo]++;
		h[posMaior].tipo = 3;
	}
	printf("\nThis set of heroes:\n");
	printf("Contains %.2f percentage of Intelligence\n", (float)((float)att[INTELLIGENCE]/(float)m)*(float)100);
	printf("Contains %.2f percentage of Strength\n", (float)((float)att[STRENGTH]/(float)m)*(float)100);
	printf("Contains %.2f percentage of Agility\n", (float)((float)att[AGILITY]/(float)m)*(float)100);

}

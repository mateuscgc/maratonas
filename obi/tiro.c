#include <stdio.h>

int buscaCirculo(long long *raios, int i, int f, long long disTiro){
    int meio;    
    if (i == f){
        if (disTiro <= raios[i])
            return i;
        return -1;
    }
    meio = (f + i)/2;
    if (disTiro <= raios[meio])
        return buscaCirculo(raios, i, meio, disTiro);
    return buscaCirculo(raios, meio+1, f, disTiro);
}

int main(){
    int c, t, i, circulo;
    scanf("%d %d", &c, &t);
    long long raios[c], disTiro, tiro[2], pontos = 0;
    for (i = 0; i < c; i++) {
        scanf("%lld", &raios[i]);
        raios[i] *= raios[i];
    }
    for (i = 0; i < t; i++){
        scanf("%lld %lld", &tiro[0], &tiro[1]);
        disTiro = ((tiro[0]*tiro[0]) + (tiro[1]*tiro[1]));
        circulo = buscaCirculo(raios, 0, c - 1, disTiro);        
        if (circulo >= 0)
            pontos += c - circulo;
    }
    printf("%lld\n", pontos);    

    return 0;	
}

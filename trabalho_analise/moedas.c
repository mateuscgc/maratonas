#include <stdio.h>

#define NUM_IMPOSSIVEL_MOEDAS 50001

int main(int argc, char const *argv[])
{
    long m, k;
    int n, j;
    long min;
    scanf("%li %d", &m, &n);
    for (;m > 0;) {
        long moedas[n];
        long resultados[m+1];
        for (k = 0; k < n; k++) {
            scanf("%li", &moedas[k]);
        }
        for (k = 0; k <= m; k++){
            
            if (k == 0) {
                resultados[k] = 0;

            } else {

                min = NUM_IMPOSSIVEL_MOEDAS;
                for (j = 0; j < n ; j++){
                    if (moedas[j] <= k) {
                        if (resultados[k - moedas[j]] + 1 < min)
                            min = resultados[k - moedas[j]] + 1;
                    }
                }
                resultados[k] = min; 
            }

        }

        if (resultados[m] >= NUM_IMPOSSIVEL_MOEDAS)
            printf("Impossivel\n");
        else
            printf("%li\n", resultados[m]);
        
        scanf("%li %d", &m, &n);
    }

    return 0;
}

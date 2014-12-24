#include <stdio.h>


int main(int argc, char const *argv[]) {
    int n, x, i, ini, fim, min, atual;
    scanf ("%d %d", &n, &x);
    atual = 0;
    min = 0;
    for (i = 1; i <= n; i++){
        scanf("%d %d", &ini, &fim);
        min += (ini - atual - 1)%x;
        min += fim - ini + 1;
        atual = fim;
    }

    printf("%d\n", min);

    return 0;
}

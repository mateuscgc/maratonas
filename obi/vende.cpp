#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, k, i, j, menor;
    scanf("%d %d", &n, &k);
    int distancias[n];
    for(i = 0; i < n; i++)
        scanf("%d", &distancias[i]);
    sort(distancias, distancias+n);    
    i = k;
    menor = distancias[n-1] - distancias[i--];
    //printf("%d\n", menor);        
    for(j = n-2; i >= 0; i--, j--){
        if (distancias[j] - distancias[i] < menor)
            menor = distancias[j] - distancias[i];
        //printf("%d\n", menor);
    }

    printf("%d\n", menor);

    return 0;
}

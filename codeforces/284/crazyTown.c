#include <stdio.h>

int main(int argc, char const *argv[]) {
    double vc[2];
    double un[2];
    int numRotas, i;
    double a, b, c;
    scanf("%lf %lf", &vc[0], &vc[1]);
    scanf("%lf %lf", &un[0], &un[1]);
    scanf("%d", &numRotas);
    int pulos = 0;
    double y1, y2;
    for (i = 0; i < numRotas; i++){
        scanf("%lf %lf %lf", &a, &b, &c);
        y1 = (-a*vc[0] - c) / b;
        y2 = (-a*un[0] - c) / b;
        if ((vc[1]<y1)^(un[1]<y2))
            pulos++;
    }

    printf("%d\n", pulos);

    return 0;
}

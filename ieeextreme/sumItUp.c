#include <stdio.h>

long pot(int x,int n){
	int aux;
	if (n == 0)
		return 1;
	aux = pot(x, n/2);
	if ((n % 2) == 0){
		return aux*aux;
	}
	return (long) aux*aux*x;
}

int main(int argc, char const *argv[])
{
	int n, i, j, q, op;
	long soma = 0;
	scanf("%d", &n);
	int num[n], num2[n];
	for(i = 0; i < n; i++){
		scanf("%d", &num[i]);
		num2[i] = num[i];
	}
	scanf("%d", &q);
	for (i = 1;  i <= q; i++){
		scanf("%d", &op);
		for (j = 0; j < n; j++){
			num[(j - op + n) % n] += num2[j];
		}
		for (j = 0; j < n; j++){
			num2[j] = num[j];
		}
	}

	for (i = 0; i < n; i++)
		soma += num[i];
	printf("%li\n", soma % (pot(10, 9) + 7))

	return 0;
}
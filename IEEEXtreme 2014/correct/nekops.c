#include <stdio.h>

#define NUM_GRANDE 100000

int main(int argc, char const *argv[])
{
	int num_sequencias, i, j, k, count, max_lenght;
	scanf("%d", &num_sequencias);
	int sequencias[num_sequencias+1][NUM_GRANDE];

	for(i = 1; scanf("%d", &sequencias[0][i]) != EOF; i++);
	sequencias[0][0] = i - 1;
	max_lenght = 0;

	for(i = 1; i <= num_sequencias; i++){
		count = 1;
		k = 1;
		for (j = 2; j <= sequencias[i-1][0]; j++){
			if(sequencias[i-1][j] == sequencias[i-1][j-1]) {
				count++;
			} else {
				sequencias[i][k++] = count;
				sequencias[i][k++] = sequencias[i-1][j-1];
				count = 1;
			}
		}
		sequencias[i][k++] = count;
		sequencias[i][k++] = sequencias[i-1][j-1];
		
		sequencias[i][0] = k - 1;
		if ((k - 1) > sequencias[max_lenght][0])
			max_lenght = i;

	}
	int aux;
	int count_total = 0;
	for (j = 1; j <= sequencias[max_lenght][0]; j++){
		aux = sequencias[max_lenght][j];
		while (aux != 0){
			aux /= 10;
			++count_total;
		}
		++count_total;
	}
	--count_total;

	for (i = 0; i <= num_sequencias; i++){
		count = 0;
		for (j = 1; j <= sequencias[i][0]; j++){
			aux = sequencias[i][j];
			while (aux != 0){
				aux /= 10;
				count++;
			}
			count++;
		}
		count--;
		count = count_total - count;
		for(j = 1; j <= count/2; j++)
			printf(".");
		if (count % 2 == 1)
			printf(".");
		for (j = 1; j <= sequencias[i][0]; j++)
			if(j==1)
				printf("%d", sequencias[i][j]);
			else
				printf(" %d", sequencias[i][j]);
		for(j = 1; j <= count/2; j++)
			printf(".");
		printf("\n");
	}
	printf("%d\n", sequencias[i - 1][0]);


	return 0;
}
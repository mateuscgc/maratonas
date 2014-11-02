#include <stdio.h>

void passArray(int  *d, int *s, int length){
	int i; 
	for (i = 0 ; i < length; i++)
		d[i] = s[i];
}

int numAlg(int num){
	int count = 0;
	while (num != 0){
		num /= 10;
		count++;
	}
	return count;
}

void printState(int *c, int n, int i){
	int j;
	int num_alg = numAlg(i);
	printf("%d", i);
	for (j = 1; j <= (3 - num_alg); j++)
		printf(" ");
	printf(" -");
	for (j = 0; j < n; j++){
		if(c[j])
			printf("*");
		else
			printf(" ");
	}
	printf("-\n");
}

void toBinary(int d, int *b, int length){
	int i;
	int aux;
	for (i = 0; i < length; i++){
		if(d != 0) {
			b[i] = d % 2;
			d /= 2;
		} else {
			b[i] = 0;
		}
	}
	for(i = 0; i < length/2; i++){
		aux = b[i];
		b[i] = b[length - i - 1];
		b[length - i - 1] = aux;
	}
}

int main(int argc, char const *argv[])
{
	int rule, interations, numCells, cells, i, j;
	int rule_b[8];
	scanf("%d", &rule);
	toBinary(rule, rule_b, 8);
	// for (i = 0; i < 8; i++)
	// 	printf("%d\n", rule_b[i]);

	scanf("%d", &interations);
	scanf("%d", &numCells);
	scanf("%d", &cells);
	int cells_b[numCells], next[numCells];
	toBinary(cells, cells_b, numCells);

	int pre_state[3];
	int num_alg_max = numAlg(interations);
	printState(cells_b, numCells, 1);
	for (i = 2; i <= interations; i++){
		int change = 0;
		for (j = 0; j < numCells; j++){
			pre_state[1] = cells_b[j];
			if(j > 0)
				pre_state[0] = cells_b[j-1];
			else
				pre_state[0] = 0;
		
			if (j < numCells - 1)
				pre_state[2] = cells_b[j+1];
			else
				pre_state[2] = 0;
			if (pre_state[0] && pre_state[1] && pre_state[2])
				next[j] = rule_b[0];
			else if (pre_state[0] && pre_state[1] && !pre_state[2])
				next[j] = rule_b[1];
			else if (pre_state[0] && !pre_state[1] && pre_state[2])
				next[j] = rule_b[2];
			else if (pre_state[0] && !pre_state[1] && !pre_state[2])
				next[j] = rule_b[3];
			else if (!pre_state[0] && pre_state[1] && pre_state[2])
				next[j] = rule_b[4];
			else if (!pre_state[0] && pre_state[1] && !pre_state[2])
				next[j] = rule_b[5];
			else if (!pre_state[0] && !pre_state[1] && pre_state[2])
				next[j] = rule_b[6];
			else if (!pre_state[0] && !pre_state[1] && !pre_state[2])
				next[j] = rule_b[7];
			if (next[j] != cells_b[j])
				change = 1;
		}
		printState(next, numCells, i );
		if (!change)
			break;
		passArray(cells_b, next, numCells);
	}


	return 0;
}
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int numSubs, numCons, i, j, k, no = 0;
	scanf("%d %d", &numSubs, &numCons);
	int cons[numCons][2];
	for (i = 0; i < numCons; i++){
		scanf("%d %d", &cons[i][0], &cons[i][1]);
	}

	int subs[numSubs];
	for (i = 0; i < numSubs; i++){
		scanf("%d", &subs[i]);
	}
	for (i = numSubs - 1; i >= 0; i--)
		for (j = 0; j < numCons; j++)
			if (cons[j][1] == subs[i]) {
				for (k = i; k >= 0 && subs[k] != cons[j][0]; k--);
				if (k == -1){
					no = 1;
					i = 0;
					j = numCons;
					break;
				}
			}

	if(no)
		printf("NO\n");
	else
		printf("YES\n");


	return 0;
}
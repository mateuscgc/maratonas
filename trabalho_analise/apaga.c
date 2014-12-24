#include <stdio.h>



int main(int argc, char const *argv[])
{
	long n, d, i, j, k, menor;

	scanf("%li %li", &n, &d);
	
	for(;n != 0;) {
		char num[n];
		scanf("%s", num);

		j = 0;
		for (i = 1; i < n && j < d; i++){
			for (k = 1; i - k >= 0 && (num[i-k] < num[i] || num[i-k] == 58) && j < d; k++) {
				if (num[i-k] != 58){
					num[i-k] = 58;
					j++;	
				}
				
			}
		}

		i = 0;
		j = 0;
		
		while (j < (n - d)){
			if (num[i] < 58){
				printf("%d", num[i] - 48);
				j++;
			}
			i++;
		}
		printf("\n");
	
		scanf("%li %li", &n, &d);
	}

	return 0;
}
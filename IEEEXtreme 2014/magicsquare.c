#include <stdio.h>
#define max_n 1000
#define max_saida 10000

int main(){
	int i, j, m[max_n][max_n], n, hor[max_n], ver[max_n];
	int sum = 0;
	int sum_diag = 0;
	int sum_diag2 = 0;
	int sum_col = 0;
	int sum_row = 0;
	int num_diff_lines = 0;
	int diff_lines[n*n];

	scanf("%d", &n);
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			scanf("%d", &m[i][j]);
		}
	}
	
	for(i = 0; i < n; i++){
		sum_diag += m[i][i];
		sum_diag2 += m[i][n-i-1];
	}

	for (i = n - 1; i >= 0; i--){
		sum = 0;
		for (j = 0; j < n; j++)
			sum += m[j][i];
		if(sum != sum_diag) {
			diff_lines[num_diff_lines] = -(i+1);
			num_diff_lines++;
		}
	}


	if(sum_diag2 != sum_diag){
		diff_lines[num_diff_lines] = 0;
		num_diff_lines++;
	}

	for (i = 0; i < n; i++){
		sum = 0;
		for (j = 0; j < n; j++)
			sum += m[i][j];
		if(sum != sum_diag){
			diff_lines[num_diff_lines] = i + 1;
			num_diff_lines++;
		}
	}

	if(num_diff_lines > 0){
		printf("%d\n", num_diff_lines);
		for (i = 0; i < num_diff_lines; i++)
			printf("%d\n", diff_lines[i]);
	} else {
		printf("0\n");
	}


	return 0;
}
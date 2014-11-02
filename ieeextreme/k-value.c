#include <stdio.h>
#include <stdlib.h>
#define MAX_NUMBERS 100000

typedef long unsigned int uli;

int compare_function(const void *a, const void *b){
	return (*(uli*)a - *(uli*)b);
}

int main(){
	int i, j, n, m, k, z;
	uli less_number, in_num, out_num, aux;
	scanf("%d %d %d", &n, &m, &k);
	uli sub_sequence[m], entrada[n];
	for(i = 0; (i < (n + (m - 1))); i++){
		if(i < n)
			scanf("%lu", &entrada[i]);
		if(i >= (m - 1)){
			if(i == (m - 1)){
				for(j = (i - (m-1)), z = 0; z < m; j++, z++)
					sub_sequence[z] = entrada[j]; 
				qsort(sub_sequence, m, sizeof(uli), compare_function);
				less_number = sub_sequence[(k - 1)];
			}
			else{
				in_num = entrada[i >= n ? i % n : i];
				out_num = entrada[(i - m)];
				for(j = 0; (sub_sequence[j] != out_num); j++);
				if(in_num > out_num){
					for(z = (j+1); (z < m) && (sub_sequence[z] < in_num); z++)
						sub_sequence[z-1] = sub_sequence[z];
					sub_sequence[z-1] = in_num;					
				}
				else{
					for(z = (j-1); (z >= 0) && (sub_sequence[z] > in_num); z--)
						sub_sequence[z+1] = sub_sequence[z];
					sub_sequence[z+1] = in_num;		
				}
				if(sub_sequence[(k - 1)] < less_number){
					less_number = sub_sequence[(k - 1)];
				}
			}
		}
	}
	printf("%lu\n", less_number);
	return 0;
}

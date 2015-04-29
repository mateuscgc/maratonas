#include <stdio.h>

int main(){

  int N;
  long long i = 0;

  scanf("%d", &N);

  for( i = 1; (i*i) <= N; i++){
    if(i != 1)
      printf(" ");
    
    printf("%lld", i*i);

  }
  if(N == 0) printf("1");
  printf("\n");

  return 0;
}

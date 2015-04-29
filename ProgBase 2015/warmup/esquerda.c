#include <stdio.h>
#include <stdlib.h>

int main(){

  int N;
  char commands[1001];
  char pos[5] = "NLSO";
  int face = 0;
  int i = 0;
  scanf("%d",&N);

  scanf("%s", commands);
  
  for( i = 0; i < N; i++){
    if(commands[i] == 'D' )
      if(face < 3)
        face++;
      else face = 0;
    else{
      if(face > 0)
        face--;
      else face = 3;
    }
  }

  printf("%c\n", pos[face]);

  return 0;
}

#include <bits/stdc++.h>

using namespace std;

long long r[55555];

int main(){
  r[1] = 1;
  for(long long i = 2; i <= 50000; i++)
    r[i] = r[i-1] + 6*(i-1);
  
  int n;
  while(scanf("%d", &n) == 1){
    printf("%lld\n", r[n]);
  }
}
#include <bits/stdc++.h>

using namespace std;

int mid[700], kel[700];

int main(){
  int n; cin >> n;
  int ans = 0;
  for(int i = 0; i < n; i++){
    int x; string s;
    cin >> x >> s;
    if(s == "Midkemia") mid[x]++; else kel[x]++;
  }
  
  for(int i = 300; i <= 600; i++){
      ans += min(mid[i], kel[i]);
  }
  
  cout << ans << endl;
}
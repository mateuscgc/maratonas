#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

int pts[5];

int main(){
    int n, c;
    while(scanf("%d%d", &n, &c), n||c){
      double fatia = 1.0/c;
      memset(pts, 0, sizeof pts);
      pts[0] = -1;
      
      while(n--){
		for(int i = 1; i <= 4; i++){
			double x, y;
			scanf("%lf%lf", &x, &y);
			double dist = hypot(x-1, y-1);
			int l = 1, r = c;
			while(l < r){
				int m = (l+r)/2;
				if(m*fatia >= dist)
					r = m;
				else
					l = m+1;
			}
			
			pts[i] += c-l+1;
		}
	}
      
#if 0
      for(int i = 1; i <= 4; i++) cout << pts[i]<< " ";
      cout << endl;
#endif
      
      vector<int> jog;
      jog.push_back(0);
      for(int i = 1; i <= 4; i++){
	if(pts[i] > pts[jog[0]]){
	  jog.clear();
	  jog.push_back(i);
	}else if(pts[i] == pts[jog[0]]){
	  jog.push_back(i);
	}
      }
      
      if(jog.size() == 1){
	printf("Jogador %d ganhou\n", jog[0]);
      }else{
	printf("Jogadores");
	for(int i = 0; i < jog.size(); i++) printf(" %d", jog[i]);
	printf(" empataram\n");
      }
    }
}
#include <bits/stdc++.h>

using namespace std;

int uf[100001];
int range[100001];
vector<int> vet;

void init(int n){
	for(int i=0; i<n; i++){
		uf[i]=i;
		range[i]=0;
	}
}

void merge(int x,int y){
	 //cout << x << " - " << y << endl;
	 //cout << vet[x] << " " << vet[y] << endl;
	range[x] = range[uf[x]]+range[uf[y]]+(vet[x] - vet[y]); 
	for(int i=y; i>=0 && uf[i] == y; i--) uf[i] = uf[x];
}

int main(){
	int n,k,t;
	scanf("%d",&t);
	set<int> s;
	for(int w=0; w<t; w++){
		vet.clear();
		s.clear();
		scanf("%d%d",&n,&k);
		for(int i=0; i<n; i++){
			int k;
			scanf("%d",&k);
			s.insert(k);
			// cout << vet[i] << endl;
		}
		for(int it : s){
			vet.push_back(it);
		}
		n = vet.size();
		init(n);
		int g = n;
		while(g>k){
			int aux=0x3f3f3f3f;
			int melhor = 0;
			int i;
			for(i=0; i<n && uf[0] == uf[i]; i++); 
			for(; i<n; i++){
				if(uf[i] != uf[i-1]){
					if(vet[i] - vet[i-1] < aux){
						aux = vet[i] - vet[i-1];
						melhor = i;
					}
				}
			}
			merge(melhor,melhor-1);
			g--;
		}
		int sum = 0;
		for(int i=1; i<n; i++){
			if(i == 1 || uf[i] != uf[i-1]) {
				sum += range[uf[i]];
				// cout << range[i] << endl;
				// cout << "bla\n";
			}
			// cout << range[i] << endl;
		}
		printf("%d\n",sum);
	}
}
#include <bits/stdc++.h>

using namespace std;

int uf[100001];
int sz[100001];
vector<int> vet;

void init(int n){
	for(int i=0; i<n; i++){
		uf[i]=i;
		sz[i] = 1;
	}
}

int find(int x) {
	return (uf[x] == x ? x : uf[x] = find(uf[x]));
}

void merge(int x,int y){
	int ux = find(x);
	int uy = find(y);

	if(sz[ux] < sz[uy]) swap(ux, uy);

	uf[uy] = ux;
	sz[ux] += sz[uy];
}

int main(){
	int n,k,t;
	scanf("%d",&t);
	set<int> s;
	for(int w=0; w<t; w++){
		vector< int > unions;
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
		
		for(int i = 1; i < n; i++) {
			unions.push_back(vet[i] - vet[i-1]);
		}

		sort(unions.begin(), unions.end());
		int sum=0;
		for(int i = 0; i < n-k; i++) {
			sum += unions[i];
		}
		// for(int i = 0; i < k; i++) {
		// 	merge(unions[i].second, unions[i].second-1);
		// }

		// int sum = 0;
		// for(int i=0; i<n; i++){
		// 	if(i == 0 || uf[i] != uf[i-1]) {
		// 		if(i != 0) {
		// 			sum += vet[i-1] - vet[fi];
		// 		}
		// 		fi = i;
		// 	}
		// }
		printf("%d\n",sum);
	}
}
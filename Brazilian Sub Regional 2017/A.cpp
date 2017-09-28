#include <bits/stdc++.h>
#define ROOT 1
#define ff first
#define endl '\n'
#define ss second
using namespace std;

struct node {
	int freq[9];
	int lazy = 0;
	int best = 0;
	node(){}
};

node tree[4*112345];

node combine(node a, node b){
	node ans;
	for(int i=0; i<9; i++){
		ans.freq[i] = a.freq[i] + b.freq[i];
	}
	pair<int, int> best(0,0);
	for(int i=0; i<9; i++){
		if(best.ff <= ans.freq[i]){
			best.ff = ans.freq[i];
			best.ss = i;
		}
	}
	ans.best = best.ss;
	return ans;
}

//
void build(int root, int l, int r){
	if(l == r){
		for(int i=0; i<9; i++) tree[root].freq[i] = 0;
		tree[root].freq[1] = 1;
		tree[root].best = 1;
		tree[root].lazy = 0;
		return;
	}
	int m = (l+r) >> 1;
	build(2*root, l, m);
	build(2*root+1, m+1, r);
	tree[root] = combine(tree[2*root], tree[2*root+1]);
}

//


void propagate(int root, int l, int r){
	if(tree[root].lazy == 0) return;
	int vet[9];
	for(int i=0; i<9; i++){
		vet[(i+tree[root].lazy)%9] = tree[root].freq[i];
	}
	for(int i=0; i<9; i++){
		tree[root].freq[i] = vet[i];
	}
	pair<int, int> best(0,0);
	for(int i=0; i<9; i++){
		if(best.ff <= tree[root].freq[i]){
			best.ff = tree[root].freq[i];
			best.ss = i;
		}
	}
	tree[root].best = best.ss;
	if(l != r){
		tree[2*root].lazy += tree[root].lazy;
		tree[2*root+1].lazy += tree[root].lazy;
	}
	tree[root].lazy = 0;
}

node query1(int root, int l, int r, int a, int b){
	propagate(root, l, r);
	if(l == a && r == b){
		return tree[root];
	}
	int m = (l+r) >> 1;
	if(b <= m) return query1(2*root, l, m, a, b);
	else if(m < a) return query1(2*root+1, m+1, r, a, b);
	else {
		node left = query1(2*root, l, m, a, m);
		node right = query1(2*root+1, m+1, r, m+1, b);
		node ans = combine(left, right);
		return ans;
	}
}

node query2(int root, int l, int r, int x){
	propagate(root, l, r);
	if(l == x && r == x){
		return tree[root];
	}
	int m = (l+r) >> 1;
	if(x <= m) return query2(2*root, l, m, x);
	else return query2(2*root+1, m+1, r, x);
}
	
void range_update(int root, int l, int r, int a, int b, int val){
	if(l == a && r == b){
		tree[root].lazy += val;
		//cout << "lazy " << a << " " << b << " = " << tree[root].lazy << endl;
		return;
	}
	int m = (l+r) >> 1;
	if(b <= m) range_update(2*root, l,m, a,b, val);
	else if(m < a) range_update(2*root+1, m+1, r, a, b, val);
	else {
		range_update(2*root, l, m, a, m, val);
		range_update(2*root+1, m+1, r, m+1, b, val);
	}
	propagate(root, l, r);
	propagate(2*root, l, m);
	propagate(2*root+1, m+1, r);
	tree[root] = combine(tree[2*root], tree[2*root+1]);
}

int main(){
	int n, q;
	scanf("%d %d", &n, &q);
	build(ROOT, 0, n-1);
	//for(int i=0; i<n; i++) cout << query2(ROOT, 0, n-1, i).best << endl;
	while(q--){
		int a, b;
		scanf("%d %d", &a, &b);
		node melhor = query1(ROOT, 0, n-1, a, b);
		//cout << "node frequencies" << endl;
		//for(int i=0; i<9; i++) cout << melhor.freq[i] << " ";
		//cout << endl;
		range_update(ROOT, 0, n-1, a, b, melhor.best);
		//for(int i=0; i<n; i++) cout << query2(ROOT, 0, n-1, i).best << endl;
	}
	for(int i=0; i<n; i++) printf("%d\n", query2(ROOT, 0, n-1, i).best);
}

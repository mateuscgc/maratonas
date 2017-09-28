#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
	int n;
	cin >> n;

	string notas[12] = {"do", "do#", "re", "re#", "mi", "fa" , "fa#", "sol" , "sol#", "la", "la#", "si"};

	set<int> mus;
	for(int i = 0; i<n; i++) {
		int num;
		cin >> num;
		num--;
		mus.insert(num%12);
	}
	vector<int> ve;
	for(int x : mus) ve.push_back(x);

	int jump[12] = {1,0,1,0,1,1,0,1,0,1,0,1};


	for(int i = 0; i < 12; i++) {
		bool flag = true;
		//cout << "i = " << i << endl;	
		for(int j = 0; j < ve.size(); j++) {
			int ju = ve[j]-i;			
			if(ju < 0) ju += 12;
			//cout << ju << endl;
			if(!jump[ju]) flag = false;
		}
		if(flag) {
			cout << notas[i] << endl;
			return 0;
		}
	}
	cout << "desafinado" << endl;
}

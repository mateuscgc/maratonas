#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int cont = 0;
	for(int i=0; i<s.size(); i++){
		cont += s[i]-'0';
	}
	cout << cont%3 << endl;
}

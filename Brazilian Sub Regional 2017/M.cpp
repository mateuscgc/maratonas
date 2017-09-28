#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a, b, c;
	cin >> a >> b >> c;
	cout << min({c*4+b*2, a*2+c*2, a*4+b*2}) << endl;
}


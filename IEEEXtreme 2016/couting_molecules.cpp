#include <bits/stdc++.h>

using namespace std;

int main(){
	long long c,h,o;
	cin >> c >> h >> o;
	
	long long maxcarb, maxagua, maxglic;
	maxcarb = (o - h/2)/2;
	maxglic = (c - maxcarb)/6;
	maxagua = h/2 - 6*maxglic;
	
	//cout << c << endl;
	c-= (maxcarb + 6*maxglic);
	//cout << c << endl;
	//cout << h << endl;
	h-= (12*maxglic + 2*maxagua);
	//cout << h << endl;
	//cout << o << endl;
	o-= (2*maxcarb + 6*maxglic + maxagua);
	//cout << o << endl;
	if(o || c || h) cout << "Error" << endl;
	else cout << maxagua << " " << maxcarb << " " << maxglic << endl;
}  